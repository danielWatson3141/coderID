from itertools import product

T = int(raw_input())

def check_valid(out, dev, flips):
    out2 = []
    for o in out:
        o2 = ""
        bits = map(int, o)
        for i, f in enumerate(flips):
            o2 += str(1 - bits[i]) if f else str(bits[i])
        out2.append(o2)

    for o, d in zip(sorted(out2), sorted(dev)):
        if o != d:
            return False
    return True

for case in range(T):
    N, L = map(int, raw_input().split())
    outlets = raw_input().split()
    devices = raw_input().split()

    o_counter = [0] * L
    d_counter = [0] * L

    for out in outlets:
        for i, bit in enumerate(out):
            o_counter[i] += int(bit)

    for dev in devices:
        for i, bit in enumerate(dev):
            d_counter[i] += int(bit)

    flips = [False] * L
    h_indices = []
    for i in range(L):
        if N % 2 == 0 and o_counter[i] == N/2:
            h_indices.append(i)
            continue
        if o_counter[i] == d_counter[i]:
            continue

        if o_counter[i] == N - d_counter[i]:
            flips[i] = True
        else:
            print "Case #{}: NOT POSSIBLE".format(case+1)
            break
    else:
        min_fc = 999999
        for prod in product([False, True], repeat=len(h_indices)):
            tmp_flips = flips[:]
            for i, h in zip(h_indices, prod):
                tmp_flips[i] = h
            if check_valid(outlets, devices, tmp_flips):
                fc = tmp_flips.count(True)
                if fc < min_fc:
                    min_fc = fc

        if min_fc < 999999:
            print "Case #{}: {}".format(case+1, min_fc)
        else:
            print "Case #{}: NOT POSSIBLE".format(case+1)