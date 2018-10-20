import pprint

def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

def is_full_tree(G):
    def travel(parent,child):
        if len(G[child]) == 3:
            L = G[child][:]
            L.remove(parent)
            return travel(child,L[0]) and travel(child,L[1])
        return len(G[child]) == 1
    for i,V in enumerate(G):
        if len(V) != 2:
            continue
        if travel(i,V[0]) and travel(i,V[1]):
            return True
    return False

def full_tree_count(parent,child,G):
    if len(G[child]) < 3:
        return 1
    L = G[child][:]
    L.remove(parent)
    L = [full_tree_count(child,adj,G) for adj in L]
    L.sort(reverse=True)
    return L[0]+L[1]+1

def calculate():
    N = input()
    
    G = [[] for i in xrange(N)]
    for i in xrange(1,N):
        S,D = map(int,raw_input().split())
        S,D = S-1,D-1
        G[S].append(D)
        G[D].append(S)


    size = []

    for i,adj in enumerate(G):
        if len(adj) < 2:
            continue
        L = [full_tree_count(i,adj_v,G) for adj_v in adj]
        L.sort(reverse=True)
        size.append(L[0]+L[1]+1)

    if len(size) == 0:
        #the number of vertex is 2.
        assert N == 2
        print 1
    
    else:
        print N-max(size)


if __name__ == '__main__':
    do()

