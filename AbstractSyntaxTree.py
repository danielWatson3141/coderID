import re
import json
import PPTools
from collections import deque

with open("grammar.json", 'r') as f:
    GRAMMAR = json.load(f)

class Node:
    # implemention of an AST node
    def __init__(self, node_type, spelling = "", data_type = ""):
        # for function declaration, spelling is function name, data_type is return type
        self.spelling = spelling # the portion of code that the node was created from
        self.type = node_type
        self.data_type = data_type
        self.children = []

        # Type-specific features
        self.var_type = data_type

    def set_spelling(self, spelling):
        self.spelling = spelling

    def set_data_type(self, data_type):
        self.data_type = data_type

    def add_child(self, child):
        self.children.append(child)

    def get_children(self):
        return self.children


class ASTree:
    # implemention of an Abstract Syntax Tree
    def __init__(self):
        self.head = Node("Function")

    def traverse(self, node):
        if node is None:
            return None
        print("|".join([node.type, node.spelling, node.data_type]))
        for c in node.children:
            self.traverse(c)

    def is_decl_specifier(self, token):
        if token in GRAMMAR['Declarator']['Decl-Specifier']:
            return True

    def is_base_data_type(self, token):
        if token in GRAMMAR['Type-Specifier']['Simple-Type']:
            return True

    def get_matching(self, end):
        matches = {
            ")": "(",
            "}": "{",
            "]": "["
        }
        return matches[end]


    def lexer(self, tokens):
        decl= Node(node_type="Declarator")
        fn_body = Node(node_type="Function-Body")

        curr_parent_type = "Declaration-Specifiers"
        curr_parent_node = Node(curr_parent_type)

        base_data_type_seen = deque()  # using a stack to account for multi-word base return types, e.g. long int
        node_stack = deque() # tracking statements in the function body
        temp_stack = deque()

        prev_token = ""

        for token in tokens:

            if self.is_base_data_type(token):
                base_data_type_seen.append(token)
                continue

            if len(base_data_type_seen) > 0:
                data_type = " ".join(base_data_type_seen)
                base_data_type_seen = deque()
                temp_stack.append(data_type)

            if curr_parent_type == "Declaration-Specifiers":
                if self.is_decl_specifier(token):
                    curr_parent_node.add_child(Node("Decl-Specifier", spelling=token))
                elif token == "(": # start of the argument list
                    # set function details
                    self.head.set_spelling(temp_stack.pop())
                    self.head.set_data_type(temp_stack.pop())

                    decl.add_child(curr_parent_node)  # no more declaration specifiers
                    curr_parent_type = "Argument-List"
                    curr_parent_node = Node(curr_parent_type)
                elif token == "::" or prev_token == "::":  # TODO: account for pointers, references (&), i.e. custom classes
                    temp_stack.append(temp_stack.pop() + token)
                else:
                    temp_stack.append(token) # not a declaration specifier - either return type or function name

            elif curr_parent_type == "Argument-List":
                if token == ")": # end of argument list
                    # TODO: custom data types/pointers/references need to be accounted for string join?
                    tmp_node = Node("Argument", temp_stack.pop(), temp_stack.pop())
                    curr_parent_node.add_child(tmp_node)
                    decl.add_child(curr_parent_node)

                    curr_parent_type = "" # reset the parent node
                    curr_parent_node = None

                elif token == ",":
                    # TODO: custom data types/pointers/references need to be
                    # accounted for string join?
                    tmp_node = Node("Argument", temp_stack.pop(), temp_stack.pop())
                    curr_parent_node.add_child(tmp_node)
                else:
                    temp_stack.append(token)

            else:
                # branching statements
                # TODO: these could be added to the grammar JSON file and reduced to one check
                if prev_token == "else" and token == "if":
                    node_stack.append(Node("Else-If-Statement"))
                elif token == "if":
                    node_stack.append(Node("If-Statement"))
                elif token == "else":
                    node_stack.append(Node("Else-Statement"))
                elif token == "while":
                    node_stack.append(Node("While-Statement"))
                elif token == "for":
                    node_stack.append(Node("For-Statement"))
                elif token == "return":
                    node_stack.append(Node("Return-Statement"))
                elif token == "break":
                    node_stack.append(Node("Break-Statement"))
                elif token == "continue":
                    node_stack.append(Node("Continue-Statement"))
                elif token == "goto":
                    node_stack.append(Node("Goto-Statement"))
                elif token == "{": # contents of branching statements
                    node_stack.append(token)
                elif token == "}":
                    opening = self.get_matching(token)
                    children = []
                    while True:
                        tmp = node_stack.pop()
                        if tmp == opening:
                            if len(node_stack) > 0:  # not the function closing bracket
                                parent_node = node_stack.pop()
                                parent_node.children += children
                                node_stack.append(parent_node)
                            else:  # end of function
                                fn_body.children += children # top-level statements are the function body children
                            break
                        else:
                            children.append(tmp)

                elif token == "=":
                    if len(temp_stack) > 0: # variables - captures base type variables
                        tmp_node = Node("Variable")
                        tmp_node.set_spelling(prev_token)
                        tmp_node.set_data_type(temp_stack.pop())
                        node_stack.append(tmp_node)
                    else: # treat as assignment and not new variable
                        node_stack.append(Node("AssignmentStatement"))
                else:
                    pass

            prev_token = token

        self.head.add_child(decl)
        self.head.add_child(fn_body)

"""
if __name__ == "__main__":
    file = "test3.cpp"
    tu_str = PPTools.Tokenize.tokenize(file)
    tree = ASTree()
    tokenStrings = PPTools.Tokenize.tokensToText(tu_str).split(" ")
    tree.lexer(tokenStrings)
    print("Node Type | Spelling | Data Type")
    tree.traverse(tree.head)
"""
