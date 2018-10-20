#inputFileName = "test.in"
#inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
#inputFileName = "A-small-attempt2.in"
#inputFileName = "A-small-attempt3.in"
inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def parseBits(s):
    return map(int, s)


def calcBits(bs, pos):
    cnt = 0
    for b in bs:
        if b[pos] == 1:
            cnt += 1
    return cnt


def invertBits(bs, pos):
    copy = []
    for b0 in bs:
        b = b0[:]
        if b[pos] == 1:
            b[pos] = 0
        else:
            b[pos] = 1
        copy.append(b)
    return sorted(copy)



def comp(sources, devices, pos, N):
    sources = sorted(sources)
    devices = sorted(devices)
    for x in xrange(N):
        s = sources[x][0:pos]
        d = devices[x][0:pos]
        if s != d:
            return False
    return True


def test(sources, devices, sCnt, dCnt, pos, N, L):
    if pos >= L:
        sources = sorted(sources)
        devices = sorted(devices)
        if sources == devices:
            print "Good"
            print sources
            print devices
            return 0
        else:
            return -1
    if sCnt[pos] == dCnt[pos]:
        if not comp(sources, devices, pos, N):
            return -1
        r = test(sources, devices, sCnt, dCnt, pos + 1, N, L)
        if r != -1:
            return r
    if sCnt[pos] + dCnt[pos] == N:
        copy = invertBits(sources, pos)
        if not comp(copy, devices, pos, N):
            return -1
        r = test(copy, devices, sCnt, dCnt, pos + 1, N, L)
        if r != -1:
            print "Invert " + str(pos)
            return r + 1

    return -1


def testBF(sources0, devices0, sCnt, dCnt, pos, N, L):
    sources = sources0[:]
    devices = devices0[:]
    if pos >= L:
        sources = sorted(sources)
        devices = sorted(devices)
        #        print 'cmp'
        #        print sources
        #        print devices
        #        print str(sources == devices)
        if sources == devices:
        #            print "Good"
        #            print sources
        #            print devices
            return 0
        else:
            return -1

    r = testBF(sources[:], devices[:], sCnt, dCnt, pos + 1, N, L)
    if r != -1:
        return r


    r = testBF(invertBits(sources, pos), devices[:], sCnt, dCnt, pos + 1, N, L)
    if r != -1:
    #        print "Invert " + str(pos)
        return r + 1

    return -1


def calcSingleTest(f):
    line = f.readline()
    N = int(line.split()[0])
    L = int(line.split()[1])
    line = f.readline()
    #print line
    sources = map(parseBits, line.split())
    #sources = line.split()
    line = f.readline()
    #print line
    devices = map(parseBits, line.split())
    #devices = line.split()
    print sources
    print devices

    sCnt = []
    dCnt = []
    for pos in xrange(L):
        sCnt.append(calcBits(sources, pos))
        dCnt.append(calcBits(devices, pos))
    print sCnt
    print dCnt

    for pos in xrange(L):
        if sCnt[pos] != dCnt[pos] and sCnt[pos] + dCnt[pos] != N:
            return "NOT POSSIBLE"

    #r2 = testBF(sources[:], devices[:], sCnt, dCnt, 0, N, L)
    r = test(sources[:], devices[:], sCnt, dCnt, 0, N, L)
#    if r != r2:
#        print "!!!!!! " + str(r) + " " + str(r2)
    if r == -1:
        return "NOT POSSIBLE"
    else:
        print "Good " + str(r)
        return r


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




