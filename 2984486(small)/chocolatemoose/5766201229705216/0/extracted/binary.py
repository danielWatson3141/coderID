import sys
from collections import defaultdict
from operator import itemgetter

def order_key(pair):
    return pair[1] - pair[0]

def get_weight(node,parent,edges):
#     print node, parent
    if len(edges[node]) == 1 and parent != -1:
        return 0,1
    elif (len(edges[node]) == 2 and parent != -1) or (parent == -1 and len(edges[node]) == 1):
        child = [neighbour for neighbour in edges[node] if neighbour != parent][0]
        score = get_weight(child,node,edges)[1]
        return score, score + 1
    else:
        neighbours = [get_weight(neighbour,node,edges) for neighbour in edges[node] if neighbour != parent]
#         print neighbours
        s_neigh = sorted(neighbours,key=order_key, reverse=True)
        return s_neigh[0][0]+s_neigh[1][0]+sum((s[1]) for s in s_neigh[2:]),sum((s[1]) for s in s_neigh)+1

# edges = defaultdict(set)
# edges[1].add(2)
# edges[2].add(1)
# edges[1].add(3)
# edges[3].add(1)
# edges[1].add(4)
# edges[4].add(1)
# edges[1].add(5)
# edges[5].add(1)
# edges[6].add(1)
# edges[1].add(6)
# edges[6].add(7)
# edges[7].add(6)
# 
# print get_weight(6, -1, edges)

with open(sys.argv[1]) as ff:
    t = int(ff.readline())
    for c in range(1,t+1):
        n = int(ff.readline())
        edges = defaultdict(set)
        for i in range(n-1):
            x,y = map(int,ff.readline().split())
            edges[x].add(y)
            edges[y].add(x)
#         if c == 2:
#             print get_weight(3, 1, edges)
#             for i in range(1,n+1):
#                 print get_weight(i,-1,edges)
        print "Case #%d: %d" % (c,min(get_weight(i,-1,edges)[0] for i in range(1,n+1)))
        