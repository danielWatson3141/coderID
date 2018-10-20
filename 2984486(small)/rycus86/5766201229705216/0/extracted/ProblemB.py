SIZE    = 'small'
INPUT   = 'b-' + SIZE + '.in'
OUTPUT  = 'b-' + SIZE + '.out'

DATASET = []
RESULT  = []

import itertools

def read_input():
    with open(INPUT) as infile:
        T = int( infile.readline() )
        for t in xrange(T):  # @UnusedVariable
            N = int( infile.readline() )
            
            edges = []
            for n in xrange(N-1):  # @UnusedVariable
                edge = tuple(sorted( int(e) for e in infile.readline().split() ))
                edges.append(edge)
                
            DATASET.append(edges)

def write_result():
    C = 0
    with open(OUTPUT, 'w') as outfile:
        for r, minroot in RESULT:
            C = C + 1
            rline = 'Case #%d: %d' % (C, r)
            
            print rline
            outfile.write(rline)
            outfile.write('\n')

class Node(object):
    
    def __init__(self, V):
        self.V = V
        self.N = []
    
    def _add_nb(self, n):
        self.N.append(n)
        
    def add_neighbour(self, n):
        self._add_nb(n)
        n._add_nb(self)
    
    def __repr__(self):
        r = 'Node(' + str(self.V) + '): ['
        for n in self.N:
            r = r + str(n.V) + ','
        r = r[:-1]
        r = r + ']'
        return r

def solve():
    for edges in DATASET:
        nodes = {}
        
        for A, B in edges:
            if A in nodes:
                NA = nodes[A]
            else:
                NA = Node(A)
                nodes[A] = NA
            
            if B in nodes:
                NB = nodes[B]
            else:
                NB = Node(B)
                nodes[B] = NB
                
            NA.add_neighbour(NB)
        
        R, minroot = walk(nodes)
        RESULT.append( (R, minroot) )
        
def walk(nodes):
    min = None
    minroot = None
    
    for ni in nodes:
        visited = []
        
        N = nodes[ni]
        if len(N.N) >= 2: # possible root
            visited.append(N)
            r = visit_all(N, visited, True)
            unvisited = len(nodes) - len(visited)
            r = r + unvisited
            if min is None:
                min = r
                minroot = N
                if r == 0: break
            elif r < min:
                min = r
                minroot = N
            
    if min is None:
        return len(nodes) - 1, None # all but one
    else:
        return min, minroot
        
def visit_all(node, visited, root):
    if not root and len(node.N) == 2: # has 1 leaf + parent(node)
        return remove_all(node, visited)
    
    removed = 0
    if len(node.N) > 3:
        unvisited = [ n for n in node.N if n not in visited ]
        min = None
        for perm in itertools.permutations(unvisited, 2):
            r = 0
            for C in perm:
                r = r + visit_all(C, visited, False)
            if min is None or r < min: 
                min = r
            if min == 0:
                break
        
        if min is not None:
            removed = removed + min + len(unvisited) - 2
            for C in node.N:
                if C not in visited:
                    visited.append(C)
    else:
        for C in node.N:
            if C not in visited:
                visited.append(C)
                removed = removed + visit_all(C, visited, False)
    
    return removed

def remove_all(node, visited):
    removed = 0
    for C in node.N:
        if C not in visited:
            visited.append(C)
            removed = removed + 1 + remove_all(C, visited)
    return removed

if __name__ == '__main__':
    read_input()
    solve()
    write_result()
