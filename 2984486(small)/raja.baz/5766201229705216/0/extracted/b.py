from itertools import combinations

def build_graph(edges):
    graph = {}
    for a,b in edges:
        if a not in graph:
            graph[a] = set()
        if b not in graph:
            graph[b] = set()
        graph[a].add(b)
        graph[b].add(a)
    return graph

# def leaf_nodes(graph):
#     return set(n for n,c in graph.items() if len(c) == 1)
    
# def solve(edges):
#     g = build_graph(edges)
#     removed_count = 0
#     while True:
#         leaves = leaf_nodes(g)
#         if len(leaves) == 0:
#             return removed_count
#         leaf_links = set()
#         for l in leaves:
#             a = list(g[l])[0]
#             leaf_links.add(a)
            
#         to_remove = set()
#         for n in leaf_links:
#             c = len(g[n])
#             if c == 1:
#                 to_remove |= g[n]
#             elif c > 2:
#                 removable = g[n] & leaves
#                 to_remove |= set(list(removable)[:c-2])
#         if len(to_remove) == 0:
#             for l in leaves:
#                 for n in g[l]:
#                     g[n].remove(l)
#                 del(g[l])
#         else:
#             print g
#             print leaves
#             print leaf_links
#             print to_remove
#             print ""
#             removed_count += len(to_remove)
#             for l in to_remove:
#                 for n in g[l]:
#                     g[n].remove(l)
#                 del(g[l])

def num_nodes(r, g, f):
    n = 0
    edges = g[r] - set([f])
    n += len(edges)
    for e in edges:
        n += num_nodes(e,g,r)
    return n

def num_to_remove(r, g, f=None):
    edges = g[r]
    if f is not None:
        edges = edges - set([f])
        
    if len(edges) == 0:
        return 0
        
    if len(edges) == 1:
        return num_nodes(list(edges)[0], g, r)+1

    if len(edges) == 2:
        to_remove = 0
        for e in edges:
            to_remove += num_to_remove(e, g, r)
        return to_remove

    minr = None
    for c in combinations(edges, 2):
        c = set(c)
        to_remove = 0
        for e in c:
            to_remove += num_to_remove(e, g, r)
        for e in edges-c:
            to_remove += num_nodes(e, g, r)+1
        if minr is None or to_remove < minr:
            minr = to_remove
    return minr
    
    

def solve(edges):
    g = build_graph(edges)
    possible_roots = set(a for a,e in g.items() if len(e) >= 2)
    min_to_remove = None
    for r in possible_roots:
        t = num_to_remove(r,g)
        if min_to_remove is None or t < min_to_remove:
            min_to_remove = t
    if min_to_remove is None:
        return len(edges)
    return min_to_remove
                
            

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(1,T+1):
        N = int(raw_input())
        edges = [map(int, raw_input().split()) for j in range(N-1)]
        print "Case #%d: %d" % (i, solve(edges))
            
    
