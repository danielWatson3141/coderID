import random

def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    _=read_tuple(f)
    return read_list(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases

e=2.718
def Ppk(k,p,N):
    if p<=k:
        return 1./(N+(e-1)*(N-k-1))
    else:
        return e/(N+(e-1)*(N-k-1))
def solve(case):
    N=1000.
    ng=0
    nb=0
    for k,p in enumerate(case):
        pg=1/N
        pb=Ppk(k,p,N)
        if pg>pb:
            ng=ng+1
        else:
            nb=nb+1
    return ng>=nb 






def outcome_string(outcome):
    if outcome:
        return "BAD"
    else:
        return "GOOD"


def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
                f.write("Case #{0}: {1}\n".format( n+1 , outcome_string(o) ))
def process(path_in, path_out=None):
    if path_out==None:
        path_out=path_in.rsplit(".",1)[0]+".out"
    cases=load_cases(path_in)
    outcomes=[solve(c) for c in cases]
    save_outcomes(path_out, outcomes)
    




def verify_outcome(case, outcome):
    ### IMPLEMENT ###
    return outcome==solve(case)

def test_solutions(path_in, until_first_fail=True):
    cases=load_cases(path_in)
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print case
            print "Outcome:"
            print outcome
            if until_first_fail:
                break
            else:
                print "\n\n"
                
def gen_cases():
    ### IMPLEMENT ###
    return []

def test_solutions_gen(until_first_fail=True):
    cases=gen_cases()
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print case
            print "Outcome:"
            print outcome
            if until_first_fail:
                break
            else:
                print "\n\n"