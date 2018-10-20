def num_ones(n):
    count = 0
    while n > 0:
        count += n % 2
        n /= 2
    return count

def solve(L, outlets, devices):
    outlets = [int(a,2) for a in outlets]
    devices = set(int(a,2) for a in devices)

    min_toggles = None
    for i in range(2**L):
        tmp = set(a^i for a in outlets)
        if tmp == devices:
            toggles = num_ones(i)
            if min_toggles is None or toggles < min_toggles:
                min_toggles = toggles

    if min_toggles is None:
        return "NOT POSSIBLE"
    return str(min_toggles)

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(1, T+1):
        N,L = map(int, raw_input().split())
        outlets = raw_input().split()
        devices = raw_input().split()
        print "Case #%d: %s" % (i, solve(L, outlets, devices))
