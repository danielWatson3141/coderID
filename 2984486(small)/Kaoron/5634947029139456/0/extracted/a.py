import fileinput
import itertools as it

def print_result(n, res):
    print 'Case #%d: %s'%(n, res)

data = fileinput.input()

nbcases = int(data.next())

binint = lambda s: int('0b'+s,2)

for i in range(1,nbcases+1):
    n,l = map(int,data.next().strip().split())
    flows = map(binint,data.next().strip().split())
    devices = set(map(binint,data.next().strip().split()))

    shorter = l+1
    for k in range(2**(l+1)):
        _flows = set([flow^k for flow in flows])
        #print flows, devices
        winner = _flows == devices
        if winner:
            switches = len(filter(int,str(bin(k))[2:]))
            shorter = switches if switches < shorter else shorter

    if shorter < l+1:
        print_result(i, shorter)
    else:
        print_result(i,'NOT POSSIBLE')

