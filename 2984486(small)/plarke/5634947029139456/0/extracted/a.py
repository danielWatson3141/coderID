import pdb
f = open('A-small-attempt1.in')
t = int(f.readline())
out = open('a.out', 'w+')
for tc in range(t):
    n, l = [int(p) for p in f.readline().split()]
    start = f.readline().split()
    end = f.readline().split()
    #print(start)
    #print(end)
    shifts = set()
    for i in range(len(start)):
        #pdb.set_trace()
        s = set()
        for m in range(len(end)):
            v = tuple([x for x in range(len(start[i])) if start[i][x] != end[m][x]])
            s.add(v)
        if i != 0:
            shifts = s & shifts
        else:
            shifts = s
    if len(shifts) >= 1:
        result = str(min([len(r) for r in shifts]))
    else:
        result = 'NOT POSSIBLE'
    out.write('Case #{0}: {1}\n'.format(tc+1, result))
