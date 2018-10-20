import sys

def is_valid(flows, devices, bits):
    if bits < 0:
        return True
    devices = sorted(devices)
    for flow in flows:
        str_flow = flow[:bits + 1]
        found = None
        for d in devices:
            if d.startswith(str_flow):
                found = d
                break
        if found:
            devices.remove(found)
    return len(devices) == 0

def charching_caos(flows, devices, L):
    flips = 0
    bit = -1
    while True:
        valid = is_valid(flows, devices, bit)
        if not valid:
            new_flows = []
            for flow in flows:
                f = list(flow)
                f[bit] = '1' if f[bit] == '0' else '0'
                new_flows.append(''.join(f))
            flows = new_flows
            valid = is_valid(new_flows, devices, bit)
            flips += 1
        if not valid:
            return 'NOT POSSIBLE'
        if bit == L - 1:
            if valid:
                return flips
            break
        bit += 1
    return 'NOT POSSIBLE'



def charching(flows, devices, bit, L):
    if bit == L:
        return True, 0
    first_valid = is_valid(flows, devices, bit)
    new_flows = []
    for flow in flows:
        f = list(flow)
        f[bit] = '1' if f[bit] == '0' else '0'
        new_flows.append(''.join(f))
    second_valid = is_valid(new_flows, devices, bit)
    if first_valid and second_valid:
        valid1, flips1 = charching(flows, devices, bit + 1, L)
        valid2, flips2 = charching(new_flows, devices, bit + 1, L)
        flips2 += 1
        if valid1 and valid2:
            return True, min(flips1, flips2)
        if valid1:
            return valid1, flips1
        if valid2:
            return valid2, flips2
        return False, 0
    elif first_valid:
        return charching(flows, devices, bit + 1, L)
    elif second_valid:
        valid2, flips2 = charching(new_flows, devices, bit + 1, L)
        return valid2, flips2 + 1
    else:
        return False, 0

def solve(flows, devices, L):
    valid, flips = charching(flows, devices, 0, L)
    if not valid:
        return 'NOT POSSIBLE'
    return flips

T = int(sys.stdin.readline())
for t in range(1, T + 1):
    N, L =[int(x) for x in sys.stdin.readline().split()]
    initial = sys.stdin.readline().split()
    required = sys.stdin.readline().split()
    print('Case #{0}: {1}'.format(t, solve(initial, required, L)))

