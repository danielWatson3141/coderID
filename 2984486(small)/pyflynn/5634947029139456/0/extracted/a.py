# problem a

import sys

file_path = "/Users/flynn/playground/gcj/round-a/a/a.in"

def runner(handler):
    #file = open(file_path, 'r')
    file = sys.stdin
    T = int(file.readline())
    for t in xrange(T):
        print "Case #%s:" % (t+1),
        handler(file)


def flips(x, y):
    return {i for i, (m, n) in enumerate(zip(x, y))
            if m != n}

def is_match(flows, targets, ops):
    def flip(x):
        return x == '1' and '0' or '1'

    def operate(x):
        y = [i in ops and flip(m) or m for i, m in enumerate(x)]
        return ''.join(y)

    ff = [operate(f) for f in flows]
    return sorted(ff) == sorted(targets)

def run(file):
    N, L = map(int, file.readline().split())
    flows = file.readline().split()
    targets = file.readline().split()

    max_ans = 1000000
    ans = max_ans

    for i in xrange(N):
        x = flows[i]
        for j in xrange(N):
            y = targets[j]
            ops = flips(x, y)
            if is_match(flows, targets, ops) and len(ops) < ans:
                ans = len(ops)

    if ans == max_ans:
        ans = 'NOT POSSIBLE'
    print ans

runner(run)
