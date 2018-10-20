'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
import os
import collections

if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)

def main():
    problem_input = sys.stdin
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
        if os.path.isfile(input_file):
            problem_input = open(input_file)
        
    cases = int(problem_input.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case(problem_input)
        print "Case #%s: %s" % (case + 1, resp,)
            
def run_case(problem_input):
    vecinos = collections.defaultdict(list)
    n = int(problem_input.readline())
    for _i in xrange(n - 1):
        a,b = (int(x) for x in problem_input.readline().split())
        vecinos[a].append(b)
        vecinos[b].append(a)
        
    max_value = max(_tree_value(_make_tree(vecinos, node), node) for node in xrange(1, n + 1))
    return n - max_value
        

def _tree_value(tree, node):
    childs = tree[node]
    num_childs = len(childs) 
    if num_childs == 0:
        return 1
    elif num_childs == 1:
        return 1
    else:
        return 1 + sum(sorted((_tree_value(tree, c) for c in childs), reverse=True)[:2])

def _make_tree(vecinos, root):
    done = set()
    tree = collections.defaultdict(list)
    def _add(node):
        done.add(node)
        for child in vecinos[node]:
            if child in done:
                continue
            tree[node].append(child)
            _add(child)
    _add(root)
    return tree
            

if __name__ == "__main__":
    main()
