from itertools import *
from copy import deepcopy

def cut(g, nodes):
    for i in nodes:
        connections = g[i]
        for j in connections:
            g[j].remove(i)
        del g[i]
    return g

def check_bt(g, N):
    if len(g) == 1:
        return True
    for root in g.keys():
        if len(g[root]) == 2:
            q = []
            t = set([root])
            #root decided
            #print root, q, t
            q.extend(g[root])
            while len(q) > 0:
                #print q, t
                node = q.pop(0)
                t.add(node)
                if len(g[node]) != 3 and len(g[node]) != 1:
                    return False
                else:
                    q.extend(filter(lambda x: x not in t, g[node]))
            if len(t) == len(g):
                return True

    return False


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        answer = ""
        #data read
        N = int(fin.readline())
        g = dict()
        #print N
        for i in xrange(N-1):
            Xi, Yi = map(lambda x: int(x) - 1, fin.readline().strip().split(' '))
            if Xi not in g:
                g[Xi] = set([Yi])
            else:
                g[Xi].add(Yi)
            if Yi not in g:
                g[Yi] = set([Xi])
            else:
                g[Yi].add(Xi)
            #print Xi, Yi
        #print g
        for i in xrange(N):
            for indices in combinations(range(N), i):
                new_g = cut(deepcopy(g), indices)
                #print indices, new_g, check_bt(new_g, N)
                if check_bt(new_g, N):
                    answer = i
                    break
            if answer != "":
                break
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve("B-small-attempt0")