import sys
def charging_chaos(init_flow, need_flow):

    import itertools
    lst = list(itertools.product([0, 1], repeat=len(init_flow[0])))

    to_match = set()
    for f in need_flow:
        to_match.add(f)
    
    answer = sys.maxint
    for l in lst:
        second_set = set()
        for outlet in init_flow:
            string = "".join([str(int(outlet[x])^int(l[x])) for x in xrange(len(outlet))])
            second_set.add(string)
        if second_set == to_match:
            total_switches = sum(l)
            if total_switches<answer:
                answer = total_switches

    sol = "NOT POSSIBLE"
    if answer == sys.maxint:
        return sol
    else: return str(answer)


T=int(raw_input())
solutions = []
for t in xrange(T):
    two = map(int, raw_input().strip().split())
    N = two[0]
    L = two[1]
    init_flow =raw_input().strip().split()
    need_flow = raw_input().strip().split()
    
    sol = charging_chaos(init_flow, need_flow)
    
    form = "Case #%d: %s" %(t+1, sol)
    solutions.append(form)

with open('charging_ouput.txt', 'w') as f:
    for s in solutions[:-1]:
        f.write(s)
        f.write("\n")
    f.write(solutions[-1])

