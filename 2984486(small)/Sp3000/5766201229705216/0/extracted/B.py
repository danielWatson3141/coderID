infile = open("B-small-attempt0.in", "rU")
outfile = open("B.out", "w")

ncases = int(infile.readline().strip())

for case in xrange(1, ncases + 1):
    adj_list = {}
    
    num_nodes = int(infile.readline().strip())

    for i in xrange(num_nodes - 1):
        pair = [int(x) for x in infile.readline().strip().split(" ")]

        if pair[0] not in adj_list:
            adj_list[pair[0]] = [pair[1]]
        else:
            adj_list[pair[0]].append(pair[1])

        if pair[1] not in adj_list:
            adj_list[pair[1]] = [pair[0]]
        else:
            adj_list[pair[1]].append(pair[0])

    minimum = -1
    min_root = 0
    
    for root in adj_list:
        # Perform BFS to build tree

        parent = {root: None}
        children = {}

        fringe = [root]

        while len(fringe) > 0:
            node = fringe.pop()

            node_children = []
            
            for c in adj_list[node]:
                if c not in parent:
                    parent[c] = node
                    node_children.append(c)
                    fringe.append(c)

            children[node] = node_children

        subtree_size = {} # (size of subtree rooted at node, node to remove from subtree to get full binary tree)
        next_child = {}
        curr_node = root

        while curr_node != None:
            if curr_node not in next_child:
                next_child[curr_node] = 0

            if next_child[curr_node] >= len(children[curr_node]):
                if len(children[curr_node]) == 0:
                    subtree_size[curr_node] = (1, 0)

                elif len(children[curr_node]) == 1:
                    subtree_size[curr_node] = (1 + subtree_size[children[curr_node][0]][0],
                                               subtree_size[children[curr_node][0]][0])

                elif len(children[curr_node]) == 2:
                    subtree_size[curr_node] = (1 + subtree_size[children[curr_node][0]][0] + subtree_size[children[curr_node][1]][0],
                                               subtree_size[children[curr_node][0]][1] + subtree_size[children[curr_node][1]][1])
                    
                else:
                    to_keep = []
                    tree_size = 1
                    
                    for c in children[curr_node]:
                        tree_size += subtree_size[c][0]
                        to_keep.append(subtree_size[c][0] - subtree_size[c][1])

                    to_keep.sort()
                    to_keep.reverse()

                    subtree_size[curr_node] = (tree_size, tree_size - (1 + to_keep[0] + to_keep[1]))

                curr_node = parent[curr_node]                        

            else:
                temp_node = curr_node
                curr_node = children[curr_node][next_child[curr_node]]
                next_child[temp_node] += 1

        if minimum == -1 or subtree_size[root][1] < minimum:
            minimum = subtree_size[root][1]
            min_root = root

    outfile.write("Case #%d: %d\n" % (case, minimum))
    print case, min_root
    
infile.close()
outfile.close()
