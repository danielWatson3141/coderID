from scipy.sparse import csr_matrix
class featureExtractors:
    #when a new feature is added, added its name to the matching list.
    #order of the names matters, should match order in output vector
    charfeatureNames = []
    tokfeatureNames = []
    astfeatureNames = []

    featureNames = charfeatureNames + tokfeatureNames + astfeatureNames

    @staticmethod
    def characterLevel(function):
        """ returns row vector in scipy.sparse.csr_matrix row format of features extracted from function string"""
        return csr_matrix(0, shape = (1, 1))    #singleton 0 as default
    @staticmethod
    def tokenLevel(tokens):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from token iterable"""
        return csr_matrix(0, shape = (1, 1))    #singleton 0 as default

    @staticmethod
    def astLevel(ast):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from ast"""
        return csr_matrix(0, shape = (1, 1))    #singleton 0 as default