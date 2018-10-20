#!/usr/bin/env python


def read():
    raw_input()
    aList = map(list, raw_input().split())
    bList = map(list, raw_input().split())
    return aList, bList


def work(cases, (aList, bList)):
    minV = 1<<20

    for toSet in bList:
        toXOR = []
        for i in range(len(toSet)):
            toXOR.append(aList[0][i] != toSet[i])

        isOk = True
        for A in aList:
            newA = []
            for i in range(len(A)):
                newA.append('1' if int(A[i]) ^ toXOR[i] else '0')
            
            if newA not in bList:
                isOk = False
                break

        if isOk:
            minV = min(minV, sum(toXOR))

    if minV == 1<<20:
        print "Case #%d: NOT POSSIBLE" % cases
    else:
        print "Case #%d: %d" % (cases, minV)

    
if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
