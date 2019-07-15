import os.path
from clang import cindex
import numpy as np
from collections import Counter
from scipy.sparse import csr_matrix

import PPTools
import AbstractSyntaxTree

class ASTFeatures:
    """
    Cause of missing function bodies: function return type is not a simple C++
    data type / is from a user-defined module
    Possible solutions:
        - create AST for entire repo, and store the function decl nodes, using the context(?)
          to match it to each author's functions
        - for each function string, check if it's a function being defined outside of its class using the
            scope resolution operator. If true, drop the
    """
    def __init__(self, token_text):
        self.ast = AbstractSyntaxTree.ASTree()
        self.ast.lexer(token_text)

        self.bigrams_text = ""           # Bigrams. Format: {(parent_type, child_type): frequency}
        self.type_depths = Counter()     # Format: {ASTNodeType: depths}
        self.code_unigrams = []
        self.node_types = []
        self.depths = None

        self.num_nodes = 0
        self.max_node_depth = 0
        self.avg_node_depth = 0

    def node_to_unigram(self, node):
        if node.data_type != "":
            return node.type + " " + node.data_type
        return node.type

    def traverse_parent(self, node, ancestors, level = 0):
        self.num_nodes += 1
        self.avg_node_depth += level
        self.max_node_depth = max(self.max_node_depth, level)
        is_leaf = True

        node_type = node.type
        node_ugram = self.node_to_unigram(node)
        all_ancestors = ancestors + [node_ugram]

        for c in node.get_children():
            # if this loop is entered, this node cannot be a leaf
            if is_leaf:
                is_leaf = False

            #self.bigrams[(node_ugram, self.node_to_unigram(c))] += 1
            curr_ugram = self.node_to_unigram(c)
            for ugram in all_ancestors:
                self.bigrams_text += ugram + "," + curr_ugram + ";"
            self.traverse_parent(c, all_ancestors, level + 1)

        # non-terminal nodes
        if not is_leaf:
            self.node_types.append(node_type)
            type_depth_name = node_type + "_avg_depth"
            if type_depth_name in self.type_depths:
                self.type_depths[type_depth_name].append(level)
            else:
                self.type_depths[type_depth_name] = [level]

        """
        # Used for code in AST leaves features - not capturing all code for leaves
        if is_leaf:
            self.code_unigrams += [x.spelling for x in node.get_tokens()]
        """

    def traverse(self):
        self.traverse_parent(self.ast.head, [])
        self.avg_node_depth /= self.num_nodes

        # Changing type_depths format to {ASTNodeType: max_depth}
        for node_type in self.type_depths:
            self.type_depths[node_type] = np.mean(self.type_depths[node_type])

        # Reformatting the data values
        # drop the last semi-colon to avoid generating an empty string as a token
        self.bigrams_text = self.bigrams_text[:-1]
        self.node_types = " ".join(self.node_types)
        self.depths = csr_matrix([self.max_node_depth, self.avg_node_depth], shape=(1, 2))


if __name__ == "__main__":
    fns_seen = 3
    ast_feature_ext = {'p': 2, 'e': 3}
    #node_type_depths = {'p': [2] * fns_seen, 'e': [5] * fns_seen}
    node_type_depths = {'p': [0, 1, 2], 'd': [3, 2, 1]}

    for node_type in ast_feature_ext:
        if node_type not in node_type_depths:
            node_type_depths[node_type] = [0.0] * fns_seen
        node_type_depths[node_type].append(ast_feature_ext[node_type])

    # Updating the node types that were not seen in this function but were
    # seen before
    for node_type in node_type_depths:
        if node_type not in ast_feature_ext:
            node_type_depths[node_type].append(0.0)

    print(node_type_depths)


