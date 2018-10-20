#p3
import sys
from math import sqrt

lines = sys.stdin.readlines()

t = int(lines[0])
result = []
for k in range(t):
    n = int(lines[2*k+1])
    dataset = map(float, lines[2*k+2].split())
    for i in range(n):
        delta = abs(dataset[i] - i)
        dataset[i] = delta if delta <= n/2 else n-delta
    avg = sum(dataset) / n
    dev = reduce(lambda x, s: (x-avg)*(x-avg)/n + s, dataset, 0)
    dev = sqrt(dev)
    sigma = dev / n
    result += [sigma]
    print "Case #%d:"%(k+1), "GOOD" if sigma > 0.015 else "BAD"
#result.sort()
#print result
#print result[t / 2]