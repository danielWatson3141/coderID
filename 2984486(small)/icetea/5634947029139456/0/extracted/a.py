import sys 
lines = sys.stdin.readlines()
T = int(lines[0])
for i in range(T):
    N, L = lines[i*3+1].split()
    N = int(N)
    L = int(L)
    inp = lines[i*3+2].split()
    req = lines[i*3+3].split()
    counts = []
    for j in range(N):
        tbc = []
        inpl = list(inp[j])
        reql = list(req[0])
        for k in range(L):
            if inpl[k] != reql[k]:
                tbc.append(k)
        tmp = inp[:]
        for m in range(N):
            for x in tbc:
                tmp[m] = list(tmp[m])
                if tmp[m][x] == "0":
                    tmp[m][x] = "1"
                else: tmp[m][x] = "0"
                tmp[m] = "".join(tmp[m])
        if set(tmp) == set(req): counts.append(len(tbc))
    if len(counts) == 0: print "Case #"+str(i+1)+": NOT POSSIBLE"
    else: print "Case #"+str(i+1)+": " + str(min(counts))
