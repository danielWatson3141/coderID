import sys
def charging(init, needed):

    shared_changes = set()
    for outlet in init:
        to_change = set()
        for device in needed:
            compute = [outlet[x] != device[x] for x in xrange(len(outlet))]
            this_device = []
            for pos in xrange(len(compute)):
                if compute[pos]: this_device.append(pos)
            to_change.add(tuple(this_device))
        if len(shared_changes)==0: shared_changes = to_change
        else:
            keys = list(shared_changes)
            for changes in keys:
                if changes not in to_change:
                    shared_changes.remove(changes)
            if len(shared_changes)==0: return "NOT POSSIBLE"

    sol = sys.maxint
    for s in shared_changes:
        if len(s)<sol: sol = len(s)
         
    return str(sol)

T=int(raw_input())
solutions = []
for t in xrange(T):
    two = map(int, raw_input().strip().split())
    N = two[0]
    L = two[1]
    init_flow =raw_input().strip().split()
    need_flow = raw_input().strip().split()
    
    sol = charging(init_flow, need_flow)
    
    form = "Case #%d: %s" %(t+1, sol)
    solutions.append(form)

with open('charging_large.txt', 'w') as f:
    for s in solutions[:-1]:
        f.write(s)
        f.write("\n")
    f.write(solutions[-1])