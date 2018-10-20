# from collections import Counter
from random import randint

def bad_shuffle():
    a = range(1000)
    for k in xrange(1000):
        p = randint(0, 999)
        a[k], a[p] = a[p], a[k]
    return tuple(a)

def prep(): return frozenset(bad_shuffle() for _ in xrange(10000))

def solve(perm, bads): return 'BAD' if tuple(perm) in bads else 'GOOD'

def main(fin, fout=None):
    T = int(fin.readline().strip())
    potential_bad = prep()
    for t in xrange(T):
        _ = fin.readline()  # get params
        perm = map(int, fin.readline().strip().split())
        solution = solve( perm, potential_bad )  # insert params
        if fout is not None:
            fout.write('Case #{}: {}\n'.format(t+1, solution))
        else:
            print 'Case #{}: {}'.format(t+1, solution)


if __name__ == '__main__':
    ## ADJUST PROBLEM INDEX AND MODE
    problem = 'C'  # 'A', 'B', 'C', or 'D'
    mode = 'small'  # 'practice', 'small', 'large'

    if mode is 'practice':
        with open(problem+'-practice.in', 'r') as fin:
            main(fin)

    elif mode is 'small':
        with open(problem+'-small-attempt0.in', 'r') as fin:
            with open(problem+'-small.out', 'w') as fout:
                main(fin, fout)

    elif mode is 'large':
        with open(problem+'-large.in', 'r') as fin:
            with open(problem+'-large.out', 'w') as fout:
                main(fin, fout)

    print ('done!' if mode in ('practice', 'small', 'large')
           else 'please choose a proper mode -- practice, small, or large')
