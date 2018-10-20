def root_cost(node, nodes):
    size = len(nodes[node])
    if size == 1:
        return len(nodes) - 1, 1
    costs = []
    for n in nodes[node]:
        costs.append(subroot_cost(n, nodes, node))
    c, s = balance(costs)
    return c, s+1

def balance(costs):
    min = 2000
    min_s = 0
    total = sum(i for c in costs for i in c)
    #total = sum(s for c, s in costs)
    for i, v1 in enumerate(costs[:-1]):
        for v2 in costs[i+1:]:
            s = total - sum(v1) - sum(v2)
            c = v1[0] + v2[0] + s
            if c < min:
                min = c
                min_s = v1[1] + v2[1]
    return min, min_s

def subroot_cost(node, nodes, father):
    size = len(nodes[node])
    if size == 1:
        return (0, 1)
    if size == 2:
        n = [n for n in nodes[node] if n != father][0]
        c, s = subroot_cost(n, nodes, node)
        return s+c, 1
    costs = []
    cost = 0
    for n in nodes[node]:
        if n != father:
            c, s = subroot_cost(n, nodes, node)
            #if s == 0:
                #cost += c
            #else:
            costs.append((c, s))
    c, s = balance(costs)
    return c+cost, s + 1

def add(nodes, x, y):
    if x not in nodes:
        nodes[x] = []
    nodes[x].append(y)

def add_pair(nodes, x, y):
    add(nodes, x, y)
    add(nodes, y, x)

def main():
    n = int(raw_input())
    nodes = {}
    for i in xrange(n-1):
        x, y = raw_input().split()
        add_pair(nodes, x, y)
    min = 10000
    for i in xrange(1, n+1):
        c = root_cost(str(i), nodes)[0]
        if c < min:
            min = c
    return min

t = int(raw_input())

for i in xrange(1,t+1):
    print "Case #%d:" % i, main()
