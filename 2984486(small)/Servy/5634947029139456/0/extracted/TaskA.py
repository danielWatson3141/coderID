__author__ = 'Servy'

import sys

testNumber = int(sys.stdin.readline().strip())
for test in range(1, testNumber + 1):
    n, l = map(int, sys.stdin.readline().split())
    outlets = list(map(lambda x: int(x, 2), sys.stdin.readline().split()))
    devices = list(map(lambda x: int(x, 2), sys.stdin.readline().split()))

    matrix = [[outlets[j] ^ devices[i] for j in range(n)] for i in range(n)]

    solutionFound = False
    solutionInt = 0
    for solution in sorted(matrix[0], key=lambda x: bin(x).count("1")):
        usedOutlets = set()
        succeded = True
        for i in range(n):
            try:
              index = matrix[i].index(solution)
            except ValueError:
                succeded = False
                break

            if index in usedOutlets:
                succeded = False
                break

            usedOutlets.add(index)
        if succeded:
            solutionFound = True
            solutionInt = solution
            break

    if solutionFound:
        print("Case #%d: %d" % (test, bin(solutionInt).count("1")))
    else:
        print("Case #%d: NOT POSSIBLE" % test)