def match(now,needed):
    now.sort()
    needed.sort()
    for i in range(len(now)):
        if now[i] != needed[i]:
            return True
    return False
def count(ar,l):
    ret = [0]*l
    for i in range(l):
        for s in ar:
            ret[i] += int(s[i])
    return(ret)
def compare(n,o,l):
    ret = [0]*l
    for i in range(l):
        if n[i] != o[i]:
            ret[i] = 1
    return tuple(ret)
f = open("A-large.in","r")
o = open("A-large-answers.txt","w")
T = int(f.readline())
for t in range(1,T+1):
    inp = [int(a) for a in f.readline().split()]
    n = inp[0]
    l = inp[1]
    lifts = [0]*l
    start = [a for a in f.readline().split()]
    needed = [a for a in f.readline().split()]
    cnow = count(start,l)
    cneeded = count(needed,l)
    print("case",t,cnow,cneeded,start,needed)
    op = set([compare(start[0],n,l) for n in needed])
    for i in range(1,n):
        op1 = set([compare(start[i],n,l) for n in needed])
        op = op&op1
    if len(op) == 0:
        o.write("Case #"+str(t)+": NOT POSSIBLE"+"\n")
    else:
        o.write("Case #"+str(t)+": "+str(min([a.count(1) for a in op]))+"\n")
o.close()
#o.write("Case #"+str(t)+": NOT POSSIBLE"+"\n")
#o.write("Case #"+str(t)+": "+str(lifts.count(1))+"\n")
