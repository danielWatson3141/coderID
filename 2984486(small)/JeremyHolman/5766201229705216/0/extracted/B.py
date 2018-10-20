# GCJ 2014 Round 1A, Problem B, Jeremy Holman

import sys

DEBUG = False

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        N = int(sys.stdin.readline().strip())
        G = dict((i+1, []) for i in range(N))
        for j in xrange(1, N):
            x, y = map(int, sys.stdin.readline().strip().split(" "))
            G[x].append(y)
            G[y].append(x)

        if DEBUG:
            print "TESTING FOR CASE ", i
            for j in range(1, N+1):
                blah = do_counts(G, j, None)
                print j, blah


        if not DEBUG:
            counts = map(lambda x: do_counts(G, x, None)[1], xrange(1, N+1))
            answer = min(counts)
            print "Case #%d:" % (i+1),
            print answer


def do_counts(G, curr, parent):
    if DEBUG: print "    dc(%s, %s)" % (curr, parent)
    children = G[curr][:]
    if parent is not None:
        children.remove(parent)
    numchildren = len(children)

    if numchildren == 0:
        if DEBUG: print "                  returning", 1, 0
        return 1, 0
    elif numchildren == 1:
        ckill, cprune = do_counts(G, children[0], curr)
        if DEBUG: print "                  returning", ckill+1, ckill
        return ckill+1, ckill
    elif numchildren == 2:
        ckill1, cprune1 = do_counts(G, children[0], curr)
        ckill2, cprune2 = do_counts(G, children[1], curr)
        if DEBUG: print "                  returning", ckill1+ckill2+1, cprune1+cprune2
        return ckill1+ckill2+1, cprune1+cprune2
        
    if DEBUG: print "       hard part for ", curr, parent

    counts = []
    for child in children:
        kill, prune = do_counts(G, child, curr)
        counts.append([kill, prune])

    sum_kills = sum(zip(*counts)[0])
    if DEBUG: print "       counts = ", counts
    if DEBUG: print "       sum_kills = ", sum_kills
    maxdelta = 0
    for i in xrange(numchildren):
        for j in xrange(i+1, numchildren):
            delta = counts[i][0] + counts[j][0] - counts[i][1] - counts[j][1]
            if delta > maxdelta:
                if DEBUG: print "         %d > %d when %d,%d" % (delta, maxdelta, i, j)
                maxdelta = delta
    if DEBUG: print "       maxdelta = ", maxdelta
    if DEBUG: print "                  returning", sum_kills + 1, sum_kills - delta
    return sum_kills + 1, sum_kills - maxdelta

#    counts.sort(key = lambda x: x[2])                           # sort in order of ease-to-prune
#    child_2_prunes_sum = counts[0][2] + counts[1][2]            # how easy to prune easiest-to-prune
#    child_2_kills_sum = counts[0][1] + counts[1][1]             # how easy to kill easiest-to-prune
#    child_else_kills_sum = sum(map(lambda x: x[1], counts[2:])) # how easy to kill others
#
#    total_kill = child_2_kills_sum + child_else_kills_sum + 1   # if we kill all (and kill current)
#    total_prune = child_2_prunes_sum + child_else_kills_sum     # if we prune 2 and kill rest
#    return total_kill, total_prune


main()
