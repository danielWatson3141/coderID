import matplotlib.pyplot as plt
import pandas as pd
import sys
import os


def get_csv_feature_names(csv_file):
    """
    Reads a CSV file and gets the features names
    in it, as well as the rank of the features
    :return: Pandas DataFrame
    """
    df = pd.read_csv(csv_file, usecols=[0, 1, 3])
    df.sort_values(by='sumImportance', ascending=False, inplace=True)
    df['rank'] = range(len(df))
    df['rank'] += 1
    return df


def get_top_features(features_loc, save_loc):
    """
    Gets the top 100 features for all repos with feature importance
        reports in the features_loc directory, and saving these features
        to a csv in the save_loc directory
    :return: Tuple of Pandas Dataframes
    """
    all_features = None  # top 100 features for each repo
    top_features = None  # top 100 features overall

    for filename in os.listdir(features_loc):
        if filename.endswith("features.csv"):
            df = get_csv_feature_names(os.path.join(features_loc, filename))

            repo_name = filename.split('_features.csv')[0]
            model_type = '_single_model_multi'  # removing the model name
            # from the repo name
            if repo_name.endswith('_single_model_multi'):
                repo_name = repo_name.split('_single_model_multi')[0]
            elif repo_name.endswith('_binary'):
                repo_name = repo_name.split('_binary')[0]
            else:
                repo_name = repo_name.split('_multi')[0]
            df['repo'] = repo_name

            if top_features is None:
                top_features = df
                all_features = df.iloc[0:100]
            else:
                top_features = pd.concat([top_features, df])
                all_features = pd.concat([all_features, df.iloc[0:100]])

    top_features = top_features.groupby('feature Name').agg(
        {'Type': lambda x: x.unique(),
         'rank': 'mean'})
    top_features.sort_values(by='rank', inplace=True)
    top_features.rename(columns={'rank': 'mean_rank'}, inplace=True)
    top_features = top_features.iloc[0:100]

    tmp = top_features.iloc[0:30]
    tmp.to_csv(os.path.join(save_loc, 'top_30_features.csv'), index=True)

    return all_features, top_features


def get_percent_in_top_100(all_features, top_features, save_loc):
    """
    For each repo in all_features, the percentage of the repo's top 100 features
        that appear in the top overall 100 features (stored in top_features) is
        calculated and displayed in a bar plot. The data is stored in a csv in
        the save_loc directory
    :return: None
    """
    in_top_features = all_features.loc[
        all_features['feature Name'].isin(top_features.index),]
    in_top_features = in_top_features.groupby('repo')['feature Name'].count()
    in_top_features.name = 'percentage'
    in_top_features = in_top_features.to_frame().reset_index()
    in_top_features.to_csv(os.path.join(save_loc, "percent_in_top_100_by_repo.csv"),
                           index=False)

    # plot bar graph
    ax = in_top_features.plot.bar(x='repo', y='percentage', color="#5E96AE")
    ax.set_xticklabels(labels=in_top_features['repo'], rotation=45)
    ax.set_title("Features by Repo in Overall Top 100 Features")
    # ax.set_ylim(top=100, bottom=0)
    ax.set_xlabel("Repository")
    ax.set_ylabel("Percentage")
    ax.get_legend().remove()
    plt.show()
    plt.savefig(os.path.join(save_loc, 'features_by_repo_in_top_100.png'), bbox_inches='tight')


if __name__ == "__main__":
    save_loc = "./" # no save location provided -> default to current directory
    if len(sys.argv) < 2:
        sample_dir = "feature_reports/"
        print("You must pass in a features report directory, and, optionally, a save directory. e.g. python {} {}".format(sys.argv[0], sample_dir))
        exit(1)
    if len(sys.argv) > 2: # save location given
        save_loc = sys.argv[2]
    report_loc = sys.argv[1]

    all_features, top_features = get_top_features(report_loc, save_loc)
    get_percent_in_top_100(all_features, top_features, save_loc)