import numpy as np
import matplotlib.pyplot as plt
from scipy import interp
from sklearn.metrics import auc

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

    # Interpolate all ROC curves that these points
    mean_tpr = np.zeros_like(all_fpr)
    weighted_mean_tpr = np.zeros_like(all_fpr)

    for author, metrics in results.items():
        mean_tpr += interp(all_fpr, metrics["fpr"], metrics["tpr"])
        weighted_mean_tpr += interp(all_fpr, metrics["fpr"], metrics["tpr"]) * metrics[author]["%"]

    # Average out results
    mean_tpr /= len(results)
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
    }
    return averages


def plot_author_roc_auc_curve(author, fpr, tpr, roc_auc, color='darkorange', directory="classResults", session_name=""):
    plt.figure()
    lw = 2
    plt.plot(
        fpr, tpr, color=color, lw=lw,
        label='ROC curve (area = %0.2f)' % roc_auc
    )
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('ROC Curve for {}'.format(author))
    plt.legend(loc="lower right")

    plot_filepath = "{}/{}_{}_ROC.png".format(directory, session_name, author)
    plt.savefig(plot_filepath)


def plot_roc_auc_curves(results, directory="classResults", session_name=""):
    # Plot individual author ROC curves
    for i, (author, metrics) in enumerate(results.items()):
        plot_author_roc_auc_curve(
            author, metrics["fpr"], metrics["tpr"], metrics[author]["AUC"], get_color(i),
            directory=directory, session_name=session_name
        )

    lw = 2
    plt.figure(figsize=(10, 10))

    roc_averages = get_avg_roc_auc(results)
    # Plot macro average ROC
    plt.plot(
        roc_averages["unweighted"]["fpr"], roc_averages["unweighted"]["tpr"], color="deeppink", lw=lw,
        label="macro average ROC curve (area = {0:0.1f})".format(roc_averages["unweighted"]["AUC"]),
        linestyle=":",
    )
    # Plot weighted average ROC
    plt.plot(
        roc_averages["weighted"]["fpr"], roc_averages["weighted"]["tpr"], color="teal", lw=lw,
        label="weighted average ROC curve (area = {0:0.1f})".format(roc_averages["weighted"]["AUC"]),
        linestyle=":",
    )
    # Plot all ROC curves
    for i, (author, metrics) in enumerate(results.items()):
        plt.plot(
            metrics["fpr"], metrics["tpr"], color=get_color(i), lw=lw,
            label="ROC curve for {0:s} (area = {1:0.1f})".format(author, metrics[author]["AUC"]),
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
