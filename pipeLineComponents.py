from pyspark.ml import Transformer
from pyspark.sql import DataFrame

class reposToCommits(Transformer):
    def _transform(self, repoNames:DataFrame):
        def repoToCommits(repoName:str):

            #check local store to see if we have it clone already

            #if not, clone it

            #mine it in parallel
            #ouput schema should be same as BQ schema

        return repoNames.rdd.map(reposToCommits)

class authorNamesToCommits(Transformer):
    def _transform(self, authorNames:DataFrame):
        def authorToCommits(authorName):
            #get rows in BQ that match the authornames field
    
        return authorNames.rdd.map(authorToCommits)
        
class commitsToDiff(Transformer):
    def _transform(self, commits:DataFrame):
        def commitsToDiff(commit):
        #Check if the commit is already stored locally (or from a local repo)

        # if it is, fetch and output it

        # if it is not, fetch it from the GH API
        return commits.rdd.map(commitsToDiff)

class diffsToFnStr(Transformer):
    def _transform(self, diffs:DataFrame):
        def diffToFNStr(diff):
        #run lizard over the code

        #extract the function as indicated by lizard and output the string
        return diffs.rdd.map(diffsToFnStr)

class fnStrsToTokens(Transformer):
    def _transform(self, fnStrs:DataFrame):
        def fnStrToTokens(fnStr):
        #Lex the code with Clang and return an iterator of token strings
        return fnStr.rdd.map(fnStrToTokens)

class fnStrToWhiteSpaceFeatures(Transformer):
    def _transform(self, fnStr:DataFrame):
        def fnStrToWSPC(fnStr):

        return fnStr.rdd.map(fnStrToWSPC)

class fnStrToASTFeatures(Transformer):
    def _transform(self, fnStr:DataFrame):
        def fnStrToAST(fnStr):

        return fnStr.rdd.map(fnStrToAST)

class fnStrToFeatures(Transformer):
    def _transform(self, fnStr:DataFrame):
        def fnStrToFeatures(fnStr):

        return fnStr.rdd.map(fnStrToFeatures)


class featureReducer(Transformer):
    #takes an fMat with a column called 'label' for the ground truth class
    #outputs an fMat with few columns, based on cv-driven feature selection
    def _transform(self, fMat:DataFrame):
        



