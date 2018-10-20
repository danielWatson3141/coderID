import string

file_name = "B-large.in"

binTreeInput = open(file_name, 'r')
data = string.split(binTreeInput.read().strip(), '\n')
numCases = int(data[0])

def countNodes(node, parent, tree):
    if len(tree[node]) <= 2:
        return 1
    else:
        count = []
        for n in tree[node]:
            if n != parent:
                count.append(countNodes(n, node, tree))
        count.sort()
        count = count[-1] + count[-2] +1
    return count

index = 1
for case in range(1,numCases+1):
    numNodes = int(data[index])
    tree = dict()
    for i in range(1,numNodes+1):
        tree[i] = []
    for edge in range(index+1, index +numNodes):
        a,b = [int(x) for x in string.split(data[edge])]
        tree[a].append(b)
        tree[b].append(a)
    index += numNodes #preparing for next input set
    """ Before this is preprocessing the data """

    minCut = 10**4
    for i in range(1,numNodes+1):
        if len(tree[i]) == 1:
            count = countNodes(tree[i][0], i, tree)
        elif len(tree[i]) == 2:
            count = countNodes(tree[i][0], i, tree) + countNodes(tree[i][1], i, tree) +1
        else:
            branches = [countNodes(tree[i][x], i, tree) for x in range(len(tree[i]))]
            branches.sort()
            count = branches[-1] + branches[-2] + 1
        if minCut > numNodes - count:
            minCut = numNodes - count
    print "Case #" + str(case) + ":", minCut

