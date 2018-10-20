import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]
    
def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

################################################################################

def read_case(f):
    n = read_int(f)
    adj = {}
    for i in range(n-1):
        e = read_ints(f)
        if e[0] in adj:
            adj[e[0]].append(e[1])
        else:
            adj[e[0]] = [e[1]]
        if e[1] in adj:
            adj[e[1]].append(e[0])
        else:
            adj[e[1]] = [e[0]]
    return n, adj

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')


################################################################################
def search(root, used, n, adj):
    child = []
    for i in range(1, n+1):
        if i in adj[root] and used[i] == False: child.append(i)
    if len(child) < 2:
        return 1
    childRes = []
    for i in range(len(child)):
        used[child[i]] = True
        childRes.append(search(child[i], used, n, adj))
        used[child[i]] = False
    childRes.sort()
    return childRes[len(child) - 1] + childRes[len(child) - 2] + 1
    
def solve_small(case):
    n, adj = case
    used = [False] * (n+1)
    res = 0
    for i in range(1, n+1):
        used[i] = True
        t = search(i, used, n, adj)
        used[i] = False
        if (t > res):
            res = t
    return n - res
    
solve_large = solve_small

solve(solve_large, 'Bs')

