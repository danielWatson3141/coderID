import pydriller
import pandas as pd
from commitType import commitType
from loadRepos import clone_test_repos


def get_repo_commits(survey_df):
    repos = [
        ("gitRepos/valadoc", 1),
        ("gitRepos/vala", 2),
        ("gitRepos/tapiji", 4),
        ("gitRepos/deltaspike", 6)
    ]
    repo_commits = []
    for repo, project_id in repos:
        commit_list = survey_df[survey_df["project_id"] == project_id]["commit_hash"].tolist()
        repo_commits.append((repo, commit_list))
    return repo_commits


def classify_test_commits(repo_commits):
    classifications = []
    for repo, commits in repo_commits:
        miner = pydriller.repository_mining.RepositoryMining(
            repo,
            only_no_merge=True,
            only_commits=commits
        )
        #repository = pydriller.GitRepository(repo)
        print("Scanning repo: " + miner._path_to_repo)
        commits = list(miner.traverse_commits())    #traverse commits is a generator
                                                    #so calling this fun more than once is inefficient
        print("num Commits: {}".format(len(commits)))

        for commit in commits:
            commitLabel = commitType.categorize(commit)
            classifications.append((commit.hash, commitLabel.value))

    print("Total classified commits: {}".format(len(classifications)))

    classification_dict = {
        'FC': 'hl_forward',
        'BF': 'hl_corrective',
        'RF': 'hl_reengineering',
        'OTH': 'hl_management',
    }
    labelled_df = pd.DataFrame(classifications, columns=['commit_hash', 'label'])

    return labelled_df


def get_labelled_examples():
    # load dataset
    commit_df = pd.read_csv(
        "labelledCommitDataset/Commits.csv",
        names=["commit_id", "commit_hash", "project_id", "author_id", "committer_id", "date", "title"]
    )
    survey_df = pd.read_csv(
        "labelledCommitDataset/SurveyResults.csv",
        names= [
            "commit_id",
            "sw_adaptive",
            "sw_corrective",
            "sw_perfective",
            "nfr_maintainability",
            "nfr_usability",
            "nfr_functionality",
            "nfr_reliability",
            "nfr_efficiency",
            "nfr_portability",
            "nfr_none",
            "hl_forward",
            "hl_reengineering",
            "hl_corrective",
            "hl_management",
        ]
    )
    survey_df["commit_hash"] = commit_df["commit_hash"]
    survey_df["project_id"] = commit_df["project_id"]
    return survey_df


def test_classifications(survey_df, labelled_df):
    classified_df = pd.merge(survey_df, labelled_df, on=['commit_hash'])
    print("Num classified examples: {}". format(len(classified_df.index)))

    # Get number of matches
    num_forward = len(classified_df[
        (classified_df['hl_forward'] == 1) &
        (classified_df['label'] == 'FC')]
    )
    num_bugfix = len(classified_df[
        (classified_df['hl_forward'] == 0) &
        (classified_df['hl_corrective'] == 1) &
        (classified_df['label'] == 'BF')]
    )
    num_refactor = len(classified_df[
        (classified_df['hl_forward'] == 0) &
        (classified_df['hl_corrective'] == 0) &
        ((classified_df['hl_reengineering'] == 1) |
            (classified_df['hl_management'] == 1)) &
        (classified_df['label'] == 'RF')]
    )
    num_other = len(classified_df[
        (classified_df['hl_forward'] == 0) &
        (classified_df['hl_corrective'] == 0) &
        (classified_df['hl_reengineering'] == 0) &
        (classified_df['hl_management'] == 0) &
        (classified_df['label'] == 'OTH')]
    )
    print("num_forward: {}".format(num_forward))
    print("num_bugfix: {}".format(num_bugfix))
    print("num_refactor: {}".format(num_refactor))
    print("num_other: {}".format(num_other))

    total_correct = num_forward + num_bugfix + num_refactor + num_other
    total_rows = len(classified_df.index)
    print("accuracy: {}".format(total_correct / total_rows))


def test_heuristic_function():
    if (not clone_test_repos()):
        return
    survey_df = get_labelled_examples()
    repo_commits = get_repo_commits(survey_df)
    labelled_df = classify_test_commits(repo_commits)
    test_classifications(survey_df, labelled_df)

if __name__ == "__main__":
    test_heuristic_function()
