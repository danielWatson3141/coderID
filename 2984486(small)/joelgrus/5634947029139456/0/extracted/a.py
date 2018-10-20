infile = "A-small-attempt0.in"
outfile = "A-small.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = []

for _ in range(num_cases):
    
    nt, lt = lines[0].split()
    n = int(nt)
    l = int(lt)
    
    initial_flows = lines[1].split()
    desired_flows = lines[2].split()
    cases.append((n, l,initial_flows, desired_flows))
    lines = lines[3:]

def flip_bit(c):
    return '1' if c == '0' else '0'

def flip_bit_i(s, i):
    return ''.join([flip_bit(c) if j == i else c for j, c in enumerate(s)])

def flip_flows(flows,i):
    return [flip_bit_i(flow,i) for flow in flows]
    
def equal_flows(f1,f2):
    return all(x == y for x, y in zip(sorted(f1),sorted(f2)))
    
from collections import deque
    
def process_case(case):
    n, l, initial, desired = case
    
    if equal_flows(initial,desired):
        return 0
        
    state = initial
    seen_states = set()
    d = deque()
    d.append( (state, set()) )
    while len(d) > 0:
        state, bits_flipped = d.popleft()
        #print desired, state, bits_flipped
        for i in range(l):
            if i not in bits_flipped:
                new_state = flip_flows(state,i)
                if equal_flows(new_state, desired):
                    return len(bits_flipped) + 1
                s = ''.join(new_state)
                if s in seen_states:
                    continue
                seen_states.add(s)
                new_bf = set(bits_flipped)
                new_bf.add(i)
                d.append((new_state, new_bf))
                
    return "NOT POSSIBLE"

with open(outfile,"w") as g:
    
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + str(process_case(case)) + "\n")
    

