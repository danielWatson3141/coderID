from decimal import *
getcontext().prec = 100

fin = open('inputB.txt')
fout = open('outputB.txt','w')
num_tests = int(fin.readline())

for test_num in range(1, num_tests + 1):
    line = fin.readline().split(" ")
    N = int(line[0])
    adj = [[] for i in range(N)]

    for i in range(N-1):
        line = fin.readline().split(" ")
        start = int(line[0])-1
        end = int(line[1])-1
        adj[start].append(end)
        adj[end].append(start)

    nodes = [i for i in range(N)]
    min_del = N-1
    
    for src in range(N):
        depth = [N for i in range(N)]
        depth[src] = 0
        Q = [src]
        
        while len(Q) > 0:
            curr = Q.pop(0)
            for child in adj[curr]:
                if depth[child] > depth[curr]:
                    depth[child] = depth[curr] + 1
                    Q.append(child)

        tree_sizes = [1 for i in range(N)]
        max_size = 0
        nodes.sort(key=lambda x: depth[x], reverse=True)

        for node in nodes:
            if node != src and len(adj[node]) < 3:
                tree_sizes[node] = 1
            elif node == src and len(adj[node]) < 2:
                tree_sizes[node] = 1
            else:
##                ptr1 = None
##                ptr2 = None
##                for nbr in adj[node]:
##                    if depth[nbr] > depth[node]:
##                        if ptr1 == None or tree_sizes[nbr] > tree_sizes[ptr1]:
##                            ptr1 = nbr
##                        elif ptr2 == None or tree_sizes[nbr] > tree_sizes[ptr2]:
##                            ptr2 = nbr
                sizes = [tree_sizes[nbr] for nbr in adj[node] if depth[nbr] > depth[node]]
                sizes.sort(reverse=True)
                #tree_sizes[node] = tree_sizes[ptr1] + tree_sizes[ptr2] + 1
                tree_sizes[node] = sizes[0] + sizes[1] + 1
            max_size = max(max_size, tree_sizes[node])
        
        min_del = min(N - max_size, min_del)                  
    
    fout.write("Case #" + str(test_num) + ": " + str(min_del) + "\n")
    
fin.close()
fout.close()
