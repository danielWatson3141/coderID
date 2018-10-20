infile = open('in')
outfile = open('out','w')

from itertools import combinations
from copy import deepcopy
def flip(l, index):
    for i in l:
        i[index] = 1-i[index]

n = int(infile.readline())
for casecounter in range(n):
    outfile.write('Case #' + str(casecounter+1) + ': ')
    n,l = [int(i) for i in infile.readline().split()]
    print(n,l)
    poss = True
    a = [[int(j) for j in i] for i in infile.readline().split()]
    b = [[int(j) for j in i] for i in infile.readline().split()]
    print(a,b)
    a2 = [sum(i) for i in zip(*a)]
    b2 = [sum(i) for i in zip(*b)]
    print(a2,b2)
    total = -1
    for i in range(l):
        if a2[i] != b2[i] and a2[i] != n-b2[i]:
            poss = False
            break
    print(a,b)
    a2 = deepcopy(a)
    if poss:
        out = False
        for i in range(l+1):
            for j in combinations(range(len(a2[0])),i):
                a2 = deepcopy(a)
                #print(j)
                for k in j:
                    flip(a2,k)
                    #print(a2,j)
                if sorted(a2) == sorted(b):
                    total = i
                    out = True
                    break
            if out:
                break
    if total != -1:
        outfile.write(str(total) + '\n')
    else:
        print("NOT POSSIBLE")
        outfile.write('NOT POSSIBLE\n')


'''
01 00
11 10
10 11

11
00
10

01
10

10
01

101
111

010
001



'''
