from collections import Counter
from itertools import combinations

maxSwitches = 11
pow2s = [2**i for i in range(maxSwitches) ]

numCases = input()
for caseNum in xrange(numCases):
    devices, length = map(int, raw_input().split())
    outlets = [ int(x, 2) for x in raw_input().split() ]
    devices = [ int(x, 2) for x in raw_input().split() ]

    devCount = Counter(devices)

    def findMinSwitches():
        for numSwitches in xrange(length+20):
            # print 'blaaoop', list(combinations(pow2s[:length], numSwitches))
            for subset in combinations(pow2s[:length], numSwitches):
                mask = 0
                for sub in subset:
                    mask = mask | sub

                swCount = Counter([ outlet ^ mask for outlet in outlets])
                # print 'boop', swCount, numSwitches
                if swCount==devCount:
                    return numSwitches

    result = findMinSwitches()
    if result is None:
        result = 'NOT POSSIBLE'
    print 'Case #{0}: {1}'.format(caseNum+1, result)
