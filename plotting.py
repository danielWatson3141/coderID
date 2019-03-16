import matplotlib.pyplot as plt

# Generates distinct colours given a number. Returns black if the index is too high
def get_color(index):
    colors = [
        'red', 'blue', 'green', 'purple', 'cyan', 'lime', 'indigo', 'crimson',
        'dodgerblue', 'deepskyblue', 'coral', 'saddlebrown', 'orange', 'olive'
    ]
    if (index < len(colors)):
        return colors[index]
    return 'black'


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
