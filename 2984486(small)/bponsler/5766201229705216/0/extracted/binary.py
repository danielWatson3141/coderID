from sys import stdin

def addToTree(items, tree):
    treeItem0 = tree.get(items[0], [])
    treeItem1 = tree.get(items[1], [])

    treeItem0.append(items[1])
    treeItem1.append(items[0])

    tree[items[0]] = treeItem0
    tree[items[1]] = treeItem1

    return tree


def countChildren(tree, node, visited=None):
    visited = [] if visited is None else visited
    visited.append(node)

    children = tree[node]

    # Ignore parents
    children = filter(lambda c: c not in visited, children)

    num = len(children)
    for child in children:
        c = countChildren(tree, child, visited)
        num += c

    return num


def numChildrenToRemove(tree, node, visited=None):
    visited = [] if visited is None else visited
    visited.append(node)

    numChildren = 0
    children = tree[node]

    # Ignore visited nodes
    children = filter(lambda c: c not in visited, children)

    if len(children) == 0:
        return 0  # No children have to be removed, valid leaf
    elif len(children) == 1:
        # Have to remove the child and its children
        nc = 1 + countChildren(tree, children[0], visited)
        numChildren += nc
    else:
        childCounts = [numChildrenToRemove(tree, c, visited) \
                           for c in children]
        numChildren += sum(childCounts)

        # Need to remove children until achieve 2 children
        numChildren += len(childCounts) - 2
            

    return numChildren


def handleTest(case, numNodes, lines):
    tree = {}
    for line in lines:
        items = map(int, line.split(" "))
        tree = addToTree(items, tree)

    # Roots must have at least 2 nodes to start
    possibleRoots = filter(lambda e: len(tree[e]) >= 2, tree)

    minCount = None

    for root in possibleRoots:
        count = numChildrenToRemove(tree, root)

        minCount = count if minCount is None else min(minCount, count)

    if minCount is None:
        minCount = len(tree)

    print "Case #%d: %s" % (case, minCount)


if __name__ == '__main__':
    data = stdin.read().strip()
    lines = data.split("\n")

    numTests = int(lines[0])

    case = 1
    index = 1
    while index < len(lines):
        numNodes = int(lines[index])
        testLines = lines[index+1:index + numNodes]

        handleTest(case, numNodes, testLines)

        case += 1
        index += numNodes
