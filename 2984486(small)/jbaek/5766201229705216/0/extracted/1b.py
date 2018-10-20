from math import *
from itertools import *
from Queue import *
from collections import *
from copy import copy


# general helper functions

def split_to_int(f):
    return [int(v) for v in f.next().split()]

def split_to_float(f):
    return [float(v) for v in f.next().split()]

def split_to_str(f):
    return [str(v) for v in f.next().split()]

def factors(n):
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


def flip(st):
    l = list(st)
    for i in range(len(l)):
        if l[i] == '1':
            l[i] == '0'
        else:
            l[i] == '1'
    return ''.join(l)

def solve(tree, N):
    if is_binary(tree, N):
        return 0
    for i in range(1, N-1):
        for com in combinations(range(1, N+1), i):
            comb = set(com)
            new_tree = {}
            for k, v in tree.iteritems():
                if k not in comb:
                    new_tree[k] = [node for node in v if node not in comb]
            if is_binary(new_tree, N):
                return i
    return N-1

def is_binary(tree, N):
    roots = []
    for k, v in tree.iteritems():
        roots.append(k)
    for root in roots:
        set_nodes = set(roots)
        if len(tree[root]) != 2:
            continue
        else:
            # bfs
            set_nodes.remove(root)
            children = tree[root]
            parents = set([root])
            new_children = set([])
            cont = True
            while children and cont:
                new_children = set([])
                for child in children:
                    # if child not in set_nodes:
                    #     print 'child not in set_nodes', set_nodes, child
                    #     print 'tree', tree
                    #     cont = False
                    #     break
                    set_nodes.remove(child)
                    children_children = [c for c in tree[child] if c not in parents]
                    if len(children_children) == 0:
                        continue
                    if len(children_children) != 2:
                        cont = False
                        break
                    for c in children_children:
                        new_children.add(c)
                parents = children
                children = new_children
            if cont:
                return len(set_nodes) == 0
    return False


# problem
def main():

    with open("/Users/jackiebaek/Dropbox/Documents/Programs/Codejam/2014/Round 1A/in2.in") as f:
        cases = int(f.next())
        for i in range(cases):
            print "Case #%d:" % (i+1),
            N = split_to_int(f)[0]
            tree = defaultdict(set)
            for i in range(N-1):
                X, Y = split_to_int(f)
                tree[X].add(Y)
                tree[Y].add(X)
            print solve(tree, N)

            

main()
