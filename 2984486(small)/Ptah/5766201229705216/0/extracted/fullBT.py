import sys, os
from collections import defaultdict
from itertools import combinations

puzzles = list()

FILENAME = 'B-small-attempt3.in'

def buildObjects(puzzle):
    obj = defaultdict(list)
    for (a, b) in puzzle:
        obj[a].append(b)
        obj[b].append(a)
    return obj

def countChildren(t, currentNode, parentNode):
    children = [node for node in t[currentNode] if node != parentNode]
    return 1 + sum([countChildren(t, c, currentNode) for c in children])


def getNumberOfNodesToDelete(t, currentNode, parentNode):
    children = [node for node in t[currentNode] if node != parentNode]
    if len(children) == 0:
        return 0
    elif len(children) == 2:
        return sum([getNumberOfNodesToDelete(t, c, currentNode) for c in children])
    elif len(children) == 1: #Delete all below nodes and itself
        print "deleting children of ", currentNode
        print children
        n = countChildren(t, currentNode, parentNode) - 1
        print n
        return n
    else: #We have more than 2 children ... I only saw 3 children, but I m not going to presume anything at this point ....
        tumin = 10000
        solmin = tuple()
        for tu in combinations(children, len(children) - 2):
            n2 = sum([countChildren(t, tun, currentNode) for tun in tu])
            if n2 < tumin:
                tumin = n2
                solmin = tu
        return tumin + sum([getNumberOfNodesToDelete(t, c, currentNode) for c in children if not c in solmin])


def solve(t, nodeNumber):
    mini = 10000
    for root in range(1, nodeNumber+1):
        #if len(t[root]) > 2: #cannot be root
        #    continue
        print "\n Root is ", root
        n = getNumberOfNodesToDelete(t, root, -1)
        print "result is", n
        if n < mini:
            mini = n
    return mini

with open(FILENAME, 'r') as f:
    nbTestCases = int(f.readline())
    for _ in range(nbTestCases):
        currentPuzzle = list()
        nodeNumber = int(f.readline())
        for n in range(nodeNumber-1):
            currentPuzzle.append([int(m) for m in f.readline().strip().split()])
        puzzles.append((nodeNumber, currentPuzzle))

printResult = ''
for (i, puzzle) in enumerate(puzzles):
    print puzzle
    t = buildObjects(puzzle[1])
    print t
    print 'Case #%s: %s\n' % (i+1, solve(t, puzzle[0]))
    printResult += 'Case #%s: %s\n' % (i+1, solve(t, puzzle[0]))

print printResult
#sys.exit(0)

if os.path.isfile('result'):
    os.remove('result')
with open('result', 'w') as f:
    f.write(printResult[:-1])