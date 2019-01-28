from scipy.sparse import csr_matrix
import re
import copy
import numpy as np
import collections
import os.path
import PPTools

import warnings
warnings.filterwarnings("error", category=RuntimeWarning)

class featureExtractors:
    #when a new feature is added, added its name to the matching list.
    #order of the names matters, should match order in output vector
    functionLength = 0

    charfeatureNames = ["comments_per_char", "ternary_ops_per_char",
                        "macros_per_char", "num_tabs", "num_spaces", "num_empty_lines",
                        "avg_line_len", "std_line_len", "whitespace_ratio",
                        "new_line_open_brace", "tab_lead_lines"]

    keywords = sorted(['do', 'if', 'else', 'switch', 'for', 'while'])
    tokfeatureNames = ["num_" + word for word in keywords] + \
                      ["num_keywords", "num_tokens", "num_literals",
                       "ctrl_nesting_depth", "bracket_nesting_depth", "num_params"]

    astfeatureNames = []


    @staticmethod
    def normalize(feat_cnt, denom = 0, flag = None):
        """
        :param feat_cnt: Numeric. Feature count to normalize
        :param denom: Numeric. Denominator used when 'division' selected
        :param flag: Str. Can be one of ('log', 'division', None)
        :return:
        """
        if flag is None:
            return feat_cnt
        elif flag == 'log':
            return np.log(feat_cnt + 1)
        elif flag == 'division':
            return feat_cnt / denom
        else:
            msg = "Invalid flag value. Must be one of ('log', 'division', None)"
            raise ValueError(msg)

    @staticmethod
    def characterLevel(function:str):
        """ returns row vector in scipy.sparse.csr_matrix row format of features extracted from function string"""
        nfeatures = len(featureExtractors.charfeatureNames)
        features = np.zeros((nfeatures,), dtype=float)

        fn_len = 0
        line_lengths = []

        nbraces = 0
        new_line_brace = 0
        nindented = 0
        tab_indented = 0

        for line in function.splitlines():

            # tabs
            features[3] += line.count("\t")

            nspaces = line.count(" ")
            features[4] += nspaces

            # with or without whitespace (for sake of consistency)?
            # currently without whitespace
            n = len(line) - nspaces
            line_lengths.append(n)
            fn_len += n

            # indented lines
            if line.startswith(' ') or line.startswith('\t'):
                nindented += 1
                if line.startswith('\t'):
                    tab_indented += 1

            line = line.strip()
            if line == "":
                features[5] += 1 # empty line

            # new line before open braces
            nbraces += line.count("{") + line.count("}")
            if line.startswith("{") or line.startswith("}"):
                new_line_brace += 1

            # comments - need to account for str literals containing these vals
            if '//' in line or line.startswith('/*'):
                features[0] += 1

            # ternary operators
            m = re.search("(.+\?.+:.+)", line)
            if m is not None:
                features[1] += 1

            # macros
            if line.startswith('#'):
                features[2] += 1

        # ratio of whitespace chars to non-whitespace chars
        features[8] = features[3] + features[4] + len(line_lengths) - 1
        features[8] /= fn_len

        for i in range(6):
            features[i] = featureExtractors.normalize(featureExtractors.normalize(features[i],
                                                                                   fn_len,
                                                                                   flag = 'division'),
                                                      flag = 'log')

        features[6] = np.mean(line_lengths)
        features[7] = np.std(line_lengths)

        # bool flag representing whether majority of code block braces preceded
        #  by a new line brace
        if nbraces > 0:
            features[9] = [0, 1][new_line_brace / nbraces > 0.5]
        else:
            features[9] = -1

        if nindented > 0:
            features[10] = [0, 1][tab_indented / nindented > 0.5]
        else:
            features[10] = -1

        featureExtractors.functionLength = fn_len
        return csr_matrix(features, shape=(1, nfeatures))

    @staticmethod
    def tokenLevel(tokens):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from token iterable"""
        nfeatures = len(featureExtractors.tokfeatureNames)
        features = np.zeros((nfeatures,), dtype=float)
        kword_dict = {k:0 for k in featureExtractors.keywords}

        par_stack = collections.deque()
        depth_so_far = 0
        nesting_depth = 0

        brackets = {")": "(",
                    "]": "["}
        bracket_stack = collections.deque()
        depth_so_far_brkt = 0
        nesting_depth_brkt = 0

        n_kwords = len(featureExtractors.keywords)

        for token in tokens:
            # number of tokens
            features[n_kwords + 1] += 1

            kind = str(token.kind)
            # number of literals
            features[n_kwords + 2] += [0, 1][kind == 'TokenKind.KEYWORD']
            # number of keywords
            features[n_kwords] += [0, 1][kind == 'TokenKind.LITERAL']

            tok = token.spelling

            #print("{}".format(token))
            if tok in featureExtractors.keywords:
                kword_dict[tok] += 1

            # ctrl nesting depth calculations
            if tok == "{":
                if len(par_stack) == 0:
                    depth_so_far = 0
                par_stack.append(tok)

            if tok == "}":
                depth_so_far += 1
                if par_stack:
                    par_stack.pop()
                    if len(par_stack) == 0:
                        nesting_depth = max(nesting_depth, depth_so_far)

            # bracket nesting depth calculations
            if tok in brackets.values():    # opening brackets
                if len(bracket_stack) == 0:
                    depth_so_far_brkt = 0
                    bracket_stack.append(tok)

            if tok in brackets.keys():      # closing brackets
                depth_so_far_brkt += 1
                if bracket_stack:
                    bracket_stack.pop()
                    if len(bracket_stack) == 0:
                        nesting_depth_brkt = max(nesting_depth_brkt, depth_so_far_brkt)


        nesting_depth = max(nesting_depth, depth_so_far + len(par_stack))
        nesting_depth_brkt = max(nesting_depth_brkt,
                                 depth_so_far_brkt + len(bracket_stack))

        ind = 0
        for kword in featureExtractors.keywords:
            """
            features[ind] = featureExtractors.normalize(
                featureExtractors.normalize(kword_dict[kword], featureExtractors.functionLength, flag='division'), 
                flag='log')
            """
            features[ind] = featureExtractors.normalize(kword_dict[kword])
            ind += 1

        for i in range(3):
            ind = i + n_kwords
            """
            features[ind] = featureExtractors.normalize(
                featureExtractors.normalize(features[ind], featureExtractors.functionLength, flag='division'), 
                flag='log')
            """
            features[ind] = featureExtractors.normalize(features[ind])


        features[n_kwords + 3] = nesting_depth
        features[n_kwords + 4] = nesting_depth_brkt

        return csr_matrix(features, shape = (1, nfeatures))

    @staticmethod
    def astLevel(ast):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from ast"""
        return csr_matrix(0, shape = (1, 1))    #singleton 0 as default

"""
if __name__ == "__main__":
    tst = #include <ctype.h>
    #include <errno.h>
    
    static ssize_t get_cpu_usages(thermal_module_t *module, cpu_usage_t *list) {
    int vals, cpu_num, online;
    ssize_t read;
    uint64_t user, nice, system, idle, active, total;
    char *line = NULL;
    size_t len = 0;
    size_t size = 0;
    char file_name[MAX_LENGTH]; // test
    FILE *file;
    FILE *cpu_file;
    if (list == NULL) {
        return CPU_NUM;
    }
    file = fopen(CPU_USAGE_FILE, "r");
    if (file == NULL) {
        ALOGE("%s: failed to open: %s", __func__, strerror(errno));
        return -errno;
    }
    while ((read = getline(&line, &len, file)) != -1) {
        // Skip non "cpu[0-9]" lines.
        if (strnlen(line, read) < 4 || strncmp(line, "cpu", 3) != 0 || !isdigit(line[3])) {
            free(line);
            line = NULL;
            len = 0;
            continue;
        }
        vals = sscanf(line, "cpu%d %" SCNu64 " %" SCNu64 " %" SCNu64 " %" SCNu64, &cpu_num, &user,
                &nice, &system, &idle);
        free(line);
        line = NULL;
        len = 0;
        
        /*
        test 2
        */
        
        test = does_this_work ? 'yes' : 'no'
        
        if (vals != 5 || size == CPU_NUM) {
            if (vals != 5) {
                ALOGE("%s: failed to read CPU information from file: %s", __func__,
                        strerror(errno));
            } else {
                ALOGE("/proc/stat file has incorrect format.");
            }
            fclose(file);
            return errno ? -errno : -EIO;
        }
        
        active = user + nice + system;
        total = active + idle;
        // Read online CPU information.
        snprintf(file_name, MAX_LENGTH, CPU_ONLINE_FILE_FORMAT, cpu_num);
        cpu_file = fopen(file_name, "r");
        online = 0;
        if (cpu_file == NULL) {
            ALOGE("%s: failed to open file: %s (%s)", __func__, file_name, strerror(errno));
            fclose(file);
            return -errno;
        }
        if (1 != fscanf(cpu_file, "%d", &online)) {
            ALOGE("%s: failed to read CPU online information from file: %s (%s)", __func__,
                    file_name, strerror(errno));
            fclose(file);
            fclose(cpu_file);
            return errno ? -errno : -EIO;
        }
        fclose(cpu_file);
        list[size] = (cpu_usage_t) {
            .name = CPU_LABEL[size],
            .active = active,
            .total = total,
            .is_online = online
        };
        size++;
    }
    fclose(file);
    if (size != CPU_NUM) {
        ALOGE("/proc/stat file has incorrect format.");
        return -EIO;
    }
    return size;
}
    print(featureExtractors.charfeatureNames)
    print(featureExtractors.characterLevel(tst))
    filename = os.getcwd() + "/test.cpp"
    #tokens = PPTools.Tokenize.cpp(filename)
    #print(featureExtractors.tokfeatureNames)
    #print(featureExtractors.tokenLevel(tokens))
    tu = PPTools.Tokenize.cpp(filename)
"""

"""
class AST:
    def __init__(self, cursor):
        self.cur = cursor # top-level node
        self.depth = 0
        # use dict to store counts of cursor types for now
        # TODO: extend this to store counts for distinct sub-paths
        # Construct an element of the corpus of the node types by traversing the tree and the
        #   storing the type of each node in a vector
        #
"""