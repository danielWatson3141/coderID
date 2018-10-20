#p2
import sys

def test(edges, root, notin):
    outedges = filter(lambda x: x != notin, edges[root])
    if len(outedges) < 2:
        return 1
    results = []
    for edge in outedges:
        results += [test(edges, edge, root)]
    results.sort()
    return 1 + results[-1] + results[-2]

lines = sys.stdin.readlines()
t = int(lines[0])
counter = 1
for ncase in range(t):
    n = int(lines[counter])
    counter += 1
    edges = [[] for i in range(n)]
    results = []
    for a in range(n-1):
        data = map(lambda x: int(x) - 1, lines[counter].split())
        counter+=1
        edges[data[0]] += [data[1]]
        edges[data[1]] += [data[0]]
    for i in range(n):
        results += [test(edges, i, n)]
    print "Case #%d:"%(ncase+1), n-max(results)
