import math

def foo(p, c, l, o, d, o2, d2):
    for x in o2:
        if x not in d2:
           return -1
    if p >= l:
        return c
    o2a = o2[:]
    o2b = o2[:]
    d2a = d2[:]
    
    for x in range(0, len(o)):
        o2a[x] += o[x][p]
        
        if o[x][p] == "0":
            o2b[x] += "1"
        else:
            o2b[x] += "0"
        d2a[x] += d[x][p]
    #print(o2a)
    #print(o2b)
    a = foo(p+1, c, l, o, d, o2a, d2a)
    b = foo(p+1, c+1, l, o, d, o2b, d2a)
    if(a > -1 and b > -1):
        return min(a, b)
    if(a == -1):
        return b
    return a

inputs = open("in.txt").readlines()
output = open('out.txt', 'w')
t = int(inputs[0])
for i in range(1, t + 1):
    r = (i - 1) * 3 + 1
    p = inputs[r].rstrip().split(" ");
    n = int(p[0])
    l = int(p[1])
    
    o = inputs[r + 1].rstrip().split(" ")
    d = inputs[r + 2].rstrip().split(" ")

    #print(o, d);
    ans = foo(0, 0, l, o, d, [""]*n, [""]*n)
    
    if(ans == -1):
        answer = "Case #%d: NOT POSSIBLE\n"%(i)
    else:
        answer = "Case #%d: %d\n"%(i, ans)
    print(answer)
    
    output.write(answer)
output.close()
