__author__ = 'Levan Kasradze'

import itertools
import copy

fin = open('a.in')
fout = open('a.out', 'w')
T = int(fin.readline())
for t in range(1, T + 1):
    fout.write('Case #' + str(t) + ': ')
    line = fin.readline().strip().split()
    n = int(line[0])
    l = int(line[1])
    outlets = fin.readline().strip().split()
    devices = fin.readline().strip().split()
    o = []
    for i in range(n):
        o.append([])
        for j in outlets[i]:
            if j == '0':
                o[i].append(0)
            else:
                o[i].append(1)
    d = []
    for i in range(n):
        d.append([])
        for j in devices[i]:
            if j == '0':
                d[i].append(0)
            else:
                d[i].append(1)

    index = [i for i in range(l)]
    found = False
    for i in range(l):
        if not found:
            for j in itertools.combinations(index, i):
                outlets = copy.deepcopy(o)
                for k in j:
                    for outlet in outlets:
                        outlet[k] = 1 - outlet[k]

                found = True
                for k in d:
                    if k in outlets:
                        outlets.remove(k)
                    else:
                        found = False
                        break

                if found:
                    fout.write(str(i) + '\n')
                    break

    if not found:
        fout.write('NOT POSSIBLE\n')
fin.close()
fout.close()