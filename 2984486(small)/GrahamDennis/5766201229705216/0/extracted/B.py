#!/usr/bin/env python

import sys
from heapq import heappush, heappop, heappushpop

def main(argv):
    f = open(argv[1])
    
    T = int(f.readline())
    
    for t in xrange(T):
        print "Case #%i: %s" % (t+1, solve(f))


def solve(f):
    N = int(f.readline())
    
    edges = [map(int, f.readline().split()) for _ in xrange(N-1)]
    
    graph = {}
    for src, dst in edges:
        graph.setdefault(src, set()).add(dst)
        graph.setdefault(dst, set()).add(src)
    
    dp = {}
    
    def best_tree_from_root_excluding_node(root, exclude):
        result = dp.get((root, exclude))
        if result is not None: return result
        
        result = 1
        
        results = []
        
        for target in graph[root]:
            if target == exclude: continue
            results.append(best_tree_from_root_excluding_node(target, root))
        
        results.sort()
        
        if len(results) >= 2:
            result = results[-2] + results[-1] + 1
        
        dp[(root, exclude)] = result
        
        return result
    
    max_tree_size = 1
    
    for root in xrange(1, N+1):
        max_tree_size = max(max_tree_size, best_tree_from_root_excluding_node(root, None))
    
    return N - max_tree_size


if __name__ == "__main__":
    sys.exit(main(sys.argv))
