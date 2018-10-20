import fileinput
from itertools import permutations, starmap, izip


def solve(outlets, devices):
    ok = []
    for perm in permutations(outlets):
        switches = list(starmap(lambda i, j: i ^ j, izip(perm, devices)))
        switches = set(switches)
        if len(switches) == 1:
            switch = switches.pop()
            ok.append(bin(switch).count('1'))
    if ok:
        return '%d' % min(ok)

    return 'NOT POSSIBLE'


def run():
    f = fileinput.input()
    T = int(f.readline())
    for t in xrange(1, T + 1):
        N, L = f.readline().split(' ')
        outlets = [int(o, 2) for o in f.readline().split(' ')]
        devices = [int(o, 2) for o in f.readline().split(' ')]
        print 'Case #%d: %s' % (t, solve(outlets, devices))


if __name__ == '__main__':
    run()