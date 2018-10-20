import sys

sys.stdin = open('f.in')
debug, sys.stdout = sys.stdout, open('f.out', 'w')

def solve(n, l, outlets, devices):

    def possible(i, g, v):
        if i < len(g):
            if g[i] - v:
                for x in g[i] - v:
                    if possible(i + 1, g, v | {x}):
                        return True
                return False
            else:
                return False
        else:
            return True
        
    def switch(o, d):
        r = []
        for i in range(len(o)):
            if o[i] == d[i]:
                r.append('0')
            else:
                r.append('1')
        return ''.join(r)

    graphs = {}
    for i, o in enumerate(outlets):
        for j, d in enumerate(devices):
            g = graphs.setdefault(switch(o, d), [set() for k in range(n)])
            g[i].add(j)

    res = l + 1
    for s, g in graphs.items():
        if possible(0, g, set()):
            res = min(res, s.count('1'))

    return res if res < l + 1 else 'NOT POSSIBLE' 

t = int(input())
answer = 'Case #{0}: {1}'
for i in range(t):
    n, l = map(int, input().split())
    outlets = input().split()
    devices = input().split()
    print(answer.format(i + 1, solve(n, l, outlets, devices)))
sys.stdin.close()
sys.stdout.close()
