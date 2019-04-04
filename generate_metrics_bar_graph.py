import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


# Returns weighted precision and recall from classification report file
def get_report_precision_recall(filename):
    repo_df = pd.read_csv(filename)
    total = sum(repo_df["support"])
    repo_df["weighted_precision"] = repo_df["precision"] * repo_df["support"] / total
    repo_df["weighted_recall"] = repo_df["recall"] * repo_df["support"] / total
    repo_precision = repo_df["weighted_precision"].sum()
    repo_recall = repo_df["weighted_recall"].sum()

    return repo_precision, repo_recall

# Returns list of all overall precision and recall from sessions listed in the file
def get_session_metrics(filepath, experiment):
    
    with open(filepath, 'rb') as readfile:
        session_df = pd.read_csv(readfile)

    sessions = list(session_df["session"])


    report_paths = list(session_df[experiment+"_filepath"])

    precisions = []
    recalls = []
    for path in report_paths:
        precision, recall = get_report_precision_recall(path)
        precisions.append(precision)
        recalls.append(recall)

    return sessions, precisions, recalls

# Plots a bar graph of the session names, list of precision, and list of recall
def plot_precision_recall_bar_graph(session_names, session_precisions, session_recalls, experiment):
    index = np.arange(len(session_names))
    bar_width = 0.35

    # Red and blue
    colors = ["#A02C2D", "#5E96AE"]

    # plot bar graph
    fig, ax = plt.subplots()
    ax.grid(axis="y")
    ax.set_axisbelow(True)
   
    precision_rects = ax.bar(
        index, session_precisions, bar_width,
        color=colors[0], label="Precision"
    )
    recall_rects = ax.bar(
        index + bar_width, session_recalls, bar_width,
        color=colors[1], label="Recall"
    )
    ax.set_xlabel("Repo")
    ax.set_ylabel("Precision/Recall Score")
    ax.set_title(experiment+" Classification Metric by Repository")
    ax.set_xticks(index + bar_width / 2)
    ax.set_xticklabels(range(1, len(session_names)+1))
    ax.legend(loc="lower right")
    ax.tick_params(labelbottom=False)
    plt.show()
    plt.savefig("all_binary_prec_recall.png")

import csv
def write_prec_recall(session_names, session_precisions, session_recalls):
    
    with open("all_prec_recall.csv", 'w') as writeFile:
        writer = csv.writer(writeFile)
        it = 0
        for name in session_names:
            writer.writerow([[session_names[it]], [session_precisions[it]], [session_recalls[it]]])
	    it+=1


if __name__ == "__main__":
    if (len(sys.argv) < 2):
        sample_file = "bar_graph_sessions.csv"
        print("You must pass in a sessions list file. e.g. python {} {}".format(sys.argv[0], sample_file))
        exit(1)

    session_file = sys.argv[1]

    for experiment in ["binary", "multi", "single_model_multi"]:
        session_names, precisions, recalls = get_session_metrics(session_file, experiment)
        plot_precision_recall_bar_graph(session_names, precisions, recalls, experiment)
        write_prec_recall(session_names, precisions, recalls, experiment)

