import requests
import os
import time
import glob
import shutil
import re
from bs4 import BeautifulSoup

HANDLE = "sajib2405129"

API_URL = f"https://codeforces.com/api/user.status?handle={HANDLE}"
MAIN_FOLDER = "CODEFORCES"

HEADERS = {
    "User-Agent": "Mozilla/5.0"
}


def clean_root_files():
    """
    Move old source files from repository root
    into CODEFORCES folder.
    """
    extensions = [
        "*.cpp",
        "*.c",
        "*.txt",
        "*.java",
        "*.py",
        "*.cs",
        "*.kt",
        "*.rs",
        "*.go",
        "*.js"
    ]

    os.makedirs(MAIN_FOLDER, exist_ok=True)

    for ext in extensions:
        for file_path in glob.glob(ext):

            if file_path in ["sync.py", "README.md"]:
                continue

            try:
                destination = os.path.join(
                    MAIN_FOLDER,
                    os.path.basename(file_path)
                )

                shutil.move(file_path, destination)

                print(f"Moved {file_path} -> {destination}")

            except Exception as e:
                print(f"Error moving {file_path}: {e}")


def get_extension(language):
    """
    Convert Codeforces language name to file extension.
    """

    lang = language.lower()

    if "c++" in lang or "gnu c++" in lang:
        return "cpp"

    if "c#" in lang or "csharp" in lang:
        return "cs"

    if "java" in lang:
        return "java"

    if "python" in lang:
        return "py"

    if lang == "c" or lang.startswith("c "):
        return "c"

    if "kotlin" in lang:
        return "kt"

    if "rust" in lang:
        return "rs"

    if "go" in lang:
        return "go"

    if "javascript" in lang:
        return "js"

    if "typescript" in lang:
        return "ts"

    return "txt"


def sanitize_name(name):
    """
    Remove characters that are invalid in folder names.
    """
    return re.sub(r'[\\/*?:"<>|]', "", name).strip()


def fetch_source_code(contest_id, submission_id):
    """
    Fetch actual submitted source code from
    Codeforces submission page.
    """

    url = (
        f"https://codeforces.com/contest/"
        f"{contest_id}/submission/{submission_id}"
    )

    try:
        response = requests.get(
            url,
            headers=HEADERS,
            timeout=20
        )

        if response.status_code != 200:
            print(
                f"Failed to fetch submission "
                f"{submission_id}: HTTP {response.status_code}"
            )
            return None

        soup = BeautifulSoup(
            response.text,
            "html.parser"
        )

        source = soup.find(
            "pre",
            id="program-source-text"
        )

        if source is None:
            source = soup.find(
                "pre",
                class_="source"
            )

        if source is None:
            print(
                f"Source code not found for "
                f"submission {submission_id}"
            )
            return None

        return source.get_text()

    except Exception as e:
        print(
            f"Error fetching submission "
            f"{submission_id}: {e}"
        )
        return None


def create_readme(
    readme_path,
    contest_id,
    index,
    problem_name,
    submission_id,
    language,
    verdict
):
    """
    Create README containing problem and submission links.
    """

    problem_url = (
        f"https://codeforces.com/contest/"
        f"{contest_id}/problem/{index}"
    )

    submission_url = (
        f"https://codeforces.com/contest/"
        f"{contest_id}/submission/{submission_id}"
    )

    with open(
        readme_path,
        "w",
        encoding="utf-8"
    ) as f:

        f.write(
            f"# {contest_id}{index} - {problem_name}\n\n"
        )

        f.write(
            f"**Verdict:** {verdict}\n\n"
        )

        f.write(
            f"**Language:** {language}\n\n"
        )

        f.write(
            f"**Submission ID:** {submission_id}\n\n"
        )

        f.write(
            f"**Problem:** "
            f"[View Problem]({problem_url})\n\n"
        )

        f.write(
            f"**Submission:** "
            f"[View Submission]({submission_url})\n"
        )


def sync_codeforces():

    print("=" * 50)
    print("          CODEFORCES AUTO SYNC")
    print("=" * 50)

    print("\nCleaning root files...")
    clean_root_files()

    print(
        f"\nFetching submissions for {HANDLE}..."
    )

    try:
        response = requests.get(
            API_URL,
            headers=HEADERS,
            timeout=20
        )

        response.raise_for_status()

        data = response.json()

    except Exception as e:
        print(
            f"Failed to fetch Codeforces API: {e}"
        )
        return

    if data.get("status") != "OK":

        print("Codeforces API returned an error:")
        print(data)

        return

    submissions = data.get("result", [])

    print(
        f"Found {len(submissions)} submissions."
    )

    added = 0
    skipped = 0
    failed = 0

    for sub in submissions:

        # Only Accepted submissions
        if sub.get("verdict") != "OK":
            continue

        try:
            contest_id = str(
                sub["problem"]["contestId"]
            )

            index = sub["problem"]["index"]

            problem_name = sub["problem"]["name"]

            submission_id = str(sub["id"])

            language = sub.get(
                "programmingLanguage",
                "Unknown"
            )

            extension = get_extension(language)

            safe_name = sanitize_name(problem_name)

            # ---------------------------------------
            # One folder per problem
            # ---------------------------------------

            problem_folder = os.path.join(
                MAIN_FOLDER,
                f"{contest_id}{index} - {safe_name}"
            )

            os.makedirs(
                problem_folder,
                exist_ok=True
            )

            # ---------------------------------------
            # One file per accepted submission
            # ---------------------------------------

            code_path = os.path.join(
                problem_folder,
                f"submission-{submission_id}.{extension}"
            )

            readme_path = os.path.join(
                problem_folder,
                f"submission-{submission_id}.md"
            )

            # Already archived
            if os.path.exists(code_path):

                print(
                    f"Already archived: "
                    f"{contest_id}{index} "
                    f"(Submission {submission_id})"
                )

                skipped += 1
                continue

            print(
                f"\nArchiving {contest_id}{index} "
                f"- {problem_name}"
            )

            print(
                f"Submission: {submission_id}"
            )

            print(
                f"Language: {language}"
            )

            # ---------------------------------------
            # Fetch actual source code
            # ---------------------------------------

            source_code = fetch_source_code(
                contest_id,
                submission_id
            )

            if source_code is None:

                print(
                    f"FAILED: Could not fetch source "
                    f"for {submission_id}"
                )

                failed += 1
                continue

            # ---------------------------------------
            # Save source code
            # ---------------------------------------

            with open(
                code_path,
                "w",
                encoding="utf-8"
            ) as f:

                f.write(source_code)

            print(
                f"Saved: {code_path}"
            )

            # ---------------------------------------
            # Save submission README
            # ---------------------------------------

            create_readme(
                readme_path,
                contest_id,
                index,
                problem_name,
                submission_id,
                language,
                sub.get("verdict", "OK")
            )

            print(
                f"Saved: {readme_path}"
            )

            added += 1

            # Don't hammer Codeforces
            time.sleep(1)

        except Exception as e:

            print(
                f"Error processing submission "
                f"{sub.get('id', 'UNKNOWN')}: {e}"
            )

            failed += 1

    print("\n" + "=" * 50)
    print("             SYNC COMPLETE")
    print("=" * 50)

    print(f"New archived    : {added}")
    print(f"Already archived: {skipped}")
    print(f"Failed          : {failed}")

    print(
        f"\nArchive location: {MAIN_FOLDER}/"
    )


if __name__ == "__main__":
    sync_codeforces()