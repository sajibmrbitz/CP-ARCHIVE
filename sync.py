import requests
from bs4 import BeautifulSoup
import os
import time
import glob
import shutil
import re

HANDLE = "sajib2405129"
API_URL = f"https://codeforces.com/api/user.status?handle={HANDLE}"
MAIN_FOLDER = "ACCEPTEDS"

def clean_root_files():
    # Root-e choriye thaka shob puran .cpp, .c, .txt file automatic ACCEPTEDS-e niye jabe
    extensions = ['*.cpp', '*.c', '*.txt']
    for ext in extensions:
        for file_path in glob.glob(ext):
            if file_path in ['sync.py', 'README.md']:
                continue
            os.makedirs(MAIN_FOLDER, exist_ok=True)
            try:
                shutil.move(file_path, os.path.join(MAIN_FOLDER, file_path))
                print(f"Moved {file_path} to {MAIN_FOLDER}/")
            except Exception as e:
                print(f"Error moving {file_path}: {e}")

def get_extension(lang):
    if 'C++' in lang: return 'cpp'
    if 'Java' in lang: return 'java'
    if 'Python' in lang: return 'py'
    if 'C' in lang: return 'c'
    return 'txt'

def fetch_problem_statement(contest_id, index):
    url = f"https://codeforces.com/contest/{contest_id}/problem/{index}"
    try:
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'}
        page = requests.get(url, headers=headers)
        soup = BeautifulSoup(page.text, 'html.parser')
        # Codeforces এর প্রবলেম ডেসক্রিপশনের মেইন ডিভটা খুঁজে বের করা
        statement = soup.find('div', class_='problem-statement')
        if statement:
            return str(statement)
        return "<p>Problem statement could not be fetched.</p>"
    except Exception as e:
        return f"<p>Error fetching statement: {e}</p>"

def sync_codeforces():
    print("Cleaning root files...")
    clean_root_files()
    
    print(f"Fetching submissions for {HANDLE}...")
    response = requests.get(API_URL).json()
    
    if response['status'] != 'OK':
        print("Failed to fetch API")
        return

    submissions = response['result']
    added = 0

    for sub in submissions:
        if sub.get('verdict') == 'OK':
            contest_id = str(sub['problem']['contestId'])
            index = sub['problem']['index']
            problem_name = sub['problem']['name']
            sub_id = str(sub['id'])
            lang = sub['programmingLanguage']
            ext = get_extension(lang)

            # ফোল্ডারের নাম সুন্দর করার জন্য স্পেশাল ক্যারেক্টার বাদ দেওয়া (যাতে উইন্ডোজ বা গিটহাবে এরর না দেয়)
            safe_name = re.sub(r'[\\/*?:"<>|]', "", problem_name)
            folder_name = os.path.join(MAIN_FOLDER, f"{contest_id}{index} - {safe_name}")
            
            code_path = os.path.join(folder_name, f"solution.{ext}")
            readme_path = os.path.join(folder_name, "README.md")

            # যদি ফোল্ডারে কোড আর README দুইটাই থাকে, তাহলে স্কিপ করবে
            if os.path.exists(code_path) and os.path.exists(readme_path):
                continue 

            print(f"Downloading {contest_id}{index} - {problem_name} (Sub: {sub_id})...")
            os.makedirs(folder_name, exist_ok=True)

            code_url = f"https://codeforces.com/contest/{contest_id}/submission/{sub_id}"
            try:
                headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'}
                page = requests.get(code_url, headers=headers)
                soup = BeautifulSoup(page.text, 'html.parser')
                code_block = soup.find('pre', id='program-source-text')

                if code_block:
                    # ১. সল্যুশন কোড সেভ করা
                    with open(code_path, 'w', encoding='utf-8') as f:
                        f.write(code_block.text)
                    
                    # ২. প্রবলেম স্টেটমেন্ট (README) সেভ করা
                    statement_html = fetch_problem_statement(contest_id, index)
                    problem_url = f"https://codeforces.com/contest/{contest_id}/problem/{index}"
                    
                    # README ফাইলে টাইটেল, লিংক এবং প্রবলেম ডেসক্রিপশন লেখা
                    with open(readme_path, 'w', encoding='utf-8') as f:
                        f.write(f"<h1><a href='{problem_url}'>{contest_id}{index} - {problem_name}</a></h1>\n\n")
                        f.write(statement_html)
                        
                    added += 1
                    time.sleep(1) # CF সার্ভারকে স্প্যাম না করার জন্য ১ সেকেন্ড ব্রেক
                else:
                    print(f"Could not find code for {sub_id}.")
            except Exception as e:
                print(f"Error fetching {sub_id}: {e}")

    print(f"Sync complete. {added} new solutions added in LeetCode style.")

if __name__ == "__main__":
    sync_codeforces()
