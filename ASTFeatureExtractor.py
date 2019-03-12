import os.path
from clang import cindex
import numpy as np
from collections import Counter

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

        self.bigrams = Counter()      # Bigrams. Format: {(parent_type, child_type): frequency}
        self.type_depths = Counter()  # Format: {ASTNodeType: depths}
        self.node_types = []
        self.code_unigrams = []

        self.num_nodes = 0
        self.max_node_depth = 0
        self.avg_node_depth = 0

    def node_to_unigram(self, node):
        if node.data_type != "":
            return node.type + " " + node.data_type
        return node.type

    def traverse_parent(self, node, level = 0):
        self.num_nodes += 1
        self.avg_node_depth += level
        self.max_node_depth = max(self.max_node_depth, level)
        is_leaf = True

        node_type = node.type
        node_ugram = self.node_to_unigram(node)
        for c in node.get_children():
            self.node_types.append(node_type)
            # if this loop is entered, this node cannot be a leaf
            if is_leaf:
                is_leaf = False

            self.bigrams[(node_ugram, self.node_to_unigram(c))] += 1
            self.traverse_parent(c, level + 1)

        # non-terminal nodes
        if not is_leaf:
            if node_type in self.type_depths:
                self.type_depths[node_type].append(level)
            else:
                self.type_depths[node_type] = [level]

        """
        # Used for code in AST leaves features - not capturing all code for leaves
        if is_leaf:
            self.code_unigrams += [x.spelling for x in node.get_tokens()]
        """

    def traverse(self):
        self.traverse_parent(self.ast.head)
        self.avg_node_depth /= self.num_nodes

        # Changing type_depths format to {ASTNodeType: max_depth}
        for node_type in self.type_depths:
            self.type_depths[node_type] = np.mean(self.type_depths[node_type])


"""
if __name__ == "__main__":
    file = "test3.cpp"
    tokens = PPTools.Tokenize.tokenize(file)
    token_text = PPTools.Tokenize.tokensToText(tokens).split(" ")

    features = ASTFeatures(token_text)
    features.traverse()
    print(features.node_types)
"""