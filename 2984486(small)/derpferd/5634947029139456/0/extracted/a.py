import sys
from copy import deepcopy as copy

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
fpIn = open("small.in", "r")
fpOut = open("small.out", "w")
# fpIn = open("large.in", "r")
# fpOut = open("large.out", "w")


def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)

class Node:
    def __init__(self, m):
        self.m = [list(x) for x in m]

    def expand(self, nodes):
        nodes = []
        for r in range(len(self.m[0])):
            nodes.append(Node(self.flip(r)))
        return nodes

    def flip(self, i):
        l = copy(self.m)
        for r in range(len(self.m)):
            if l[r][i] == '0':
                l[r][i] = '1'
            else:
                l[r][i] = '0'
        return l

    def __eq__(self, other):
        return self.m == other.m

def check(n, end):
    for a in n:
        if a not in end:
            return False
    return True

def do_test():
    line = raw_input()

    N, L = line.split()

    start = raw_input().split()
    end = [list(x) for x in raw_input().split()]

    flips = 0
    currentNodes = []
    newNodes = [Node(start)]
    while newNodes:
        for node in newNodes:
            if check(node.m, end):
                return str(flips)
        currentNodes += newNodes
        newNodes = []
        for node in currentNodes:
            for new in node.expand():
                if new not in currentNodes and new not in newNodes:
                    newNodes.append(new)
        flips += 1

    return "NOT POSSIBLE"


def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        print "Case #" + str(i+1) + ": " + do_test()

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

