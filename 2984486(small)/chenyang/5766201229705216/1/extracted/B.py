import sys
sys.setrecursionlimit(6000)
getints = lambda : map(int, raw_input().split())

def memo(fn):
    cache = {}
    def memoized(*args):
        if args not in cache:
            cache[args] = fn(*args)
        return cache[args]
    return memoized

def solve(GRAPH):
    @memo
    def compute_root(node, innode):
        # returns number of nodes to cut
        branches = get_branches(node)
        if innode is not None:
            branches.remove(innode)
        #print node, innode, branches
        l = len(branches)
        if l == 2:
            # valid
            b = list(branches)
            return compute_root(b[0], node) + compute_root(b[1], node)
        elif l < 2:
            # cut as leaf
            # print map(lambda n: cut(n, node), branches)
            return sum(map(lambda n: cut(n, node), branches))
        else:
            comp = []
            for branch in branches:
                included = compute_root(branch, node)
                removed = cut(branch, node)
                comp.append((removed - included, included, removed))
            comp = sorted(comp)
            return sum([c[2] for c in comp[:-2]]) + comp[-1][1] + comp[-2][1]
    @memo
    def cut(node, innode):
        branches = get_branches(node)
        branches.remove(innode)
        return 1 + sum([cut(b, node) for b in branches])

    def get_branches(node):
        return GRAPH[node][:]

    return min([compute_root(node, None) for node in GRAPH])


def main():
    for t in range(input()):
        n = input()
        GRAPH = {}
        for _ in range(n-1):
            a, b = getints()
            GRAPH.setdefault(a, []).append(b)
            GRAPH.setdefault(b, []).append(a)
        print >> sys.stderr, "Case " + str(t+1)
        print "Case #{}: {}".format(t + 1, solve(GRAPH))

def test():
    global GRAPH
    GRAPH = {1: [2, 3], 2: [4, 1], 3: [1, 7], 4: [5, 2, 6], 5: [4], 6: [4], 7: [3]}
    print compute_root(2, None)

main()
