from __future__ import print_function

import sys
sys.setrecursionlimit(1000000)

class Nodes:
    def __init__(self, nb):
        self.nb = nb
        self.nodes = {}
        for i in xrange(nb+1):
            self.nodes[i+1] = {}
            self.nodes[i+1]["edgeCount"] = 0
            self.nodes[i+1]["neighbours"] = []

    def addEdges(self, src, dest):
        self.nodes[src]["edgeCount"] += 1
        self.nodes[dest]["edgeCount"] += 1
        self.nodes[src]["neighbours"].append(dest)
        self.nodes[dest]["neighbours"].append(src)

    def getRootCandidate(self):
        for node_id, node in self.nodes.items():
            yield node_id

    def count(self, src, visited=[]):
        node = self.nodes[src]
        choices = []
        if src in visited:
            return 0
        visited.append(src)
        for neigh in node["neighbours"]:
            if neigh == src:
                continue
            neighbour = self.nodes[neigh]
            if neighbour["edgeCount"] <= 2:
                choices.append(1)
            else:
                a = self.count(neigh, visited)
                if a > 0:
                    choices.append(a)
        choices.sort()
        if len(choices) > 1:
            return choices[-1] + choices[-2] + 1
        else:
            return 1

if __name__ == '__main__':
    T = int(raw_input())
    for pb_i in xrange(T):
        # read input T
        N = int(raw_input())
        nodes = Nodes(N)
        for i in xrange(N-1):
            a, b = [int(_) for _ in raw_input().split()]
            nodes.addEdges(a, b)

        result = N-1
        for id in nodes.getRootCandidate(): 
            c = nodes.count(id, [])
            result = min(result, N-c)
            if result == 0:
                break
        print("Case #{}: {}".format(pb_i+1, result))