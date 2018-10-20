def memo(f):
    cache = {}
    def _f(*args):
        if args in cache:
            return cache[args]
        else:
            result = cache[args] = f(*args)
            return result
    return _f

def is_goal(state, goal): return state == goal

def flip(bit): return '0' if bit=='1' else '1'

def successors(nchanges, state, i):
    change_bit_i = frozenset(c[:i]+flip(c[i])+c[i+1:] for c in state)
    return ([nchanges+1, change_bit_i], [nchanges, state])

@memo
def solve(L, state, goal, nchanges=0, i=0):
    if is_goal(state, goal):
        return nchanges
    elif i >= L:
        return 2*L
    else:
        return min(solve(L, st, goal, nch, i+1)
                   for nch,st in successors(nchanges, state, i))


def main(fin, fout=None):
    T = int(fin.readline().strip())
    for t in xrange(T):
        N, L = map(int, fin.readline().strip().split())
        start = frozenset(fin.readline().strip().split())
        goal = frozenset(fin.readline().strip().split())
        solution = solve( L, start, goal )
        solution = solution if solution<=L else 'NOT POSSIBLE'
        if fout is not None:
            fout.write('Case #{}: {}\n'.format(t+1, solution))
        else:
            print 'Case #{}: {}'.format(t+1, solution)


if __name__ == '__main__':
    ## ADJUST PROBLEM INDEX AND MODE
    problem = 'A'  # 'A', 'B', 'C', or 'D'
    mode = 'small'  # 'practice', 'small', 'large'

    if mode is 'practice':
        with open(problem+'-practice.in', 'r') as fin:
            main(fin)

    elif mode is 'small':
        with open(problem+'-small-attempt1.in', 'r') as fin:
            with open(problem+'-small.out', 'w') as fout:
                main(fin, fout)

    elif mode is 'large':
        with open(problem+'-large.in', 'r') as fin:
            with open(problem+'-large.out', 'w') as fout:
                main(fin, fout)

    print ('done!' if mode in ('practice', 'small', 'large')
           else 'please choose a proper mode -- practice, small, or large')
