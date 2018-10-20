import sys

sys.setrecursionlimit(1000000)


def solve(f):
    f.readline()
    P = [int(s) for s in f.readline().split()]
    pairsCount = 1
    for i in range(1, len(P)):
        pairsCount *= i
    sortedPairsCount = 0
    for k in range(len(P)):
        for l in range(k+1, len(P)):
            if P[k] < P[l]:
                sortedPairsCount += 1
    if 2*sortedPairsCount > pairsCount:
        return "BAD"
    return "GOOD"


def main(f):
    T = int(f.readline())
    for t in range(1, T+1):
        result = solve(f)
        print("Case #%d: %s" % (t, result))

if __name__ == '__main__':
    main(open(sys.argv[1]) if len(sys.argv) > 1 else sys.stdin)
