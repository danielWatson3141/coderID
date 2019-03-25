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
        print(" | ".join([node.type, node.spelling, node.data_type]))
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
            "]": "[",
            "break": "start"
        }
        return matches[end]

    def is_valid_naming(self, name):
        """
        Checks if name is a valid user-defined function/variable name in C++
        :param name: String. Function/var name
        :return: Boolean
        """
        if not name.isalnum(): # underscore/special chars in name
            return all(x.isalnum() for x in name.split("_"))
        return True

    def parse_decl_specifiers(self, tokens):
        decl = Node(node_type="Declarator")
        curr_parent_type = "Declaration-Specifiers"
        curr_parent_node = Node(curr_parent_type)

        base_data_type_seen = deque()  # using a stack to account for multi-word base return types, e.g. long int
        temp_stack = deque()
        prev_token = ""
        ind = -1

        for token in tokens:
            ind += 1
            if self.is_base_data_type(token):
                base_data_type_seen.append(token)
                continue

            if len(base_data_type_seen) >= 1:  # encountered a non-base type
                # after some base types
                data_type = " ".join(base_data_type_seen)
                base_data_type_seen = deque()
                if data_type == "const":
                    token = data_type + " " + token # next token must be a type
                else:
                    if token in ["*", "&"]: # refs and pointers
                        prev_token = token
                        temp_stack.append(data_type + token)
                        continue
                    temp_stack.append(data_type)


            if self.is_decl_specifier(token):
                curr_parent_node.add_child(Node("Decl-Specifier", spelling=token))
            elif token == "(" and self.head.spelling == "": # start of the argument list
                fn_name = temp_stack.pop()
                if not fn_name[0].isalpha():  # not a valid function name
                    raise Exception("Ill-defined function - invalid function naming/typing.")
                self.head.set_spelling(fn_name)

                # accounts for no return type provided (old ANSI-C-allowed format)
                if len(temp_stack) == 1: # returns error if not valid fn
                    fn_type = temp_stack.pop()
                    if not fn_type[0].isalpha():  # not a valid function name
                        raise Exception("Ill-defined function - invalid function naming/typing.")
                    self.head.set_data_type(fn_type)
                else:
                    if len(temp_stack) > 0: # more elements past function name and type
                        raise Exception("Ill-defined function - invalid function naming/typing.")

                decl.add_child(curr_parent_node)  # no more declaration specifiers
                self.head.add_child(decl)
                return ind # index of opening bracket for args

            elif (not self.is_valid_naming(token)) or (not self.is_valid_naming(prev_token)): # special chars
                if prev_token not in ["&", "*", ""]:
                    temp_stack.append(temp_stack.pop() + token)
                else:
                    temp_stack.append(token)
            else:
                temp_stack.append(token) # not a declaration specifier - either return type or function name

            prev_token = token


    def parse_args(self, tokens, index):
        decl = self.head.get_children()[0]
        curr_parent_type = "Argument-List"
        curr_parent_node = Node(curr_parent_type)

        base_data_type_seen = deque()  # using a stack to account for
        # multi-word base return types, e.g. long int
        temp_stack = deque() # store args seen so far
        openers_seen = 0 # opening brackets seen so far
        prev_token = "("
        default_arg = False
        ind = index - 1

        if tokens[index] != "(": # function name parsing failed
            raise Exception("Ill-defined function - invalid function naming/typing.")

        for token in tokens[index:]:
            ind += 1
            if self.is_base_data_type(token):
                base_data_type_seen.append(token)
                continue

            if len(base_data_type_seen) >= 1:  # encountered a non-base type
                # after some base types
                data_type = " ".join(base_data_type_seen)
                base_data_type_seen = deque()
                if data_type == "const":
                    token = data_type + " " + token # next token must be a type
                else:
                    if token in ["*", "&"]: # refs and pointers
                        prev_token = token
                        temp_stack.append(data_type + token)
                        continue
                    temp_stack.append(data_type)

            if default_arg == True:
                if token == "(":
                    openers_seen += 1
                    continue
                elif token in [")", ","]: # next argument/end of arg list encountered
                    if openers_seen == 1: # encountered fn call in default arg value
                        default_arg = False
                    else:
                        if token == ")":
                            openers_seen -= 1
                        continue
                else:
                    continue # skip over default argument values
            else:
                if token == "=":
                    default_arg = True
                    continue

            if token == "(":
                openers_seen += 1
                temp_stack.append(token)

            elif token == ")":  # end of argument list
                opening = self.get_matching(token)
                tmp = temp_stack.pop()
                if tmp == opening: # no args, we're done
                    break
                else: # create the last argument node
                    try:
                        arg_name = tmp
                        arg_type = temp_stack.pop()

                        if not arg_name[0].isalpha():  # not a valid argument name/type
                            raise Exception("Ill-defined function - invalid arguments.")

                        if arg_type == "(" or type(arg_type) != str: # no identifier for the arg
                            temp_stack.append(arg_type)
                            arg_type = "No-Identifier " + arg_name
                            arg_name = ""

                        tmp_node = Node("Argument", arg_name, arg_type)
                        #curr_parent_node.add_child(tmp_node)
                        #decl.add_child(curr_parent_node)
                        temp_stack.append(tmp_node)
                    except:
                        raise Exception("Ill-defined function - invalid arguments.")

                children = []
                while True:
                    tmp = temp_stack.pop()
                    if tmp == opening:
                        curr_parent_node.children += children
                        break
                    children.append(tmp)
                break

            elif token == ",":
                try:
                    arg_name = temp_stack.pop()
                    arg_type = temp_stack.pop()

                    if not arg_name[0].isalpha(): # not a valid argument name
                        raise Exception("Ill-defined function - invalid arguments.")

                    if arg_type == "(" or type(arg_type) != str:  # no identifier for the arg
                        temp_stack.append(arg_type)
                        arg_type = "No-Identifier " + arg_name
                        arg_name = ""

                    tmp_node = Node("Argument", arg_name, arg_type)
                    # curr_parent_node.add_child(tmp_node)
                    # decl.add_child(curr_parent_node)
                    temp_stack.append(tmp_node)
                except:
                    raise Exception("Ill-defined function - invalid arguments.")

            elif (not self.is_valid_naming(token)) or (not self.is_valid_naming(prev_token)): # special
                if prev_token not in ["(", ",", "&", "*"]:
                    """
                    print(prev_token)
                    new_val = temp_stack.pop() + token
                    print("Prev token: " + prev_token + " , " + "Token: " + token)
                    print(new_val)
                    print("===========================================================")
                    temp_stack.append(new_val)
                    """
                    temp_stack.append(temp_stack.pop() + token)
                else:
                    temp_stack.append(token)
            else:
                temp_stack.append(token)

            prev_token = token

        decl.add_child(curr_parent_node)
        return ind + 1 # index of opening bracket for fn defintion


    def parse_fn_body(self, tokens, index):
        fn_body = Node(node_type="Function-Body")

        curr_parent_type = "Declaration-Specifiers"
        curr_parent_node = Node(curr_parent_type)

        base_data_type_seen = deque()  # using a stack to account for
        # multi-word base return types, e.g. long int
        node_stack = deque()  # tracking statements in the function body
        temp_stack = deque()
        case_stack = deque()  # tracking cases seen

        prev_token = ""

        if tokens[index] != "{": # arg list parsing failed
            raise Exception("Ill-defined function - invalid arguments.")

        for token in tokens[index:]:
            if self.is_base_data_type(token):
                base_data_type_seen.append(token)
                prev_token = token
                continue

            if len(base_data_type_seen) >= 1:  # encountered a non-base type
                # after some base types
                data_type = " ".join(base_data_type_seen)
                base_data_type_seen = deque()
                if token in ["*", "&"]: # refs and pointers
                    prev_token = token
                    temp_stack.append(data_type + token)
                    continue
                temp_stack.append(data_type)

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
            elif token == "continue":
                node_stack.append(Node("Continue-Statement"))
            elif token == "goto":
                node_stack.append(Node("Goto-Statement"))
            elif token == "switch":
                node_stack.append(Node("Switch-Statement"))
            elif token == "return":
                node_stack.append(Node("Return-Statement"))
            elif token == "break":
                node_stack.append(Node("Break-Statement"))
            elif token == "try":
                node_stack.append(Node("Try-Statement"))
            elif token == "catch":
                node_stack.append(Node("Catch-Statement"))
            elif token == "{":  # contents of branching statements
                node_stack.append(token)

            elif token == "case" or (
                    token == "default" and len(case_stack) > 0):
                if len(case_stack) > 0:  # did not encounter a case
                    # statement before this
                    case_stack.pop()
                    opening = "start"
                    children = []
                    while True:
                        tmp = node_stack.pop()
                        if tmp == opening:
                            parent_node = node_stack.pop()
                            parent_node.children += children
                            node_stack.append(parent_node)
                            break
                        else:
                            children.append(tmp)
                node_stack.append(Node("Case-Statement"))
                node_stack.append("start")
                case_stack.append(True)

            elif token == "}":
                opening = self.get_matching(token)
                children = []
                while True:
                    tmp = node_stack.pop()
                    if tmp == opening:
                        if len(node_stack) > 0:  # not the function
                            # closing bracket
                            parent_node = node_stack.pop()
                            parent_node.children += children
                            if parent_node.type == "Catch-Statement":  #
                                # catch statements are children of the
                                # original try statement
                                try_node = node_stack.pop()
                                try_node.add_child(parent_node)
                                parent_node = try_node
                            node_stack.append(parent_node)
                        else:  # end of function
                            fn_body.children += children  # top-level
                            # statements are the function body children
                        break
                    elif tmp == "start":
                        parent_node = node_stack.pop()  # the last case
                        # statement in a switch-case statement
                        parent_node.children += children
                        node_stack.append(parent_node)
                    else:
                        children.append(tmp)

            elif token in ["=", "->"]:
                if len(temp_stack) > 0:  # variables - captures base
                    # type variables
                    tmp_node = Node("Variable")
                    tmp_node.set_spelling(prev_token)
                    tmp_node.set_data_type(temp_stack.pop())
                    node_stack.append(tmp_node)
                else:  # treat as assignment and not new variable
                    node_stack.append(Node("AssignmentStatement", prev_token))
            else:
                pass

            prev_token = token

        if len(fn_body.children) > 0:
            self.head.add_child(fn_body)


    def parse_function(self, tokens):
        args_ind = self.parse_decl_specifiers(tokens)
        #self.traverse(self.head)
        fn_body_ind = self.parse_args(tokens, args_ind)
        #self.traverse(self.head)
        self.parse_fn_body(tokens, fn_body_ind)


"""
if __name__ == "__main__":
    file = "test2.cpp"
    tu_str = PPTools.Tokenize.tokenize(file)
    #print(PPTools.Tokenize.tokensToText(tu_str))
    tree = ASTree()
    tokenStrings = PPTools.Tokenize.tokensToText(tu_str,
                                                 ignore_comments=True).split(" ")
    tree.parse_function(tokenStrings)
    print("Node Type | Spelling | Data Type")
    tree.traverse(tree.head)
"""
