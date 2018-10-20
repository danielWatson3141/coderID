T = input()

for CN in xrange(1, T+1):
    N, L = [long(i) for i in raw_input().split()]
    outlets = raw_input().split()
    devices = raw_input().split()

    allmasks = []
    for i in xrange(N):
        dev = devices[i]
        devimasks = set()
        for j in xrange(N):
            out = outlets[j]
            mask = ""
            for k in xrange(L):
                if dev[k] == out[k]:
                    mask += "0"
                else:
                    mask += "1"
            devimasks.add(mask)
        allmasks.append(devimasks)
    
    inter = set.intersection(*allmasks)

    ans = None
    for mask in inter:
        c = 0
        for x in mask:
            if x == '1':
                c += 1

        if ans == None:
            ans = c

        ans = min(ans, c)

    if ans != None:
        print "Case #%d: %d" % (CN, ans)
    else:
        print "Case #%d: NOT POSSIBLE" % (CN,)

