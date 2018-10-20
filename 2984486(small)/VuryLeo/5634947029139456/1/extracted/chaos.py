import sys
from collections import Counter

def matchHead(splits, i):
    noSwitchPos = True
    switchPos = True
    switchAns = 0xffff
    noSwitchAns = 0xffff
    if len(splits[0]['origin']) == 0:
        return 0
    if len(splits[0]['origin'][0]) == i:
        return 0
    for split in splits:
        cnto = Counter(map(lambda x:x[i], split['origin']))
        cntt = Counter(map(lambda x:x[i], split['target']))
        if cnto['0'] != cntt['0']:
            noSwitchPos = False
        if cnto['0'] != cntt['1']:
            switchPos = False
    if noSwitchPos:
        nsSplits = []
        for split in splits:
            no0 = [x for x in split['origin'] if x[i] == '0']
            no1 = [x for x in split['origin'] if x[i] == '1']
            nt0 = [x for x in split['target'] if x[i] == '0']
            nt1 = [x for x in split['target'] if x[i] == '1']
            ns0 = {
                'origin': no0,
                'target': nt0
            }
            ns1 = {
                'origin': no1,
                'target': nt1
            }
            if len(no0) != 0:
                nsSplits.append(ns0)
            if len(no1) != 0:
                nsSplits.append(ns1)
        noSwitchAns = matchHead(nsSplits, i + 1)
    if switchPos:
        sSplits = []
        for split in splits:
            o0 = [x for x in split['origin'] if x[i] == '0']
            o1 = [x for x in split['origin'] if x[i] == '1']
            t0 = [x for x in split['target'] if x[i] == '0']
            t1 = [x for x in split['target'] if x[i] == '1']
            s0 = {
                'origin': o0,
                'target': t1
            }
            s1 = {
                'origin': o1,
                'target': t0
            }
            if len(o0) != 0:
                sSplits.append(s0)
            if len(o1) != 0:
                sSplits.append(s1)
        switchAns = matchHead(sSplits, i + 1)
    return min(noSwitchAns, switchAns + 1)

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        n, l = map(int, sys.stdin.readline().split())
        origin = sys.stdin.readline().split()
        target = sys.stdin.readline().split()
        splits = [{
            'origin': origin,
            'target': target
        }]
        ans = matchHead(splits, 0)
        if ans > l:
            ans = "NOT POSSIBLE"
        sys.stdout.write("{}\n".format(ans))

