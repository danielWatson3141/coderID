T = int(raw_input().strip())


def compare(list1, list2, limit):
    nlist1 = sorted([el[:(limit + 1)] for el in list1])
    nlist2 = sorted([el[:(limit + 1)] for el in list2])
    return nlist1 == nlist2

for i in xrange(T):
    N, L = map(int, raw_input().strip().split(' '))
    outlets = map(lambda x: map(int, list(x)), raw_input().strip().split(' '))
    items = map(lambda x: map(int, list(x)), raw_input().strip().split(' '))
    new_outlets = [[0 for _a in xrange(L)] for _ in xrange(N)]

    possible = True
    total = 0
    for k in xrange(L):
        ox, oy, ix, iy = 0, 0, 0, 0
        for j in xrange(N):
            if outlets[j][k] == 1:
                ox += 1
            else:
                oy += 1
            if items[j][k] == 1:
                ix += 1
            else:
                iy += 1

        if (ox, oy) == (ix, iy) and ox == oy:
            for j in xrange(N):
                if outlets[j][k] == 1:
                    new_outlets[j][k] = 1
                else:
                    new_outlets[j][k] = 0
            if compare(new_outlets, items, k):
                continue
            for j in xrange(N):
                if outlets[j][k] == 1:
                    new_outlets[j][k] = 0
                else:
                    new_outlets[j][k] = 1
            if compare(new_outlets, items, k):
                total += 1
                continue
            else:
                possible = False
                break
        elif (ox, oy) == (ix, iy):
            for j in xrange(N):
                if outlets[j][k] == 1:
                    new_outlets[j][k] = 1
                else:
                    new_outlets[j][k] = 0
            if compare(new_outlets, items, k):
                continue
            else:
                possible = False
                break
        elif (oy, ox) == (ix, iy):
            for j in xrange(N):
                if outlets[j][k] == 1:
                    new_outlets[j][k] = 0
                else:
                    new_outlets[j][k] = 1
            if compare(new_outlets, items, k):
                total += 1
                continue
            else:
                possible = False
                break
        else:
            possible = False
            break

    # print "outlets: %s" % sorted(outlets)
    # print "items: %s" % sorted(items)
    # print "new_outlets: %s" % sorted(new_outlets)
    if not possible:
        print "Case #%s: NOT POSSIBLE" % (i + 1)
    else:
        print "Case #%s: %s" % (i + 1, total)
