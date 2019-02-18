from collections import defaultdict
from sklearn.naive_bayes import MultinomialNB
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import LinearSVC

class Classifier:

    def __init__(self, model_name):
        """
        :param model_name: String. the type of model that this classifier is.
            Must be one of "random_forest", "logit", "linear_svm", "naive_bayes".
        :return: a Classifier object.
        """
        # TODO: add a param_dict parameter here?
        self.model_name = model_name

        if model_name == "random_forest":
            self.parameters = {
                "n_estimators": 10,
                "oob_score": True,
                "max_features": "sqrt"
            }
            self.model = RandomForestClassifier(**self.parameters)

        elif model_name == "logit":
            self.parameters = {
                "penalty": "l2",
                "solver": "saga", # check if other methods may be better
                "multi_class": "multinomial",
                # NOTE: Set a random_state value when solver == ‘sag’ or ‘liblinear’.
                # TODO: add check for the above.
                "random_state": None
            }
            self.model = LogisticRegression(**self.parameters)

        elif model_name == "linear_svm":
            self.parameters = {
                "penalty": "l2",
                "loss": "squared_hinge",
                # TODO: From docs: "Prefer dual=False when n_samples > n_features." Account for this later
                "dual": True,
                "random_state": None,
                "tol": 1e-4
            }
            self.model = LinearSVC(**self.parameters)

        elif model_name == "naive_bayes":
            self.parameters = {}
            self.model = MultinomialNB(**self.parameters)

        else:
            assert(True, "Invalid model choice. Parameter model_name must be one " \
                         "of 'random_forest', 'logit', 'svm', or 'naive_bayes'.")

        self.parameters = defaultdict(None, self.parameters)


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
        self.model.set_params(**self.parameters)

