from enum import Enum
from sklearn.feature_selection import mutual_info_classif, SelectKBest
from sklearn.feature_extraction.text import TfidfVectorizer
from scipy.sparse import hstack, vstack, csr_matrix
from tqdm import tqdm
import itertools
from collections import Counter
import numpy as np
import os
import re
import time
import queue
import github
import PPTools
import ASTFeatureExtractor
import pydriller
import featureExtractors
import multiprocessing
import sys
import warnings
if not sys.warnoptions:
    warnings.simplefilter("ignore")


class gitProfileSet:

    # TODO: Make it so re-compiling doesn't break
    # TODO: Make sibling class of ProfileSet

    langList = ["cpp", "c", "C++", "c++", "C"]

    def __init__(self, name):
        """Initialize a new gitset"""
        self.name = name
        self.repos = []
        self.authors = dict()
        self.featuresDetected = False
        self.featuresSelected = None
        self.termsSelected = None
        self.minedRepos = set()
        #self.authorLock = set()

    def addRepo(self, args):
        print("Adding repo: "+args)
        try:
            if args not in self.repos:
                self.repos.append(args)
        except Exception:
            print("Couldn't get that one...")
        # self.compileAuthors(newRepo)

    def mineLocalRepos(self):
        """Mine all repos in the repo list for commits by those in authors. None for get all"""
        for repo in self.repos:
            if repo in self.minedRepos or repo is None:
                continue
            miner = pydriller.repository_mining.RepositoryMining(
                repo, only_modifications_with_file_types=gitProfileSet.langList, only_no_merge=True)

            print("Scanning repo: "+miner._path_to_repo)

            tipeCounts = dict()

            for commit in tqdm(miner.traverse_commits()):
                author = commit.author
                tipe = commitType.categorize(commit)

                if tipe not in tipeCounts:
                    tipeCounts.update({tipe: 0})
                count = tipeCounts.get(tipe)
                tipeCounts.update({tipe: count+1})

                # if tipe is commitType.FEATURE:
                if True:
                    if author.name not in self.authors:
                        self.authors.update({author.name: gitAuthor(author)})
                        #print("Found new author: "+author.name)

                    author = self.authors.get(author.name)

                    author.commits.update({(repo, commit.hash): commit})
                    # author.commits.add((repo,commit.hash))

                    if repo not in author.repos:
                        author.repos.add(repo)

                    author.extractCommitInfo(commit)

            print(str("finished"+str(miner._path_to_repo)))
            print("types: "+str(tipeCounts))
            #print(authorsWithEnoughDocs+" authors with enough code so far.")

    def displayAuthors(self):
        for value in self.authors.values():
            print(value)

    def getFeatures(self):
        numAuthors = PPTools.Config.get_value('Model', 'number_of_authors')

        inputs = []
        node_types = []
        code_unigrams = []
        self.target = []
        charfeatureNames = featureExtractors.featureExtractors.charfeatureNames
        charLevelFeatures = None
        tokfeatureNames = featureExtractors.featureExtractors.tokfeatureNames
        tokFeatures = None

        # generating tokens/unigrams
        print("Gathering char and token level features")
        authors_seen = 0
        for author in tqdm(self.authors.values()):
            if numAuthors != -1 and authors_seen == numAuthors:
                break
            authors_seen += 1

            for fun in author.functions:
                fn_str = '\n'.join(fun.values())

                # whitespace fn's still getting in. This will catch for that.
                if fn_str.isspace() or fn_str == '':
                    continue

                try:
                    tu = PPTools.Tokenize.get_tu(fn_str)
                    # Sometimes this  breaks for n.a.r.
                    tokens = list(tu.get_tokens(extent=tu.cursor.extent))
                    inputs.append(PPTools.Tokenize.tokensToText(
                        tokens))  # Convert to text

                    # Reset tu Brute?
                    #tu = PPTools.Tokenize.get_tu(fn_str)

                    #tree = ASTFeatureExtractor.AST(tu.cursor)
                    # tree.traverse()

                    # TODO: concatenate in the featureExtractor module or here?
                    #node_types.append(" ".join(tree.node_types))
                    #code_unigrams.append(" ".join(tree.code_unigrams))
                    #del tree

                except Exception:
                    continue

                """
                Bigram matrix:
                Create a dok matrix (Dictionary Of Keys based sparse matrix) here
                """
                # Function-string level features
                if charLevelFeatures is None:
                    charLevelFeatures = featureExtractors.featureExtractors.characterLevel(
                        fn_str)
                else:
                    charLevelFeatures = vstack([charLevelFeatures,
                                                featureExtractors.featureExtractors.characterLevel(fn_str)])

                # Token-level features
                # if tokFeatures is None:
                #     tokFeatures = featureExtractors.featureExtractors.tokenLevel(tokens)
                # else:
                #     tokFeatures = vstack([tokFeatures, featureExtractors.featureExtractors.tokenLevel(tokens)])

                self.target.append(author.name)
                del tokens

        inputs = np.array(inputs)

        # TODO: abstract this out since it gets used a lot.
        print("Vectorizing...")
        vectorizer = TfidfVectorizer(analyzer="word", token_pattern="\S*",
                                     decode_error="ignore", lowercase=False)
        vectorizer_tf = TfidfVectorizer(analyzer="word", token_pattern="\S*",
                                        decode_error="ignore", lowercase=False,
                                        use_idf=False)

        self.counts = hstack([charLevelFeatures, tokFeatures], format='csr')
        self.terms = charfeatureNames  # + tokfeatureNames

        need_tf = False

        #i = 0
        # for features in tqdm([inputs, node_types, code_unigrams]):
        #    i += 1
        # TFIDF
        self.counts = hstack([self.counts, vectorizer.fit_transform(inputs)],
                             format='csr')
        self.terms += vectorizer.get_feature_names()

        # Get only the term frequencies
        # if need_tf:
        #     self.counts = hstack([self.counts, vectorizer_tf.fit_transform(features)],
        #                             format = 'csr')
        #     self.terms += vectorizer_tf.get_feature_names()
        # else:
        #     # accounts for the fact that we do not need the TF of the unigrams/inputs
        #     need_tf = True

        del inputs, node_types, code_unigrams

        self.target = np.array(self.target)

        self.featuresDetected = True
        # should fit feature detector here
        # then pass it down

    def featureSelect(self):
        section = 'Feature Selection'
        reductionFactor = PPTools.Config.get_value(section, 'reduction_factor')
        # First round feature selection using mutual information

        if self.featuresSelected is not None:
            print("Features selected already, skipping.")

        total_num_features = self.counts.shape[1]
        print("Number of features before selection: {}".format(total_num_features))

        from sklearn.ensemble import RandomForestClassifier
        from sklearn import feature_selection
        import heapq

        # featureSets = dict() #keep track of sets and feature importances
        # format: key=n_features value = (strength, features, importances)

        # clf = RandomForestClassifier(n_estimators=300, oob_score=True, max_features="sqrt")
        clf = RandomForestClassifier(n_estimators=PPTools.Config.get_value(section, 'n_estimators'),
                                     oob_score=PPTools.Config.get_value(
                                         section, 'oob_score'),
                                     max_features=PPTools.Config.get_value(section, 'max_features'))

        # train with all features to start

        previous = 0
        strength = .01

        nFeatures = total_num_features
        features = self.counts
        terms = self.terms

        previousFeatures = None
        previousTerms = None

        # choose optimal feature set size
        while True:
            previous = strength

            strength, importances = self.evaluate(clf, features, self.target)
            print((nFeatures, strength))
            if strength < previous:
                break
            from operator import itemgetter
            match = zip(range(0, nFeatures), importances)

            nFeatures = int(reductionFactor*nFeatures)

            previousFeatures = features
            previousTerms = terms

            best = list(map(lambda x: x[0], heapq.nlargest(
                nFeatures, match, key=itemgetter(1))))

            features = features[:, best]
            terms = [terms[i] for i in best]

        self.featuresSelected = previousFeatures
        self.termsSelected = previousTerms

        print("Features selected...")

        n_relevant_features = len(self.termsSelected)

        print("Number of features after selection: {}".format(n_relevant_features))
        frac_selected = 100 * n_relevant_features / total_num_features
        print("Percentage of features selected: {:.2f}%".format(frac_selected))

    def evaluate(self, clf, features, targets):
        from sklearn.model_selection import cross_val_score, ShuffleSplit
        numSamples = features.shape[0]
        section = 'Cross Validation'

        splits = PPTools.Config.get_value(section, 'n_splits')
        trSize = int(min(PPTools.Config.get_value(section, 'train_min'),
                         numSamples * PPTools.Config.get_value(section, 'train_ratio')))
        teSize = int(min(PPTools.Config.get_value(section, 'test_min'),
                         numSamples * PPTools.Config.get_value(section, 'test_ratio')))
        featureCount = features.shape[1]
        cv = ShuffleSplit(n_splits=splits, train_size=trSize, test_size=teSize)

        importances = np.zeros(featureCount)
        strength = 0
        for train, test in cv.split(features, targets):

            trFeatures = features[train]
            trTarget = targets[train]

            teFeatures = features[test]
            teTarget = targets[test]

            clf.fit(trFeatures, trTarget)

            predictions = clf.predict(teFeatures)

            stren = len(np.where(predictions == teTarget)[0])/teSize

            strength += stren / splits
            importances += clf.feature_importances_ / splits

        return (strength, importances)

    def testProgrammerTransparency(self, authors=None):
        results = dict()
        #{name: (pr, re, f1)}
        if authors == None:
            authors = [author.name for author in self.authors]

        for author in authors:
            results.update({author: 0})

        return results

    def functionToString(self, lines):
        textLines = list(len(lines))

        for lineInfo, line in lines:
            cHash, fil, lnum = lineInfo
            textLines[lnum] = line

        return "\n".join(textLines)

    def __str__(self):
        return (str(len(self.authors))+" authors. "+str(sum(map(lambda x: len(x.functions), self.authors.values())))+" functions in total.")


class gitAuthor:

    def __init__(self, dev):

        if isinstance(dev, tuple):
            self.name, self.email = dev
        else:
            self.name = dev.name
            self.email = dev.email

        self.commits = set()  # dict of sets {repoURL: commitSha's}
        #self.files = set()
        # list of dicts. Each dict represents a function. str same as self.lines
        self.functions = list()
        # key: {commitHash,file.cpp,lineNumber} value: literal code
        self.lines = dict()
        self.repos = set()

    def merge(self, other):
        """merges the authors into one author object, keeping self.name"""
        print("Merging author: "+self.name)
        self.commits.add(other.commits)
        self.functions.extend(other.functions)
        # self.files.union(other.files)
        self.lines.update(other.lines)

    def __str__(self):
        return self.name+": "+str(len(self.commits))+" commits. "+str(len(self.lines))+" LOC, "+str(len(self.functions))+" complete functions from "+str(len(self.repos)) + " repos."

    def extractCommitInfo(self, commit):
        for mod in commit.modifications:
            mod._calculate_metrics()
            if mod.new_path is None or not mod.new_path.split(".")[-1] in gitProfileSet.langList:
                continue

            # self.files.add(mod.new_path)
            # parse diff and add lines to list

            leDiff = PPTools.parse_diff(mod.diff)
            for num, line in leDiff["added"]:
                self.lines.update({(commit.hash, mod.new_path, num): line})

            # extract functions with lizard
            funs = mod._function_list

            # maintain list of dicts containing the source code of specific functions. Same format as for lines
            lineIndex = 0
            for fun in funs:
                newFun = dict()
                try:
                    while(leDiff["added"][lineIndex][0] < fun.start_line):
                        lineIndex += 1

                    while(leDiff["added"][lineIndex][0] < fun.end_line+1):
                        newFun.update(
                            {(commit.hash, mod.new_path, leDiff["added"][lineIndex][0]): leDiff["added"][lineIndex][1]})
                        lineIndex += 1
                # if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                except IndexError:
                    pass
                if len(newFun) > 1:
                    self.functions.append(newFun)

    def getNamedUser(self):
        """Best effort search of github for the user by both name, email and fullname. Always returns single best match"""
        with open(os.getcwd()+"/github.token", 'r') as file:
            g = github.MainClass.Github(file.readline().split("\n")[0], timeout=30)

        emailResult = None
        try:
            emailResult = g.search_users(self.email+" in:email")
            if emailResult.totalCount == 1:
                return emailResult[0]
        except Exception:
            pass

        fullNameResult = None
        try:
            fullNameResult = g.search_users(self.name+" in:fullname")
            if fullNameResult.totalCount == 1:
                return fullNameResult[0]
        except Exception:
            pass

        loginResult = None
        try:
            loginResult = g.search_users(self.name+" in:login")
            if loginResult.totalCount == 1:
                return loginResult[0]
        except Exception:
            pass

        if emailResult.totalCount > 0 or loginResult.totalCount > 0 or fullNameResult.totalCount > 0:
            return self.ghUserListIntersection(emailResult, loginResult, fullNameResult)
        else:
            return None

    @staticmethod
    def ghUserListIntersection(email, login, fullname):
        foundUsers = set()

        if email.totalCount > 100 or email.totalCount == 0:
            email = None    #prevent API drain from long lists
        if login.totalCount > 100 or login.totalCount == 0:
            login = None    #prevent API drain from long lists
        if fullname.totalCount > 100 or fullname.totalCount == 0:
            fullname = None
        

        if email:
            foundUsers = foundUsers.union(email)

        if login:
            if not foundUsers:
                foundUsers = foundUsers.union(login)
            else:
                foundUsers = foundUsers.intersection(login)

        if len(foundUsers) == 1:
            return list(foundUsers)[0]

        if fullname:
            if not foundUsers:
                foundUsers = foundUsers.union(fullname)
            else:
                foundUsers = foundUsers.intersection(fullname)

        if foundUsers:
            return list(foundUsers)[0]
        elif email:
            return email[0]
        elif login:
            return login[0]
        elif fullname:
            return fullname[0]

        return None

    def getRepos(self, skip=None):
        """Get all repos associated with a given author, except for those in skip"""
        users = self.getNamedUser()

        while(True):
            try:
                repoList = []
                userCount = 0
                for user in users:
                    userCount += 1
                    for repo in user.get_repos():
                        if repo.language in gitProfileSet.langList and (not skip or repo not in self.repos):
                            repoList.append(repo)

                return repoList
            except github.RateLimitExceededException:
                print("API rate limit exceeded. Chilling for 60 seconds.")
                time.sleep(60)

            except github.GithubException:
                print("Appears we got a 502, wait a second...")
                time.sleep(1)

        #print(str(userCount)+" users found by that id.")

        return repoList

    def fetchCommits(self):
        """Fetch all public commits and stores in self.commits"""
        user = self.getNamedUser()
        if user is None:
            return None

        events = user.get_events()
        mods = []
        for event in events:
            if event.type == "PushEvent":
                try:
                    commits = event.payload['commits']
                    repo = event.repo
                    if not repo.language in gitProfileSet.langList:
                        continue
                    self.repos.add(repo.git_url)
                    try:
                        comparison = repo.compare(event._payload.value['before'], event._payload.value['head'])
                    except Exception:
                        print("likely timeout. Trying again in 5 seconds")
                        time.sleep(5)
                        try:
                            comparison = repo.compare(event._payload.value['before'], event._payload.value['head'])
                        except Exception:
                            continue
                        
                    mods.append(comparison)
                    self.commits.add((repo.git_url, commits[0]['sha']))
                except github.GithubException:
                    print("Encountered GH problem.")
                    continue
        if mods == []:
            return None
        else:
            return mods

    def extractComparisonInfo(self, comparison):
        files = comparison.files  # get files in commit

        # TODO: This section is just gross, consider refactor
        for f in files:
            if f.additions == 0:
                continue
            filename = f.filename
            if len(filename.split(".")) >= 2:
                ext = filename.split(".")[-1]
                if ext in gitProfileSet.langList:  # check for files with c or c++ extensions
                    if f.patch is None:
                        continue
                    diff = PPTools.parse_diff(f.patch)  # parse the diff

                    newSC = list()
                    for line in diff["added"]:  # save each line
                        newSC.append(line[1])
                    from lizard import analyze_file as liz
                    fileInfo = liz.analyze_source_code(
                        filename, "\n".join(newSC))  # ask lizard for functions
                    lineIndex = 0
                    for fun in fileInfo.function_list:  # separate source code out by functions
                        newFun = dict()
                        try:
                            while lineIndex+1 < fun.start_line:
                                lineIndex += 1

                            while(lineIndex < fun.end_line):
                                newFun.update(
                                    {(comparison.base_commit.sha, filename, diff["added"][lineIndex][0]): diff["added"][lineIndex][1]})
                                self.lines.update(
                                    {(comparison.base_commit.sha, filename, diff["added"][lineIndex][0]): diff["added"][lineIndex][1]})
                                lineIndex += 1
                        # if end of input reached before end of functions. This is probable when non-complete functions are submitted.
                        except IndexError:
                            pass
                        if len(newFun) > 1:
                            self.functions.append(newFun)

    def mineMods(self, mods):
        #print("Mining Commits...")
        for comparison in mods:
            self.extractComparisonInfo(comparison)

    def getGPSofSelf(self, skip=[]):
        """Generates a GPS containing this author and all of their public commits."""

        gps = gitProfileSet(self.name)
        # gps.authorLock.add(self.name)

        author = gitAuthor((self.name, self.email))

        gps.authors.update({self.name: author})

        try:
            mods = author.fetchCommits()
        except github.RateLimitExceededException:
            print("API rate limit exceeded. Chilling for 60 seconds.")
            for i in tqdm(range(1, 60)):
                time.sleep(1)
            return self.getGPSofSelf(skip)

        author.mineMods(mods)
        
        # TODO: finish this

        return gps


class commitType(Enum):
    FEATURE = "FC"
    BUGFIX = "BF"
    REFACTOR = "RF"
    OTHER = "OTH"

    types = {FEATURE, BUGFIX, REFACTOR, OTHER}

    def describe(self):
        # self is the member here
        return self.name, self.value

    # TODO: User better heuristic
    @staticmethod
    def categorize(commit):
        added = 0
        removed = 0
        for mod in commit.modifications:
            if mod.new_path is None or mod.new_path.split(".")[-1] not in gitProfileSet.langList:
                continue
            # mod._calculate_metrics()
            added += mod.added
            removed += mod.removed

        if added == 0:
            return commitType.OTHER

        if added-removed < .1*added:
            if added < 20:
                return commitType.BUGFIX
            else:
                return commitType.REFACTOR

        if added > 20:
            return commitType.FEATURE

        return commitType.OTHER
