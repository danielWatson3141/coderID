import numpy as np
import matplotlib.pyplot as plt
from scipy import interp
from sklearn.metrics import auc, roc_curve

# Generates distinct colours given a number. Returns black if the index is too high
def get_color(index):
    colors = [
        'red', 'blue', 'green', 'purple', 'cyan', 'lime', 'indigo', 'crimson',
        'dodgerblue', 'deepskyblue', 'coral', 'saddlebrown', 'orange', 'olive'
    ]
    if (index < len(colors)):
        return colors[index]
    return 'black'

def get_avg_roc_auc(results):
    # aggregate all fpr for all authors
    all_fpr = np.unique(np.concatenate([result["fpr"] for _, result in results.items()]))

    # Interpolate all ROC curves at these points
    mean_tpr = np.zeros_like(all_fpr)
    weighted_mean_tpr = np.zeros_like(all_fpr)

    samples = 0
    targets = []
    predictions = []
    # compute total number of samples
    for author, metrics in results.items():
        samples += metrics[author]["support"]

    for author, metrics in results.items():
        mean_tpr += interp(all_fpr, metrics["fpr"], metrics["tpr"])
        weighted_mean_tpr += interp(all_fpr, metrics["fpr"], metrics["tpr"]) * metrics[author]["support"] / samples

        targets.extend(metrics["targets"])
        predictions.extend(metrics["predictions"])

    # Average out results
    mean_tpr /= len(results)

    # Compute micro-average ROC
    micro_fpr, micro_tpr, _ = roc_curve(targets, predictions)

    averages = {
        "unweighted": {
            "fpr": all_fpr,
            "tpr": mean_tpr,
            "AUC": auc(all_fpr, mean_tpr),
        },
        "weighted": {
            "fpr": all_fpr,
            "tpr": weighted_mean_tpr,
            "AUC": auc(all_fpr, weighted_mean_tpr),
        },
        "micro": {
            "fpr" : micro_fpr,
            "tpr": micro_tpr,
            "AUC": auc(micro_fpr, micro_tpr),
        },
    }
    return averages


def plot_author_roc_auc_curve(author, fpr, tpr, roc_auc, color='darkorange', directory="plots", session_name=""):
    plt.figure()
    lw = 2
    plt.plot(
        fpr, tpr, color=color, lw=lw,
        label='ROC curve (area = %0.4f)' % roc_auc
    )
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.0])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('ROC Curve for {}'.format(author))
    plt.legend(loc="lower right")

    plot_filepath = "{}/{}_{}_ROC.png".format(directory, session_name, author)
    plt.savefig(plot_filepath)


def plot_average_roc_auc_curve(roc_averages):
    lw = 2
    # Plot macro average ROC
    plt.plot(
        roc_averages["unweighted"]["fpr"], roc_averages["unweighted"]["tpr"], color="deeppink", lw=lw,
        label="macro average ROC curve (area = {%0.4f})".format(roc_averages["unweighted"]["AUC"]),
        linestyle=":",
    )
    # Plot weighted average ROC
    plt.plot(
        roc_averages["weighted"]["fpr"], roc_averages["weighted"]["tpr"], color="teal", lw=lw,
        label="weighted average ROC curve (area = {%0.4f})".format(roc_averages["weighted"]["AUC"]),
        linestyle=":",
    )
    ## Plot micro average ROC
    plt.plot(
        roc_averages["micro"]["fpr"], roc_averages["micro"]["tpr"], color="green", lw=lw,
        label="micro average ROC curve (area = {%0.4f})".format(roc_averages["micro"]["AUC"]),
        linestyle=":",
    )


def plot_roc_auc_curves(results, directory="plots", session_name=""):
    lw = 2
    # Plot individual author ROC curves
    for i, (author, metrics) in enumerate(results.items()):
        plot_author_roc_auc_curve(
            author, metrics["fpr"], metrics["tpr"], metrics[author]["AUC"], get_color(i),
            directory=directory, session_name=session_name
        )

    roc_averages = get_avg_roc_auc(results)

    # Plot average ROC curves
    plt.figure()
    plot_average_roc_auc_curve(roc_averages)
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.0])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('All ROC Curves for {}'.format(session_name))
    plt.legend(loc="lower right")

    average_plot_filepath = "{}/{}_Average_ROC.png".format(directory, session_name)
    plt.savefig(average_plot_filepath)

    # Plot all ROC curves
    plt.figure(figsize=(10, 10))
    plot_average_roc_auc_curve(roc_averages)

    for i, (author, metrics) in enumerate(results.items()):
        plt.plot(
            metrics["fpr"], metrics["tpr"], color=get_color(i), lw=lw,
            label="ROC curve for {0:s} (area = {0:0.4f})".format(author, metrics[author]["AUC"]),
        )
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('All ROC Curves for {}'.format(session_name))
    plt.legend(loc="lower right")

    # Save plot
    plot_filepath = "{}/{}_All_ROC.png".format(directory, session_name)
    plt.savefig(plot_filepath)


# Plots a histogram of function lengths in terms of lines of code given a list of functions
# functions is a list of dictionaries mapping tuples of (commitHash, file, lineNumber) to strings
def plot_function_length_histogram(functions, directory="plots", session_name=""):
    function_lengths = [len(function.split("\n")) for function in functions]
    bin_size = 10
    bins = np.arange(min(function_lengths), max(function_lengths) + bin_size, bin_size)

    # Plot histogram
    plt.figure()
    plt.hist(function_lengths, bins=bins, edgecolor='black')
    plt.title("Lines of Code of Classified Functions")
    plt.ylabel("Frequency")
    plt.xlabel("Lines of Code")

    # Save plot
    plot_filepath = "{}/{}_function_LOC_hist.png".format(directory, session_name)
    plt.savefig(plot_filepath)

