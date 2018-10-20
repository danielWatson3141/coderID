import sys
import networkx as nx
import itertools as it

# braucht 4 minuten und ist inkorrekt

# open input files and read in into lines
filename = "input.txt"
inputFromFile=True
if inputFromFile: inp = open(filename)
else: inp=sys.stdin

# Precomputation

# solving a testcase
def solveTestCase(g,N):
    if isFullBinaryTree(g): return 0
    for r in range(N+1):
        for todelete in it.combinations(range(1,N+1),r):
            f=nx.Graph(g)
            for n in todelete: f.remove_node(n)
            if isFullBinaryTree(f): return r

def isFullBinaryTree(g):
    if(g.number_of_nodes() ==1): return True
    if(not nx.is_connected(g)): return False
    degrees = sorted(nx.degree(g).values())
    if(min(degrees)>=1 and max(degrees)<=3 and degrees.count(2)==1): return True
    return False

T =int(inp.readline())

for t in range(1,T+1):
    N=int(inp.readline())
    g=nx.Graph()
    g.add_nodes_from(range(1,N+1))
    for _ in range(N-1):
        x,y=[int(x) for x in inp.readline().split()]
        g.add_edge(x,y)
    print "Case #%d: %d"  % (t,solveTestCase(g,N))
