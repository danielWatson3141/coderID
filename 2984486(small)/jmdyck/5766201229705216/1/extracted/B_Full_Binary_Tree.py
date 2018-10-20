#!/usr/bin/python

import sys, pdb

sys.setrecursionlimit(3000)

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    return
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            mtrace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            mtrace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    adj = {}
    def add(x, y):
        if x not in adj: adj[x] = []
        adj[x].append(y)

    N = int(getline())
    for i in range(N-1):
        (x, y) = map(int, getline().split())
        add(x, y)
        add(y, x)

    def n_nodes_at_or_beyond(r, rparent):
        return 1 + sum(
            [ 
                n_nodes_at_or_beyond(node, r)
                for node in adj[r]
                if node != rparent
            ]
        )

    def n_nodes_to_delete_starting_at(r, rparent, level):
        # if case_num == 2 and i == 4:
        mtrace('  '*level, 'At', r)
        children = [ node for node in adj[r] if node != rparent ]
        n_children = len(children)
        mtrace('  '*level, "n_children=", n_children)
        if n_children == 0:
            mtrace('  '*level, "don't need to delete any!")
            res = 0
        elif n_children == 1:
            # We can't add children, so we have to delete this one AND all it leads to.
            mtrace('  '*level, "delete that only child and all its descendants")
            [child] = children
            res = n_nodes_at_or_beyond(child, r)
        elif n_children == 2:
            mtrace('  '*level, "delete whatever the two children need to delete")
            # but don't delete the children themeselves
            [child1, child2] = children
            res = (
                n_nodes_to_delete_starting_at(child1, r, level+1) 
                +
                n_nodes_to_delete_starting_at(child2, r, level+1)
            )
        elif n_children > 2:
            # We have to delete all but 2 children.
            mtrace('  '*level, "delete all but 2")
            # 
            # For 2 children, we will keep it, but make it be full:
            # each: n_nodes_to_delete_starting_at(child, r, level+1)
            #
            # and for n_children-2 children, we will delete it
            # each: n_nodes_at_or_beyond(child, r)
            #
            # How to choose the 2?
            #
            # Delete all, then reinstate the 2 that will un-delete the most.
            nd = 0
            n_reinstate = []
            for child in children:
                nd_if_kept = n_nodes_to_delete_starting_at(child, r, level+1)
                nd_if_deleted = n_nodes_at_or_beyond(child, r)

                nd += nd_if_deleted

                n_reinstate.append(nd_if_deleted - nd_if_kept)

            n_reinstate.sort()
            res = nd - n_reinstate[-1] - n_reinstate[-2]
        else:
            assert 0

        mtrace('  '*level, "n to delete =", res)
        return res

    min_n_to_delete = 2*N
    for i in range(1,N+1):
        mtrace('if', i, 'is the root...')
        n = n_nodes_to_delete_starting_at(i, None, 1)
        mtrace('we need to delete', n)
        if n < min_n_to_delete: min_n_to_delete = n

    assert min_n_to_delete < N

    print 'Case #%d: %s' % (case_num, min_n_to_delete)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
