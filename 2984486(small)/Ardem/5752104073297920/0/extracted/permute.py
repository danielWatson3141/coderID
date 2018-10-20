fin = file("in.txt","r")
fout = file("out.txt","w")

t = int(fin.readline())

def permute(num,s):
    if s >= len(num):
        return []
    out = []
    hmm = []
    for i in range(len(num)):
        boot = list(num)
        boot[i],boot[s] = boot[s],boot[i]
        boo = ''.join(boot)
        out.append(boo)
    for o in out:
        hmm = hmm + permute(o,s+1)
    #print out,'*****', out + hmm, s, num
    return out + hmm

for i in range(t):
    n = int(fin.readline())
    perm = map(int,fin.readline().split(' '))
    if (perm[0] < 500):
        fout.write("Case #%d: BAD\n"%(i+1))
    else:
        fout.write("Case #%d: GOOD\n"%(i+1))

"""temp = ''.join([str(i) for i in range(4)])
gah = permute(temp,0)
print len(gah)

d = {}
for g in gah:
    if g not in d:
        d[g] = 1
    else:
        d[g] = d[g] + 1
d = sorted(d.items())
print d"""

fin.close()
fout.close()
