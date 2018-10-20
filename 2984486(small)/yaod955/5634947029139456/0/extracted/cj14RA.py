f = open('A-small-attempt0.in','r')
#f = open('test.txt','r')
n = int(f.readline())
cases = []
for i in range(n):
    count = -1
    s = 'Case #'+`i+1`+': '
    t = f.readline().split();
    start = f.readline().split();
    end = f.readline().split();
    sc,ec = {},{}
    for x in start :
        sc[x] = sc.get(x,0)+1
    for y in end :
        ec[y] = ec.get(y,0)+1
    for j in range(2**int(t[1])) :
        k=str(bin(j))[2:].zfill(int(t[1]));
        if all(sc.get(''.join('0' if a == b else '1' for a, b in zip(z,k))) == ec.get(z) for z in ec.keys()) :
            count = str(bin(j)).count('1')
            break;
    if count==-1 : s += 'NOT POSSIBLE'
    else : s += `count`
    cases.append(s)
f.close()
g = open('outputA.txt','w')
for z in cases :
    g.write(z+'\n')
g.close()