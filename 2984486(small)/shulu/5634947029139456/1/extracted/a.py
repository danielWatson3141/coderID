import sets

def check(devices, outlets):
    token = devices[0]
    ans = False
    l = len(bin(token))
    for outlet in outlets:
        diff = token ^ outlet
        if bin(diff).count("1") >= l:
            continue;
        dSet = sets.Set(devices)
        for outletI in outlets:
            try:
                dSet.remove(outletI ^ diff)
            except KeyError:
                continue
        l = bin(diff).count("1")
        ans = True
    return l if ans else -1

for n in xrange(int(raw_input())):
    N, L = map(int, raw_input().split(' '))
    outlets = map(lambda x: int(x, 2), raw_input().split(' '))
    devices = map(lambda x: int(x, 2), raw_input().split(' '))
    token = devices[0]
    ans = False
    l = len(bin(token))
    for outlet in outlets:
        failed = False
        diff = token ^ outlet
        if bin(diff).count("1") >= l:
            continue;
        dSet = sets.Set(devices)
        for outletI in outlets:
            try:
                dSet.remove(outletI ^ diff)
            except KeyError:
                failed = True
                break
        if failed:
            continue
        l = bin(diff).count("1")
        ans = True
    print "Case #%d: %s" % (n+1, "NOT POSSIBLE" if not ans else str(l))


