import requests
from bs4 import BeautifulSoup
import os
import time

HANDLE = "sajib2405129"
API_URL = f"https://codeforces.com/api/user.status?handle={HANDLE}"

def get_extension(lang):
    if 'C++' in lang: return 'cpp'
    if 'Java' in lang: return 'java'
    if 'Python' in lang: return 'py'
    if 'C' in lang: return 'c'
    return 'txt'

def sync_codeforces():
    print(f"Fetching submissions for {HANDLE}...")
    response = requests.get(API_URL).json()
    
    if response['status'] != 'OK':
        print("Failed to fetch API")
        return

    submissions = response['result']
    added = 0

    for sub in submissions:
        # শুধু Accepted (OK) সল্যুশনগুলো নিবো
        if sub.get('verdict') == 'OK':
            contest_id = str(sub['problem']['contestId'])
            index = sub['problem']['index']
            sub_id = str(sub['id'])
            lang = sub['programmingLanguage']
            ext = get_extension(lang)

            folder_name = contest_id
            file_name = f"{index}.{ext}"
            path = os.path.join(folder_name, file_name)

            # যদি কোডটা আগে থেকেই ফোল্ডারে থাকে, তবে স্কিপ করবো (যাতে গিটহাব/CF ব্লক না করে)
            if os.path.exists(path):
                continue 

            print(f"Downloading Contest: {contest_id}, Problem: {index} (Sub: {sub_id})...")
            os.makedirs(folder_name, exist_ok=True)

            url = f"https://codeforces.com/contest/{contest_id}/submission/{sub_id}"
            try:
                # Cloudflare ব্লক এড়াতে ইউজার-এজেন্ট সেট করা
                headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'}
                page = requests.get(url, headers=headers)
                soup = BeautifulSoup(page.text, 'html.parser')
                code_block = soup.find('pre', id='program-source-text')

                if code_block:
                    with open(path, 'w', encoding='utf-8') as f:
                        f.write(code_block.text)
                    added += 1
                    time.sleep(1) # CF সার্ভারকে রিকোয়েস্ট দিয়ে স্প্যাম না করার জন্য ১ সেকেন্ড ব্রেক
                else:
                    print(f"Could not find code for {sub_id}. Maybe restricted.")
            except Exception as e:
                print(f"Error fetching {sub_id}: {e}")

    print(f"Sync complete. {added} new solutions added.")

if __name__ == "__main__":
    sync_codeforces()
