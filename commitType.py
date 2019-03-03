from enum import Enum
from collections import defaultdict

correctiveDict = defaultdict(int, (
    ('active', 1),
    ('against', 1),
    ('already', 1),
    ('bad', 1),
    ('block', 1),
    ('bug', 1),
    ('build', 1),
    ('call', 1),
    ('case', 1),
    ('catch', 1),
    ('cause', 2),
    ('character', 1),
    ('compile', 1),
    ('correctly', 1),
    ('create', 1),
    ('different', 1),
    ('dump', 1),
    ('error', 2),
    ('except', 1),
    ('exist', 1),
    ('explicitly', 1),
    ('fail', 1),
    ('failure', 2),
    ('fast', 1),
    ('fix', 2),
    ('format', 1),
    ('good', 1),
    ('hack', 1),
    ('hard', 1),
    ('help', 1),
    ('init', 1),
    ('instead', 1),
    ('introduce', 1),
    ('issue', 1),
    ('lock', 1),
    ('log', 1),
    ('logic', 1),
    ('look', 1),
    ('merge', 1),
    ('miss', 2),
    ('null', 2),
    ('oops', 2),
    ('operation', 1),
    ('operations', 1),
    ('pass', 1),
    ('previous', 1),
    ('previously', 1),
    ('probably', 1),
    ('problem', 1),
    ('properly', 1),
    ('random', 1),
    ('recent', 1),
    ('request', 1),
    ('reset', 1),
    ('review', 1),
    ('run', 1),
    ('safe', 1),
    ('set', 1),
    ('similar', 1),
    ('simplify', 1),
    ('special', 1),
    ('test', 1),
    ('think', 1),
    ('try', 1),
    ('turn', 1),
    ('valid', 1),
    ('wait', 1),
    ('warn', 2),
    ('warning', 1),
    ('wrong', 2),
))
adaptiveDict = defaultdict(int, (
    ('active', 1),
    ('add', 2),
    ('additional', 2),
    ('against', 1),
    ('already', 1),
    ('appropriate', 2),
    ('available', 2),
    ('bad', 1),
    ('behavior', 1),
    ('block', 1),
    ('build', 1),
    ('call', 1),
    ('case', 1),
    ('catch', 1),
    ('change', 2),
    ('character', 1),
    ('compatibility', 2),
    ('compile', 1),
    ('config', 2),
    ('configuration', 2),
    ('context', 2),
    ('correctly', 1),
    ('create', 1),
    ('currently', 2),
    ('default', 2),
    ('different', 1),
    ('documentation', 2),
    ('dump', 1),
    ('easier', 2),
    ('except', 1),
    ('exist', 1),
    ('explicitly', 1),
    ('fail', 1),
    ('fast', 1),
    ('feature', 2),
    ('format', 1),
    ('future', 2),
    ('good', 1),
    ('hack', 1),
    ('hard', 1),
    ('header', 1),
    ('help', 1),
    ('include', 1),
    ('information', 2),
    ('init', 1),
    ('inline', 1),
    ('install', 2),
    ('instead', 1),
    ('internal', 2),
    ('introduce', 1),
    ('issue', 1),
    ('lock', 1),
    ('log', 1),
    ('logic', 1),
    ('look', 1),
    ('merge', 1),
    ('method', 2),
    ('necessary', 2),
    ('new', 2),
    ('old', 2),
    ('operation', 1),
    ('operations', 1),
    ('pass', 1),
    ('patch', 2),
    ('previous', 1),
    ('previously', 1),
    ('probably', 1),
    ('properly', 1),
    ('protocol', 2),
    ('provide', 2),
    ('random', 1),
    ('recent', 1),
    ('release', 2),
    ('replace', 1),
    ('request', 1),
    ('require', 2),
    ('reset', 1),
    ('review', 1),
    ('run', 1),
    ('safe', 1),
    ('security', 2),
    ('set', 1),
    ('similar', 1),
    ('simple', 2),
    ('simplify', 1),
    ('special', 1),
    ('structure', 2),
    ('switch', 2),
    ('test', 1),
    ('text', 2),
    ('think', 1),
    ('trunk', 2),
    ('try', 1),
    ('turn', 1),
    ('useful', 2),
    ('user', 2),
    ('valid', 1),
    ('version', 2),
    ('wait', 1),
))
perfectiveDict = defaultdict(int, (
    ('cleanup', 2),
    ('consistent', 2),
    ('declaration', 2),
    ('definition', 2),
    ('header', 1),
    ('include', 1),
    ('inline', 1),
    ('move', 2),
    ('prototype', 2),
    ('removal', 2),
    ('static', 2),
    ('style', 2),
    ('unused', 2),
    ('variable', 2),
    ('warning', 1),
    ('whitespace', 2),
))

class commitType(Enum):
    FEATURE = "FC"
    BUGFIX = "BF"
    REFACTOR = "RF"
    OTHER = "OTH"

    types = {FEATURE, BUGFIX, REFACTOR, OTHER}


    def describe(self):
        # self is the member here
        return self.name, self.value

    @staticmethod
    def categorize(commit, langList=None):
        added = 0
        removed = 0
        for mod in commit.modifications:
            if mod.new_path is None or (langList is not None and mod.new_path.split(".")[-1] not in langList):
                continue
            added += mod.added
            removed += mod.removed

        if added == 0:
            return commitType.OTHER

        categories = [
            [0, correctiveDict, commitType.BUGFIX],
            [0, adaptiveDict, commitType.FEATURE],
            [0, perfectiveDict, commitType.REFACTOR],
        ]
        for word in commit.msg.split():
            for category in categories:
                category[0] += category[1][word]

        # Use old heuristic if weight is 0 for all categories
        if (all(lst[0] == 0 for lst in categories)):
            if added-removed < .1*added:
                if added < 20:
                    return commitType.BUGFIX
                else:
                    return commitType.REFACTOR
            if added > 20:
                return commitType.FEATURE
            return commitType.OTHER

        return max(categories, key=lambda category: category[0])[2]

