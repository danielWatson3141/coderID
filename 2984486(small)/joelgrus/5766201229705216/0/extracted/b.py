infile = "B-small-attempt4.in"
outfile = "B-small-4.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = []

for _ in range(num_cases):
    
    N = int(lines[0])
    edges = [[int(y) for y in x.split()] for x in lines[1:N]]
    lines = lines[N:]
    
    edge_counts = Counter(x for edge in edges for x in edge)
        
    case = N, edges
    
    cases.append(case)

from collections import deque    

# edges = [x.split() for x in """4 5
# 4 2
# 1 2
# 3 1
# 6 4
# 3 7""".split("\n")]

# edges = [map(int,x) for x in edges]

# tree = make_tree(7,edges,2)

# edges2 = [x.split() for x in """4 5
# 4 2
# 1 2
# 6 4""".split("\n")]

# for i in range(1,8):
    # #print i
    # tree = make_tree(7,edges,i)
    # #print num_to_remove(tree,i)
    # #print

def make_tree(N, edges, root):
    nodes = [None] + [[] for _ in range(N)]

    q = deque(edges)
    new_edges = []
    levels = { root : 0 }
    while len(q) > 0:
        ###print q, levels
        edge = q.popleft()
        a, b = edge
        if a in levels and b not in levels:
            levels[b] = levels[a] + 1
            new_edges.append((a,b))
            nodes[a].append(b)
        elif b in levels and a not in levels:
            levels[a] = levels[b] + 1
            new_edges.append((b,a))
            nodes[b].append(a)
        elif b in levels and a in levels:
            raise Exception("huh?")
        else:
            q.append(edge)

    return nodes

def is_full(tree):
    edge_counts = Counter(source for source, _ in tree)
    return all(x == 2 for x in edge_counts.values())

def num_to_remove(tree, root):
    #print root, tree
    ##print "root", root
    children = tree[root]
    ##print "children", children
    num_children = len(children)
    if num_children == 0:
        remove = 0
        remaining = 1
        result = remove, remaining
        #print root, result
        return result
    if num_children == 1:
        remove_children, remaining_children = num_to_remove(tree, children[0])
        remove = remove_children + remaining_children
        remaining = 1
        result = remove, remaining
        #print root, result
        return result
    if num_children == 2:
        ntr = [num_to_remove(tree, child) for child in children]
        remove = sum(x[0] for x in ntr)
        remaining = 1 + sum(x[1] for x in ntr)
        result = remove, remaining
        #print root, result
        return result
    ntr = [num_to_remove(tree, child) for child in children]
    ntr.sort(reverse=True, key=lambda pair: pair[1])
    #print "ntr", ntr
    remove = sum(x[0] + x[1] for x in ntr[2:]) + ntr[0][0] + ntr[1][0]
    remaining = 1 + ntr[0][1] + ntr[1][1]
    result = remove, remaining
    #print result
    return result
    

def process_case(case):
    ##print case
    N, edges = case
    
    ntr = min( num_to_remove(make_tree(N, edges,i), i) for i in range(1, N+1))
        
    return ntr[0]
        
def process_case_bad(case):
    
    ##print
    ##print case
    
    N, edges = case

    new_counts = Counter(x for edge in edges for x in edge)
    roots = [k for k,v in new_counts.items() if v == 2]
    
    for root in roots:
        tree = make_tree(edges, root)
        if is_full(tree):
            return 0    
    
    q = deque()
    
    q.append( (edges, set()) )
    
    while len(q) > 0:
        edges, nodes_deleted = q.popleft()
        ##print edges, nodes_deleted
        counts = Counter(x for edge in edges for x in edge)
        ##print "counts", counts

        for i in range(1, N + 1):
            if i not in nodes_deleted and counts[i] == 1:
                ##print
                ##print "trying to delete", i, "from", edges
                new_edges = [e for e in edges if i not in e]
                ##print "new edges", new_edges
                # the tree is empty
                if not new_edges:
                    continue
                    
                new_counts = Counter(x for edge in new_edges for x in edge)
                roots = [k for k,v in new_counts.items() if v == 2]
                
                for root in roots:
                    tree = make_tree(new_edges, root)
                    if is_full(tree):
                        ##print "FOUND IT!!!!!"
                        return len(nodes_deleted) + 1
                    
                new_nodes_deleted = set(nodes_deleted)
                new_nodes_deleted.add(i)
                
                q.append((new_edges, new_nodes_deleted))
                                
    return N
    
with open(outfile,"w") as g:
    
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + str(process_case(case)) + "\n")
    

