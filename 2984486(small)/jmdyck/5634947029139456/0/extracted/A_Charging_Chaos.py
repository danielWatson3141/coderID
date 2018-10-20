#!/usr/bin/python

import sys

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

    (N,L) = map(int, getline().split())
    initial_flows = getline().split()
    required_flows = getline().split()
    assert len(initial_flows) == N
    assert len(required_flows) == N
    for i in range(N):
        len(initial_flows[i]) == L
        len(required_flows[i]) == L

    # brute force:

    candidates = []
    f = "{0:0%db}" % L
    for i in range(pow(2,L)):
        switches = f.format(i)
        n_flips = switches.count('1')
        # mtrace(switches, n_flips)
        candidates.append( (n_flips, switches) )
    candidates.sort()

    for (n_flips, switches) in candidates:
        # Does 'switches' work?
        mtrace('    considering', switches)
        current_flows = initial_flows[:]
        mtrace('        current_flows:', ' '.join(current_flows))
        for i in range(L):
            if switches[i] == '0':
                # Leave bit i as-is.
                mtrace('        bit %s: leave as-is' % i)
                pass
            elif switches[i] == '1':
                # Flip bit i in the flow of each outlet
                mtrace('        bit %s: flip!' % i)
                current_flows = [
                    flow[0:i]
                    +
                    ('0' if flow[i] == '1' else '1')
                    +
                    flow[i+1:]
                    for flow in current_flows
                ]
                mtrace('        current_flows:', ' '.join(current_flows))
            else:
                assert 0
        if sorted(current_flows) == sorted(required_flows):
            mtrace('        success!')
            min_n_flips = n_flips
            break
    else:
        min_n_flips = "NOT POSSIBLE"

    print 'Case #%d: %s' % (case_num, min_n_flips)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
