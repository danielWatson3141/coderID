import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


# Returns weighted precision and recall from classification report file
def get_report_precision_recall(filename):
    repo_df = pd.read_csv(filename)
    repo_df["weighted_precision"] = repo_df["precision"] * repo_df["%"] / 100
    repo_df["weighted_recall"] = repo_df["recall"] * repo_df["%"] / 100
    repo_precision = repo_df["weighted_precision"].sum()
    repo_recall = repo_df["weighted_recall"].sum()

    return repo_precision, repo_recall

# Returns list of all overall precision and recall from sessions listed in the file
def get_session_metrics(filepath):
    session_df = pd.read_csv("bar_graph_sessions.csv")

    sessions = list(session_df["session"])
    report_paths = list(session_df["report_filepath"])

    precisions = []
    recalls = []
    for path in report_paths:
        precision, recall = get_report_precision_recall(path)
        precisions.append(precision)
        recalls.append(recall)

    return sessions, precisions, recalls

# Plots a bar graph of the session names, list of precision, and list of recall
def plot_precision_recall_bar_graph(session_names, session_precisions, session_recalls):
    index = np.arange(len(session_names))
    bar_width = 0.35

    # Red and blue
    colors = ["#A02C2D", "#5E96AE"]

    # plot bar graph
    fig, ax = plt.subplots()
    precision_rects = ax.bar(
        index, session_precisions, bar_width,
        color=colors[0], label="Precision"
    )
    recall_rects = ax.bar(
        index + bar_width, session_recalls, bar_width,
        color=colors[1], label="Recall"
    )
    ax.set_xlabel("Session")
    ax.set_ylabel("Precision/Recall Score")
    ax.set_title("Classification Metric by Repository")
    ax.set_xticks(index + bar_width / 2)
    ax.set_xticklabels(session_names)
    ax.legend(loc="lower right")
    plt.show()


if __name__ == "__main__":
    session_names, precisions, recalls = get_session_metrics("bar_graph_sessions.csv")
    plot_precision_recall_bar_graph(session_names, precisions, recalls)
