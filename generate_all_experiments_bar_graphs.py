import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


colors = {
    "orange": "#e07510",
    "blue": "#82aedb",
    "purple": "#784AAF",
}


# Returns weighted f1 score from a multiclass report file
def get_multi_weighted_f1_score(filename):
    repo_df = pd.read_csv(filename, index_col=0)
    return repo_df.loc['weighted avg', 'f1-score']


# Returns weighted f1 score from a binary report file
def get_binary_weighted_f1_score(filename):
    repo_df = pd.read_csv(filename)
    repo_support = repo_df["support"].sum()

    repo_df["weighted_f1_score"] = repo_df["f1-score"] * repo_df["support"] / repo_support
    repo_weighted_f1_score = repo_df["weighted_f1_score"].sum()

    return repo_weighted_f1_score


# Returns lists of weighted f1-scores from sessions listed in the file
def get_session_f1_scores(filepath):

    # Read in sessions
    session_df = pd.read_csv(filepath)

    sessions = list(session_df["session"])
    binary_paths = list(session_df["binary_filepath"])
    multi_paths = list(session_df["multi_filepath"])
    single_model_multi_paths = list(session_df["single_model_multi_filepath"])

    # Extract weighted f1-scores
    session_multi_f1_score = [get_multi_weighted_f1_score(report_path) for report_path in multi_paths]
    session_single_model_multi_f1_score = [
        get_multi_weighted_f1_score(report_path) for report_path in single_model_multi_paths
    ]
    session_binary_f1_score = [get_binary_weighted_f1_score(report_path) for report_path in binary_paths]

    return sessions, session_multi_f1_score, session_single_model_multi_f1_score, session_binary_f1_score


# Plots a bar graph of the weighted f1-score for multi-class for all sessions
def plot_multiclass_f1_score(session_names, session_multi_f1_score, session_single_model_multi_f1_score):
    index = np.arange(len(session_names))
    bar_width = 0.35

    # Plot bar graph
    fig, ax = plt.subplots()
    multi_rects = ax.bar(
            index, session_multi_f1_score, bar_width,
            color=colors["orange"], label="One-vs-all multi"
    )
    single_model_rects = ax.bar(
            index + bar_width, session_single_model_multi_f1_score, bar_width,
            color=colors["blue"], label="Single model multi"
    )

    # Set labels
    ax.set_xlabel("Session")
    ax.set_ylabel("Weighted F1-Score")
    ax.set_title("Multi-class Weighted F1-score by Repository")
    ax.set_xticks(index + bar_width / 2)
    ax.set_xticklabels(session_names)
    ax.legend(loc="lower right")
    plt.show()


# Plots a bar graph of the weighted f1-score for one-vs-all binary classification for all sessions
def plot_binary_f1_score(session_names, session_binary_f1_score):
    index = np.arange(len(session_names))
    bar_width = 0.35

    # Plot bar graph
    fig, ax = plt.subplots()
    binary_rects = ax.bar(
            index, session_binary_f1_score, bar_width,
            color=colors["purple"]
    )

    # Set labels
    ax.set_xlabel("Session")
    ax.set_ylabel("Weighted F1-Score")
    ax.set_title("Binary Weighted F1-score by Repository")
    ax.set_xticks(index)
    ax.set_xticklabels(session_names)
    plt.show()


if __name__ == "__main__":
    if (len(sys.argv) < 2):
        sample_file = "f1_score_sample_sessions.csv"
        print("You must pass in a sessions list file. e.g. python {} {}".format(sys.argv[0], sample_file))
        exit(1)

    session_file = sys.argv[1]
    session_names, multi_f1_score, single_model_f1_score, binary_f1_score = get_session_f1_scores(session_file)
    plot_multiclass_f1_score(session_names, multi_f1_score, single_model_f1_score)
    plot_binary_f1_score(session_names, binary_f1_score)
