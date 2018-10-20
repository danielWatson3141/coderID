def flip(a, b):
    return "".join(['0' if x == y else '1' for (x, y) in zip(a, b)])

def solve(outlets, devices, pattern):
    ds = [flip(d, pattern) for d in devices]
    for o in outlets:
        try:
            ds.remove(o)
        except:
            return False
    return True

def chargingChaos(outlets, devices):
    ret = 10000
    for d in devices:
        pattern = flip(outlets[0], d)
        if solve(outlets, devices, pattern):
            ret = min(ret, pattern.count('1'))
    if ret >= 10000:
        return "NOT POSSIBLE"
    return str(ret)

if __name__ == "__main__":
    T = input()
    for c in range(1, T + 1):
        (N, L) = map(int, raw_input().split(" "))
        outlets = raw_input().split(" ")
        devices = raw_input().split(" ")
        print 'Case #%d: %s' % (c, chargingChaos(outlets, devices))
