import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

class Graph:

    def __init__(self):
        self._neighbours = {}
        self._cache = {}

    def add_directed_edge(self,a,b):
        if a in self._neighbours:
            self._neighbours[a].append(b);
        else:
            self._neighbours[a] = [b]

    def add_edge(self,a,b):
        self.add_directed_edge(a,b)
        self.add_directed_edge(b,a)

    def neighbours(self, node):
        return self._neighbours[node]

    def children(self, node, parent):
        c = self._neighbours[node][:]
        c.remove(parent)
        return c

    def nodes(self):
        return self._neighbours.iterkeys()

    def compute_size_bdel(self, node, parent):
        if (node,parent) in self._cache:
            return self._cache[(node,parent)]

        size = 1
        bdel = 0

        child_data = []
        for c in self.children(node,parent):
            child_data.append(self.compute_size_bdel(c, node))

        def del_cost(cd):
            (size, bdel) = cd
            return size + bdel

        child_data = sorted(child_data, key = del_cost)
        # Delete all children
        for child_size, child_bdel in child_data:
            bdel += child_size
            bdel += child_bdel

        if (len(child_data)>=2):
            # Except the two largest children
            size += child_data[-1][0]
            bdel -= child_data[-1][0]
            size += child_data[-2][0]
            bdel -= child_data[-2][0]

        result = (size,bdel)
        self._cache[(node,parent)] = result
        return result


    def compute_minbinsize(self, root):
        bdel = 0
        for child in self.neighbours(root):
            s,d = self.compute_size_bdel(child, root)
            bdel += d
        return bdel

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            edges = int(f.readline())
            print "Case {0} has {1} edges".format(x+1, edges)

            G = Graph()

            for e in range(edges-1):
                P = map(int, f.readline().split(' '))
                G.add_edge(P[0],P[1])

            best = 999999
            for r in G.nodes():
                d = G.compute_minbinsize(r)
                if d < best:
                    best = d

            outf.write('Case #{0}: {1}\n'.format(x+1, best))
