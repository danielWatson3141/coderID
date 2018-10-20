from sys import stdin, stdout

lines = stdin.read().replace('\r', '').split('\n')

T = int(lines.pop(0))


def leq(x, y):
    return all(x[i] == y[i] for i in range(len(x)))


for CN in range(1, T + 1):
    N, L = lines.pop(0).split(' ')
    N = int(N)
    L = int(L)
    # outlets = [map(int, x) for x in lines.pop(0).split(' ')]
    # devices = [map(int, x) for x in lines.pop(0).split(' ')]
    outlets = map(lambda x: int(x, 2), lines.pop(0).split(' '))
    devices = sorted(map(lambda x: int(x, 2), lines.pop(0).split(' ')))

    # d_ones = [0 for _ in range(L)]
    # o_ones = [0 for _ in range(L)]
    # o_comp = [0 for _ in range(L)]
    # for device in devices:
    #     for i, digit in enumerate(device):
    #         if digit:
    #             d_ones[i] += 1
    # for outlet in outlets:
    #     for i, digit in enumerate(outlet):
    #         if digit:
    #             o_ones[i] += 1
    #         else:
    #             o_comp[i] += 1
    # print "Outlets:", outlets
    # print "Devices:", devices
    # print o_ones
    # print o_comp
    # print d_ones
    # switches = 0
    # for i, dsum in enumerate(d_ones):
    #     if dsum == o_ones[i]:
    #         continue
    #     elif dsum == o_comp[i]:
    #         switches += 1
    #     else:
    #         switches = 99999
    #         break
    # print outlets, devices
    min_s = L+1
    for switches in range(1 << L):
        newoutlets = sorted(map(lambda x: x ^ switches, outlets))
        s_count = bin(switches).count('1')
        if leq(newoutlets,devices) and s_count < min_s:
            min_s = s_count

    stdout.write("Case #" + str(CN) + ': ')
    if min_s > L:
        stdout.write("NOT POSSIBLE\n")
    else:
        stdout.write(str(min_s) + '\n')
