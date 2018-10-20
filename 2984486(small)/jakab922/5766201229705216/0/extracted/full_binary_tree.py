T = int(raw_input().strip())
INF = 10 ** 16

for i in xrange(T):
    N = int(raw_input().strip())
    tree = [[] for _ in xrange(N)]
    for _ in xrange(N - 1):
        fr, to = map(int, raw_input().strip().split(' '))
        fr -= 1
        to -= 1
        tree[fr].append(to)
        tree[to].append(fr)

    was = {}
    ncount = {}

    for root in xrange(N):
        stack = [(root, None, False)]
        while stack:
            curr, par, rdy = stack.pop()
            if len(tree[curr]) == 1 and par is not None:   # leaf
                was[(curr, par)] = 0
                ncount[(curr, par)] = 1
            else:
                if rdy:
                    if (par is None and len(tree[curr]) not in (0, 2) or
                            par is not None and len(tree[curr]) not in (1, 3)):
                        if par is None:
                            if len(tree[curr]) > 2:
                                target = 2
                            else:
                                target = 0
                        else:
                            if len(tree[curr]) > 3:
                                target = 2
                            else:
                                target = 0
                        sizes = []
                        drops = []
                        for child in tree[curr]:
                            if child == par:
                                drops.append(0)
                                sizes.append(0)
                                continue
                            sizes.append(ncount[(child, curr)])
                            drops.append(was[(child, curr)])

                        if target == 0:
                            was[(curr, par)] = sum(sizes)
                            ncount[(curr, par)] = sum(sizes) + 1
                        else:
                            val = INF
                            lcurr = len(tree[curr])
                            ssizes = sum(sizes)
                            for j in xrange(lcurr - 1):
                                one = tree[curr][j]
                                if one == par:
                                    continue
                                for k in xrange(j + 1, lcurr):
                                    other = tree[curr][k]
                                    if other == par:
                                        continue
                                    if (ssizes - sizes[j] - sizes[k] + drops[j]
                                            + drops[k]) < val:
                                        val = (ssizes - sizes[j] - sizes[k] +
                                               drops[j] + drops[k])

                            was[(curr, par)] = val
                            ncount[(curr, par)] = sum(sizes) + 1
                    else:
                        # print
                        # print "root: %s" % root
                        # print "ncount: %s" % ncount
                        # print "was: %s" % was
                        # print "curr: %s" % curr
                        # print "par: %s" % par
                        # print "tree[curr]: %s" % tree[curr]
                        ncount[(curr, par)] = 1
                        was[(curr, par)] = 0
                        for child in tree[curr]:
                            if child == par:
                                continue
                            ncount[(curr, par)] += ncount[(child, curr)]
                            was[(curr, par)] += was[(child, curr)]
                else:
                    stack.append((curr, par, True))
                    for child in tree[curr]:
                        if child == par:
                            continue
                        if (child, curr) not in was:
                            stack.append((child, curr, False))

    res = min([was[(root, None)] for root in xrange(N)])
    print "Case #%s: %s" % (i + 1, res)
