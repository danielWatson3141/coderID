import os.path
from clang import cindex
import PPTools
import numpy as np
from collections import Counter

class AST():

    def __init__(self):
        self.bigrams = Counter()      # Bigrams. Format: {(parent_type, child_type): frequency}
        self.type_depths = Counter()  # Format: {ASTNodeType: depths}
        self.node_types = []
        self.code_unigrams = []

        self.num_nodes = 0
        self.max_node_depth = 0
        self.avg_node_depth = 0
        self.INVALID_TYPE = str(cindex.TypeKind.INVALID)

    def node_to_unigram(self, node):
        # Drop 'CursorKind' from the node kind
        node_type = str(node.kind)
        ugram = [node_type.split(".")[1]]

        if 'TYPE' in node_type:
            ugram.append(node.displayname)

        return tuple(ugram)

    def traverse_parent(self, node, level = 0):
        self.num_nodes += 1
        self.avg_node_depth += level
        self.max_node_depth = max(self.max_node_depth, level)
        is_leaf = True

        node_type = str(node.kind)
        node_ugram = self.node_to_unigram(node)
        # create the text string here?
        self.node_types.append(node_type)
        for c in node.get_children():
            # if this loop is entered, this node cannot be a leaf
            if is_leaf:
                is_leaf = False

            self.bigrams[(node_ugram, self.node_to_unigram(c))] += 1
            print(c.kind, c.spelling)
            self.traverse_parent(c, level + 1)

        # non-terminal nodes that have a node type
        if not is_leaf and node_type != self.INVALID_TYPE:
            if node_type in self.type_depths:
                self.type_depths[node_type].append(level)
            else:
                self.type_depths[node_type] = [level]

        if is_leaf:
            self.code_unigrams += [x.spelling for x in node.get_tokens()]

    def traverse(self, node):
        self.traverse_parent(node)
        self.avg_node_depth /= self.num_nodes

        # Changing type_depths format to {ASTNodeType: max_depth}
        for node_type in self.type_depths:
            self.type_depths[node_type] = np.mean(self.type_depths[node_type])


"""
if __name__ == "__main__":
    os.environ["DYLD_LIBRARY_PATH"] = "/usr/local/Cellar/llvm/7.0.1/lib/"
    if not cindex.Config.loaded:
        cindex.Config.set_library_file(
            '/usr/local/Cellar/llvm/7.0.1/lib/libclang.dylib')

    filename = os.getcwd() + "/test.c"
    idx = cindex.Index.create()
    tu = idx.parse(filename, args=['-std=c++11'], options=0)

    ast = AST()
    ast.traverse(tu.cursor, 0)
    ast.calculate_depths()
"""
