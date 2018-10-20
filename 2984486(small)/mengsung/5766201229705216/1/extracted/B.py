
graph = None

def max_full_binary_tree(root, previous) :
    child = 0
    for i in range(1, len(graph)) :
        if i != previous and graph[root][i] == 1:
            child += 1
            
    if child < 2 :
        return 1
    else :
        sub_tree = []
        for i in range(1, len(graph)) :
            if i != previous and graph[root][i] == 1:
                sub_tree.append(max_full_binary_tree(i, root))
        sub_tree.sort(reverse=True)
        return 1 + sub_tree[0] + sub_tree[1]

    
    

def solve(f) :
    global graph
    n = int(f.readline())
    graph = [ [ 0 for j in range(n+1) ] for i in range(n+1) ]
    for i in range(n - 1) :
        x, y = f.readline().split()
        x = int(x)
        y = int(y)
        graph[x][y] = 1
        graph[y][x] = 1

    max_nodes = -1
    for i in range(1, n+1) :
        nodes = max_full_binary_tree(i, 0)
        if nodes > max_nodes :
            max_nodes = nodes
            
    return n - max_nodes

if __name__ == '__main__' :
    with open('B-large.in') as f:
        t = int(f.readline())
        for i in range(t) :
            print ('Case #{0}: {1}'.format(i + 1, solve(f)))
