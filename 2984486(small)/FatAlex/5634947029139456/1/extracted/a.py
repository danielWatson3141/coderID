def read_list(f):
    return [x for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    N,L=read_tuple(f)
    outlets=read_list(f)
    devices=read_list(f)
    return outlets,devices


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def xor(f1, f2):
    return "".join([("0" if c1==c2 else "1") for c1,c2 in zip(f1,f2)])
def weight(f):
    return sum([(1 if c=="1" else 0) for c in f])
def distance(f1,f2):
    return weight(xor(f1,f2))
def calc_syndrome(flows, mask):
    return [xor(flow,mask) for flow in flows]
def comp_syndromes(s1, s2):
    perm=[]
    for l in s1:
        if l in s2:
            perm.append(s2.index(l))
        else:
            return None
    return perm
def solve(case):
    outlets,devices=case
    N=len(outlets)
    if N==1:
        return distance(devices[0],outlets[0])
    dev_synd=calc_syndrome(devices,devices[0])
    min_weight=None
    for n in xrange(N):
        out_synd=calc_syndrome(outlets,outlets[n])
        if comp_syndromes(out_synd,dev_synd) is not None:
            w=distance(devices[0],outlets[n])
            if min_weight is None:
                min_weight=w
            else:
                min_weight=min(min_weight,w)
    return min_weight






def outcome_string(outcome):
    if outcome is None:
        return "NOT POSSIBLE"
    else:
        return "{}".format(outcome)


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