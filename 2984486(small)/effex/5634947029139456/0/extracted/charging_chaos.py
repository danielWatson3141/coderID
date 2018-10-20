filename = 'A-small.in'

f = open(filename, 'r')
num_cases = int(f.readline())

class Case:
    pass

def binarystr_to_int(s):
    num = 0
    for b, e in zip(s, reversed(range(len(s)))):
        num += pow(2, e) * int(b)
    return num

def next_case(f):
    c = Case()
    n_and_l = f.readline().split()
    if n_and_l == []:
        return []
    c.num_devices = int(n_and_l[0])
    c.num_switches = int(n_and_l[1])
    initial_flows = f.readline().split()  # these are strings
    c.initial_flows = []
    for flow in initial_flows:
        c.initial_flows.append(binarystr_to_int(flow))
    c.required_flows = f.readline().split() # these are strings
    c.required_flows = map(binarystr_to_int, c.required_flows)
    return c

def flip_switches(flows, switches):
    new_flows = []
    for f in flows:
        new_flows.append(f ^ switches)
    return new_flows

def num_flipped(switches):
    num = 0
    bit = 0
    while (1 << bit) <= switches:
        if switches & (1 << bit):
            num += 1
        bit += 1
    return num

c = next_case(f)
casenum = 1
while c != []:

    ans_str = 'Case #' + str(casenum) + ': '

    required_set = set(c.required_flows)
    min_flipped = 0
    match = 0
    for switches in range(pow(2, c.num_switches)):
        flipped = flip_switches(c.initial_flows, switches)
        if required_set == set(flipped):
            nflip = num_flipped(switches)
            if nflip < min_flipped or min_flipped == 0:
                min_flipped = nflip
            match = 1
            break
    
    if match:
        ans_str += str(min_flipped)
    else:
        ans_str += 'NOT POSSIBLE'

    print(ans_str)
    c = next_case(f)
    casenum += 1

if casenum - 1 != num_cases:
    print('error: not all cases read')
f.close()
