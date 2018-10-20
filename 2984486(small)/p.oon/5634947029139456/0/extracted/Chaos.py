import sys
import itertools
sys.stdin = open('../input.txt')
sys.stdout = open('out.txt','w')

for t in range(int(input())):
    n,l = map(int,input().split(' '))

    outlet = [list(map(int,i)) for i in input().split(' ')]
    output = [list(map(int,i)) for i in input().split(' ')]
    output.sort()

    ll = [1] * l
    flip = [0] * l
    flips = 0

    outlets = [sum(outlet[j][i] for j in range(n)) for i in range(l)]
    outputs = [sum(output[j][i] for j in range(n)) for i in range(l)]
    
    flg = 0
    for i in range(l):
        if(outputs[i] == outlets[i]):
            if(outputs[i] != n/2):
                ll[i] = 0
        elif(outputs[i] == n-outlets[i]):
            flip[i] = 1
            flips += 1
            ll[i] = 0
        else:
            break
    else:
        flg = 1
    if not flg:
        print('Case #%d: NOT POSSIBLE' % (t+1))
        continue

    minflip = 999
    def validate():
        global minflip
        x = [[k^flip[j] for j,k in enumerate(i)] for i in outlet]
        if(sorted(x) == output):
            minflip = min(minflip,flips)

    def rec(i):
        global flips
        if i>=l:
            validate()
            return
        if ll[i]:
            flip[i] = 0
            rec(i+1)
            flip[i] = 1
            flips += 1
            rec(i+1)
            flips -= 1
        else:
            rec(i+1)
    rec(0)
    # o=minflip
    # print(ll)
    if(minflip == 999):
        print('Case #%d: NOT POSSIBLE' % (t+1))
        continue
    print('Case #%d: %d' % (t+1,minflip))
