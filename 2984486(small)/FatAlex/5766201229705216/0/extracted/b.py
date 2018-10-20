def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    N,=read_tuple(f)
    links=[]
    for _ in xrange(N-1):
        l=read_tuple(f)
        links.append((l[0]-1,l[1]-1))
    return links


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



max_cost=1001


def build_node_links(links):
    node_links={}
    for l in links:
        if not (l[0] in node_links):
            node_links[l[0]]=[]
        if not (l[1] in node_links):
            node_links[l[1]]=[]
        node_links[l[0]].append(l[1])
        node_links[l[1]].append(l[0])
    return node_links

def find_kill_cost(par, node_links, K):
    if par in K:
        return K[par]
    n,p=par
    cost=1
    for l in node_links[n]:
        if l!=p:
            cost=cost+find_kill_cost((l,n),node_links,K)
    K[par]=cost
    return cost
def calc_kill_costs(node_links):
    K={}
    for n,l in node_links.iteritems():
        for p in l+[n]:
            find_kill_cost((n,p),node_links,K)
    return K

def find_cost(par, node_links, K, C):
    if par in C:
        return C[par]
    n,p=par
    total_kill_cost=K[(n,p)]-1
    min_cost=total_kill_cost
    ch_costs=[]
    for l in node_links[n]:
        if l!=p:
            cost=find_cost((l,n),node_links,K,C)
            ch_costs.append((l,cost))
    if len(ch_costs)>=2:
        for i in xrange(len(ch_costs)-1):
            ch1,c1=ch_costs[i]
            for j in xrange(i+1,len(ch_costs)):
                ch2,c2=ch_costs[j]
                cost=total_kill_cost-K[(ch1,n)]+c1-K[(ch2,n)]+c2
                min_cost=min(min_cost,cost)
    C[par]=min_cost
    return min_cost
def solve(case):
    links=case
    N=len(links)+1
    node_links=build_node_links(links)
    K=calc_kill_costs(node_links)
    C={}
    min_cost=max_cost
    for r in xrange(N):
        cost=find_cost((r,r),node_links,K,C)
        min_cost=min(min_cost,cost)
    return min_cost

    





def outcome_string(outcome):
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