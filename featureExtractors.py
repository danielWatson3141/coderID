from scipy.sparse import csr_matrix
import re
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
            try:
                features[i] = np.log(features[i] / fn_len)
            except RuntimeWarning: # cannot divide by 0
                features[i] = np.NAN # use this or 0?

        features[6] = np.mean(line_lengths)
        features[7] = np.std(line_lengths)

        # bool flag representing whether majority of code block braces preceded
        #  by a new line brace
        if nbraces > 0:
            features[9] = [0, 1][new_line_brace / nbraces > 0.5]
        else:
            features[9] = np.NAN # or use 0?

        if nindented > 0:
            features[10] = [0, 1][tab_indented / nindented > 0.5]
        else:
            features[10] = np.NAN # or use 0?

        featureExtractors.functionLength = fn_len
        return csr_matrix(features, shape=(1, nfeatures))

    @staticmethod
    def tokenLevel(tokens):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from token iterable"""
        nfeatures = len(featureExtractors.tokfeatureNames)
        features = np.zeros((nfeatures,), dtype=float)
        kword_dict = {k:0 for k in featureExtractors.keywords}

        par_stack = collections.deque()
        seen_control = False
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
            # number of literals
            kind = str(token.kind)
            features[n_kwords + 2] += [0, 1][kind == 'TokenKind.LITERAL']
            tok = token.spelling

            #print("{}".format(token))
            if tok in featureExtractors.keywords:
                kword_dict[tok] += 1
                if seen_control == False:
                    seen_control = True

            # ctrl nesting depth calculations
            if tok == "{":
                if seen_control:
                    par_stack.append(1)
                    if len(par_stack) == 0: # highest level of the ctrl stmt
                        depth_so_far += 1
            if tok == "}":
                if seen_control:
                    depth_so_far += par_stack.pop()
                if len(par_stack) <= 1: # nested stmt complete
                    nesting_depth = max(nesting_depth, depth_so_far)
                    depth_so_far = 0
                    seen_control = False

            # bracket nesting depth calculations
            if tok in brackets.values():      # opening brackets
                bracket_stack.append(token)
            if tok in brackets.keys():        # closing brackets
                # add valid bracket ordering check?
                if bracket_stack.pop() == brackets[tok]:
                    depth_so_far_brkt += 1
                if len(bracket_stack) == 0: # end of nesting
                    nesting_depth_brkt = max(nesting_depth_brkt, depth_so_far_brkt)
                    depth_so_far_brkt = 0

        ind = 0
        for kword in featureExtractors.keywords:
            try:
                features[ind] = np.log(kword_dict[kword] / \
                                featureExtractors.functionLength)
                # position of "count of unique keywords used" feature
                # use this or the token kind?
                features[n_kwords] += 1
            except RuntimeWarning: # cannot divide by 0
                features[ind] = np.NAN # use this or 0?
            ind += 1

        for i in range(3):
            ind = i + n_kwords
            try:
                features[ind] = np.log(features[ind] / \
                                featureExtractors.functionLength)
            except RuntimeWarning: # cannot divide by 0
                features[ind] = np.NAN # use this or 0?

        features[n_kwords + 3] = nesting_depth
        features[n_kwords + 4] = nesting_depth_brkt

        return csr_matrix(features, shape = (1, nfeatures))

    @staticmethod
    def astLevel(ast):
        """ Returns row vector scipy.sparse.csr_matrix of features extracted from ast"""
        return csr_matrix(0, shape = (1, 1))    #singleton 0 as default

'''
if __name__ == "__main__":

    tst = """#include <ctype.h>
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
}"""
    print(featureExtractors.charfeatureNames)
    print(featureExtractors.characterLevel(tst))

    filename = os.getcwd() + "/test.cpp"
    tokens = PPTools.Tokenize.cpp(filename)
    print(featureExtractors.tokfeatureNames)
    print(featureExtractors.tokenLevel(tokens))
'''