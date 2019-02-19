import subprocess
import os


# deltaspike and tapiji have very few commits labelled correctly
test_repo_dir = "gitRepos"
test_repos = [
    ("https://github.com/GNOME/valadoc.git", "valadoc"),
    ("https://github.com/GNOME/vala.git", "vala"),
    ("https://github.com/tapiji/tapiji.git", "tapiji"),
    ("https://git-wip-us.apache.org/repos/asf/deltaspike.git", "deltaspike"),
]

def check_missing_repos():
    missing_repos = []
    for git_url, repo in test_repos:
        if (not os.path.isdir("{}/{}".format(test_repo_dir, repo))):
            missing_repos.append((git_url, repo))
    return missing_repos


def query_yes_no(question, yes_answer="Y", no_answer="n"):
    prompt = "[{}/{}]".format(yes_answer, no_answer)
    print("{} {}".format(question, prompt))

    choice = input()
    return choice == yes_answer


def clone_test_repos():
    test_repos = check_missing_repos()
    if (len(test_repos) == 0):
        print("All test repos already cloned")
        return True

    question = "The following git repos need to be cloned to the \'gitRepos\' directory test the heuristic:\n"
    for git_url, _ in test_repos:
        question += "{}\n".format(git_url)
    question += "Would you like to clone them now?"

    can_clone_repos = query_yes_no(question)
    if (not can_clone_repos):
        return False

    for git_url, repo in test_repos:
        repo_path = "{}/{}".format(test_repo_dir, repo)
        subprocess.run(["git", "clone", git_url, repo_path])

    return True

if __name__ == "__main__":
    clone_test_repos()
