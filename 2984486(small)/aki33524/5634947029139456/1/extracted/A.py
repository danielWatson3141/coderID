INF = 10**8

fin = open("A-large.in")
fout = open("A.out", "w")
T = int(fin.readline())

for t in range(1, T+1):
    ans = INF
    
    N, L = map(int, fin.readline().split(" "))
    starts = [int(d, 2) for d in fin.readline().split(" ")]
    ends = [int(d, 2) for d in fin.readline().split(" ")]
    endsets = set(ends)
    
    for s in starts:
        for e in ends:
            a = s^e
            startsets = set([i^a for i in starts])
            if startsets == endsets:
                ans = min(ans, bin(a).count("1"))
    
    fout.write("Case #%d: " %t)
    if ans == INF:
        fout.write("NOT POSSIBLE\n")
    else:
        fout.write("%d\n" %ans)