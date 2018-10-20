#pylint: disable=missing-docstring,invalid-name
import sys
import os

IMPOSSIBLE = 'NOT POSSIBLE'

def checkFlows(N, flows, devs):
    return len(flows.intersection(devs)) == N

def applyFlips(L, flows, flips):
    result = []
    for oldFlow in flows:
        for flip in flips:
            oldFlow = oldFlow ^ (1 << (L - 1 - flip))
        result.append(oldFlow)
    return result

def getAllSeqs(initial, targetLen):
    if targetLen == 0:
        return []
    if targetLen == 1:
        return [[x] for x in initial]
    result = []
    for pos, x in enumerate(initial[:-targetLen + 1]):
        for seq in getAllSeqs(initial[pos + 1:], targetLen - 1):
            result.append([x] + seq)
    return result

def solve(N, L, flows, devs):
    flips = {} # True if flipping is mandatory, False otherwise
    for i in range(L):
        flowCount = sum(int(flow[i]) for flow in flows)
        devCount = sum(int(dev[i]) for dev in devs)
        if flowCount + devCount == N:
            # flipping might be needed
            flips[i] = flowCount != devCount
        elif flowCount == devCount:
            # no flip needed
            continue
        else:
            # impossible to achieve
            return IMPOSSIBLE
    # we now have all flippings that we can/have to do
    # try to find out if any of them gives good results
    intDevs = set(int(dev, 2) for dev in devs)
    intFlows = [int(flow, 2) for flow in flows]
    # first do all mandatory flips
    mandFlips = [flip for (flip, mandatory) in flips.iteritems() if mandatory]
    auxFlips = [flip for (flip, mandatory) in flips.iteritems() if not mandatory]
    flipCount = len(mandFlips)
    intFlows = applyFlips(L, intFlows, mandFlips)
    if checkFlows(N, set(intFlows), intDevs):
        # if flipping mandatory is enough - return it
        return flipCount

    for auxCount in xrange(len(auxFlips)):
        for flippings in getAllSeqs(auxFlips, auxCount):
            if checkFlows(N, set(applyFlips(L, intFlows, flippings)), intDevs):
                return flipCount + auxCount
    return IMPOSSIBLE

def main():
    with open(sys.argv[1], 'r') as inp, open('%s.out' % (os.path.splitext(sys.argv[1])[0]), 'w') as out: #pylint: disable=line-too-long
        T = int(inp.readline())
        for t in xrange(T):
            N, L = [int(x) for x in inp.readline().split()]
            flows = inp.readline().split()# [int(x, 2) for x in inp.readline().split()]
            devs = inp.readline().split() #[int(x, 2) for x in inp.readline().split()]
            out.write('Case #%s: %s\n' % (t + 1, solve(N, L, flows, devs)))

if __name__ == '__main__':
    main()
