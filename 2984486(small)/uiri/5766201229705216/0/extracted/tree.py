import sys, copy

def check_full(kid, kidlist, treedict):
    totalfullkids = 1
    if kid in kidlist:
        kidstocheck = treedict[kid]
        while len(kidstocheck):
            newkidstocheck = []
            for grandkid in kidstocheck:
                if grandkid in kidlist:
                    totalfullkids += 1
                    greatgrandkids = treedict[grandkid]
                    try:
                        greatgrandkids.remove(grandkid)
                        newkidstocheck += greatgrandkids
                    except ValueError:
                        pass
            kidstocheck = newkidstocheck
    return totalfullkids

input = sys.stdin.readlines()
input.reverse()
cases = int(input.pop())
for case in xrange(1,cases+1):
    nodes = int(input.pop())
    treedict = {}
    for i in xrange(nodes-1):
        pair = input.pop().strip().split(' ')
        left = pair[0]
        right = pair[1]
        try:
            treedict[left].append(right)
        except KeyError:
            treedict[left] = [right]
        try:
            treedict[right].append(left)
        except KeyError:
            treedict[right] = [left]
    roots = []
    fullkids = []
    for k in treedict:
        if len(treedict[k]) == 2:
            roots.append(k)
        else:
            fullkidlen = len(treedict[k])
            if fullkidlen == 3 or fullkidlen == 1:
                fullkids.append(k)
    minrem = nodes-1
    for root in roots:
        torem = nodes-1
        for kid in treedict[root]:
            if kid != root:
                torem -= check_full(kid, fullkids, treedict)
        if torem < minrem:
            minrem = torem
    print "Case #"+str(case)+": "+str(minrem)
