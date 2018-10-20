import sys
import itertools
import math
import collections
import functools

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
def solve(solver,SMALL=True,PRACTICE=False):
    fn = sys.argv[0]
    fn = fn[ 1+fn.rfind('/'): fn.rfind('.') ]
    fn = fn+['-large','-small'][SMALL]+['','-practice'][PRACTICE]
    in_fn = fn + '.in'
    out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                print i+1, res
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

#######################################################

def read_case(f):
    N,L = read_ints(f)
    init = read_words(f)
    goal = read_words(f)
    return N,L,init,goal

#######################################################

def flip(a):
    if a=='0': return '1'
    return '0'

def justflip(i,x):
    return x[:i]+ flip(x[i]) + x[i+1:]

def listflip(i,x):  #flip the ith position only
    return map(lambda y: justflip(i,y) , x)

def justerflip(lt,x):
    #print lt,x,'J'
    ans = [x[i] for i in xrange(len(x))]
    for i in lt:
        ans[i] = flip(ans[i])
    return "".join(ans)

def listerflip(lt,x):
    #print lt,x,'L'
    return map(lambda y: justerflip(lt,y) , x)

def gensubsets(s):
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))
    
def gendouble(m,x):
    # make a list of all indices to flip and yield the flips at once
    t = []
    for i in xrange(len(m)):
        if m[i]==0: t.append(i)

    if t == []:
        yield 0,x
    else:
        for i in gensubsets(t):
            yield len(i),listerflip(i,x)
    

def genresu(m,x):
    # start by flipping all
    r = x[:]
    flipct = 0
    for i in xrange(len(m)):
        if m[i] == 2:  #flip
            r = listflip(i,r)
            flipct += 1
    #print 'R',r
    # now just have to do "2" flips
    for i in gendouble(m,r):
        yield flipct+i[0], i[1]
        
            
def solver(case):
    N,L,init,goal = case
    initsum = [sum(map(lambda x: int(x[i]),init)) for i in xrange(L)]
    goalsum = [sum(map(lambda x: int(x[i]),goal)) for i in xrange(L)]
    mappy = []
    #print init, goal
    #print initsum,goalsum,'gg'
    for i in xrange(L):
        #print mappy,'mm'
        if (initsum[i] == goalsum[i]) and (initsum[i] == N-goalsum[i]):
            mappy.append(0)
        elif initsum[i] == goalsum[i]:
            mappy.append(1)
        elif initsum[i] == N-goalsum[i]:
            mappy.append(2)
        else:
            return "NOT POSSIBLE"
    if sum(mappy) == 0:
        return "NOT POSSIBLE"

    #now try mappy to see if it works
    for i in genresu(mappy,init):
        #print 'II',i
        if set(i[1]) == set(goal): return i[0]
    return "NOT POSSIBLE"
        
    



    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
