import requests
import os
import time
import glob
import shutil
import re

HANDLE = "sajib2405129"
# API URL for fetching submissions
API_URL = f"https://codeforces.com/api/user.status?handle={HANDLE}"
MAIN_FOLDER = "CODEFORCES"

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

            safe_name = re.sub(r'[\\/*?:"<>|]', "", problem_name)
            folder_name = os.path.join(MAIN_FOLDER, f"{contest_id}{index} - {safe_name}")
            
            code_path = os.path.join(folder_name, f"solution.{ext}")
            readme_path = os.path.join(folder_name, "README.md")

            if os.path.exists(code_path) and os.path.exists(readme_path):
                continue 

            print(f"Downloading {contest_id}{index} - {problem_name} (Sub: {sub_id})...")
            os.makedirs(folder_name, exist_ok=True)

            code_api_url = f"https://codeforces.com/api/contest.status?contestId={contest_id}&from=1&count=1&handle={HANDLE}"
            
            try:
                problem_url = f"https://codeforces.com/contest/{contest_id}/problem/{index}"
                with open(readme_path, 'w', encoding='utf-8') as f:
                    f.write(f"<h1><a href='{problem_url}'>{contest_id}{index} - {problem_name}</a></h1>\n\n")
                    f.write(f"<p>This is the solution for the problem <b>{problem_name}</b> on Codeforces.</p>")
                    f.write(f"<p><a href='{problem_url}' target='_blank'>Click here to view the problem statement on Codeforces.</a></p>")

                possible_old_files = [
                    os.path.join(MAIN_FOLDER, f"{contest_id}{index}.{ext}"),
                    os.path.join(MAIN_FOLDER, f"{contest_id}{index}{safe_name}.{ext}"),
                    os.path.join(MAIN_FOLDER, f"{contest_id}{index}_{safe_name}.{ext}")
                ]
                
                code_found = False
                
                
                for root, dirs, files in os.walk(MAIN_FOLDER):
                    if root == MAIN_FOLDER:
                        for file in files:
                            
                            if file.startswith(f"{contest_id}{index}") and file.endswith(f".{ext}"):
                                old_file_path = os.path.join(MAIN_FOLDER, file)
                                shutil.move(old_file_path, code_path) 
                                print(f"Moved existing code: {file} -> {folder_name}/solution.{ext}")
                                code_found = True
                                break
                    if code_found: break

                if not code_found:
                     with open(code_path, 'w', encoding='utf-8') as f:
                        f.write(f"// Solution for {contest_id}{index} - {problem_name}\n")
                        f.write(f"// Submitted at: https://codeforces.com/contest/{contest_id}/submission/{sub_id}\n")
                        f.write(f"// Currently manual fetch required due to CF blocking scrapers.\n")
                     print(f"Created placeholder code for {sub_id}.")

                added += 1
                time.sleep(0.5)
                
            except Exception as e:
                print(f"Error processing {sub_id}: {e}")

    print(f"Sync complete. {added} new solutions organized in LeetCode style.")

if __name__ == "__main__":
    sync_codeforces()
