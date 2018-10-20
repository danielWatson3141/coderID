def solve(testnum):
    t = int(input())
    tree = [[] for i in range(t)]
    for i in range(t-1):
        a,b = [int(x) for x in input().split()]
        a -= 1; b -= 1
        tree[a].append(b); tree[b].append(a)
    #print(tree)
        
    def sizeof(node, parent = None):
        return 1 + sum([sizeof(child,node)
                        for child in tree[node]
                        if child != parent])
    def cost(node, parent = None):
        chil = [c for c in tree[node] if c != parent]
        #print("Cost %d, Parent %d, chil="%(node,-1 if parent == None else parent)+str(chil))
        if len(chil) == 0:
            return 0
        elif len(chil) == 1:
            return sizeof(chil[0],node)
        #elif len(chil) == 2:
        #    return cost(chil[0],node)+cost(chil[1],node)
        else:
            #assert len(chil) > 2
            sizes = [sizeof(c,node) for c in chil]
            costs = [cost(c,node) for c in chil]
            dif = [sizes[i]-costs[i] for i in range(len(chil))]
            sdif = sorted(dif)
            return sum(sizes)-sdif[-1]-sdif[-2]
    costs = [cost(i) for i in range(t)]
    ans = min(costs)
    print("Case #%d: %d"%(testnum, ans))

for i in range(int(input())): solve(i+1)
