import PPTools
from collections import defaultdict
from sklearn.naive_bayes import MultinomialNB
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import LinearSVC

class Classifier:

    def __init__(self):
        """
        :param model_name: String. the type of model that this classifier is.
            Must be one of "random_forest", "logit", "linear_svm", "naive_bayes".
        :return: a Classifier object.
        """
        self.model_name = PPTools.Config.config['Model']['model_name']
        self.train_size = PPTools.Config.get_value('Model', 'train_size')

        self.parameters = defaultdict()
        for k, v in PPTools.Config.config.items(self.model_name):
            self.parameters[k] = PPTools.Config.cast_value(v)

        if self.model_name == "random_forest":
            self.model = RandomForestClassifier(**self.parameters)

        elif self.model_name == "logit":
            self.model = LogisticRegression(**self.parameters)

        elif self.model_name == "linear_svm":
            self.model = LinearSVC(**self.parameters)

        elif self.model_name == "naive_bayes":
            self.model = MultinomialNB(**self.parameters)

        else:
            assert(True, "Invalid model choice. Parameter model_name must be one " \
                         "of 'random_forest', 'logit', 'svm', or 'naive_bayes'.")


    def preprocess(self, X):
        """
        :param X: a dataset
        :return: the dataset preprocessed
        """
        pass

    def set_parameters(self, param_dict):
        """

        :param param_dict: Dictionary containing the parameters to be changed
            and their new values
        :return:
        """
        for param_name, value in param_dict.items():
            self.parameters[param_name] = value
            PPTools.Config.update(self.model_name, param_name, value)

        self.model.set_params(**self.parameters)

