def solve(outs, devs):
    outs = [list(e) for e in outs]
    devs = [list(e) for e in devs]
    devs.sort()
    best = 100
    if sorted(outs) == devs:
        return 0

    N = len(outs)
    L = len(outs[0])

    for z in range(2**L):
        v = bin(z).count('1')
        if v >= best:
            continue
        new_outs = []
        for o in outs:
            new_outs.append(list(o))
        for j in range(L):
            if ((L - len(bin(z)[2:])) * '0' + bin(z)[2:])[j] == '1':
                for i in range(N):
                    if new_outs[i][j] == '1':
                        new_outs[i][j] = '0'
                    else:
                        new_outs[i][j] = '1'
        if sorted(new_outs) == devs:
            best = v

    if best == 100:
        return "NOT POSSIBLE"
    else:
        return best

def do_case(case_num, outs, devs):
    print "Case #%d: %s" % (case_num, solve(outs, devs))

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        raw_input()
        outs = raw_input().split()
        devs = raw_input().split()
        do_case(case_num, outs, devs)
    
if __name__ == "__main__":
    main()
