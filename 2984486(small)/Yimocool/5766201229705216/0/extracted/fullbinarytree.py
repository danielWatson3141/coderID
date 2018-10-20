
BIG = 1000000007

file_name = "B-small-attempt1"
# file_name = "B-large"

f = open("../../../../" + file_name + ".in", "r")
# f = open("../test.txt")
w = open("../../../../" + file_name + ".out", "w")
time = int(f.readline())

for T in range(1, time + 1):
    print("case " + str(T))
    w.write("Case #" + str(T) + ": ")
    N, = map(int, f.readline().split())
    neighbors = [[] for i in range(N + 1)]
    for i in range(N - 1):
        v1, v2 = map(int, f.readline().split())
        neighbors[v1].append(v2)
        neighbors[v2].append(v1)
    min_value = BIG
    for root in range(1, N + 1):
        # print "case", str(T), "root", root
        done_nodes = set([root])
        level = [[root]]
        parent = (N + 1) * [0]
        children = [[] for i in range(N + 1)]
        
        while len(done_nodes) < N:
            level.append([])
            for v1 in level[-2]:
                for v2 in neighbors[v1]:
                    if v2 in done_nodes:
                        continue
                    done_nodes.add(v2)
                    level[-1].append(v2)
                    parent[v2] = v1
                    children[v1].append(v2)

    
        total_cut = 0
        num_children = (N + 1) * [1]
        
        for i in range(len(level) - 1, -1, -1):
            
            for v in level[i]:
                # print "Before", v, total_cut
                if len(children[v]) == 1:
                    total_cut += num_children[children[v][0]]
                elif (len(children[v]) > 2):
                    temp = []
                    for v2 in children[v]:
                        temp.append(num_children[v2])
                    temp = sorted(temp)
                    num_children[v] += temp[-1] + temp[-2]
                    for j in range(0, len(temp) - 2):
                         total_cut += temp[j]
                else:
                    for v2 in children[v]:
                        num_children[v] += num_children[v2]   
                # print "after", v, total_cut         
        # print level
        # print num_children
        min_value = min(min_value, total_cut)

    w.write(str(min_value) + "\n")
    
