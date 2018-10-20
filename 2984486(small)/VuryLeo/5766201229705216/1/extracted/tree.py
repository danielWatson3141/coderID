import sys
import operator

class Node(object):
    def __init__(self):
        self.edges = []

def dp(nodes, i, fa):
    cnt = len(nodes[i].edges)
    if fa != None:
        cnt -= 1
    if cnt < 2:
        return 1
    vs = {}
    for node in nodes[i].edges:
        if node != fa:
            vs[node] = dp(nodes, node, i)
    sortedVs = sorted(vs.items(), key=operator.itemgetter(1))[::-1]
    return sortedVs[0][1] + sortedVs[1][1] + 1

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        n = int(sys.stdin.readline())
        nodes = [Node() for i in range(n + 1)]
        for i in range(n - 1):
            s, t = map(int, sys.stdin.readline().split())
            nodes[s].edges.append(t)
            nodes[t].edges.append(s)
        ans = 0
        for i in range(1, n + 1):
            ans = max(ans, dp(nodes, i, None))
        sys.stdout.write("{}\n".format(n - ans))

