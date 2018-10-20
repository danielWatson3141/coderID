def solve(f):
    N, L = map(int, f.readline().split())
    sockets = [int(s, base=2) for s in f.readline().split()]
    devices = [int(s, base=2) for s in f.readline().split()]
    #print sockets, devices
    candidates = set()
    for s in sockets:
        difs = set([s ^ d for d in devices])
        #print difs
        candidates = candidates & difs if candidates else difs
        if len(candidates) == 0:
            break
        #print candidates
    if len(candidates) == 0:
        return "NOT POSSIBLE"
    return str(min([b.count('1') for b in map(bin, candidates)]))


test_answer = {
    1: "1",
    2: "NOT POSSIBLE",
    3: "0",
}

if __name__ == '__main__':
    import sys
    test = False
    try:
        file_name = sys.argv[1]
    except IndexError:
        file_name = 'test.txt'
        test = True
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    with open(file_name) as f:
        T = int(f.readline())
        for i in range(1, T + 1):
            answer = solve(f)
            print "Case #%d: %s" % (i, answer)
            if test:
                assert answer == test_answer[i]
