from random import *
filein = open("PC.txt", "r")
out = open("PCout.txt", "w")
cases = int(filein.readline())
perm1 = []
perm2 = []
##for i in xrange(10000000):
##        a = [0]*1000
##        b = [0]*1000
##        for j in xrange(1000):
##            a[j] = j
##            b[j] = j
##        for j in xrange(1000):
##            p = randrange(j,1000);
##            a[j],a[p] = a[p],a[j]
##            p = randrange(0,1000);
##            b[j],b[p] = b[p],b[j]
##        perm1.append(a)
##        perm2.append(b)
for QQ in xrange(cases):
    num = filein.readline()
    nums = filein.readline().split()
    a = randrange(0,1)
    if a == 1:
        out.write("Case #" + str(QQ+1) + ": " + "GOOD" + "\n")
    else:
        out.write("Case #" + str(QQ+1) + ": " + "BAD" + "\n")
            
filein.close()
out.close()
    
