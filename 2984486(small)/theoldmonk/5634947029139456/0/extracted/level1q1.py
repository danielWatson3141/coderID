def difference(g,h):
    i = 0
    j = ''
    k = 0
    while (i < len(g)):
        if g[i] == h[i]:
            i = i+1
            j = j+'0'
        else:
            j = j+'1'
            i = i+1
            k = k+1
    return [j,k]
def intstring(y):
    w = 0
    while (w < len(y)):
        y[w] = int(y[w])
        w = w+1
    return y
def change(m,n):
    o = 0
    p =''
    while (o < len(m)):
        if (n[o] == '0'):
            if (m[o] == '0'):
                p = p+'0'
                o = o+1
            else:
                p = p+'1'
                o = o+1
        else:
            if (m[o] == '0'):
                p = p+'1'
                o = o+1
            else:
                p = p+'0'
                o = o+1
    return p
fil = open('/home/cse/btech/cs1130260/workfile.txt')
sumit = open("/home/cse/btech/cs1130260/output.txt","w")
a = int(fil.readline())
x = 1
while (a > 0):
    b = fil.readline()
    swi,cha = [int(i) for i in b.split()]
    c = fil.readline()
    initial = c.split()
    d = fil.readline()
    final = d.split()
    f = 0
    e = []
    l = []
    while (f < swi):
        e.append(difference(final[0],initial[f])[1])
        l.append(difference(final[0],initial[f])[0])
        f = f+1
    q = 0
    ans = 10000
    print e
    print l
    while (q < swi):
        r = 0
        s = []
        while (r < swi):
            s.append(change(initial[r],l[q]))
            r = r+1
        ss = intstring(s)
        aa = intstring(final)
        ss.sort()
        aa.sort()
        if (ss == aa):
            ans = min(ans,e[q])
            q = q+1
            print ans
        else:
            q = q+1
            print ans
    if (ans == 10000):
        sumit.write("Case #%s: NOT POSSIBLE\n" % (x))
    else:
        sumit.write("Case #%s: %s\n" % (x,ans))
    x = x+1
    a = a-1
sumit.close()
                    
                    



















    
