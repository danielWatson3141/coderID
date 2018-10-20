#Joe Snider
#4/14
#generate test cases for codejam q3
#
#This calculates the magic number to distinguish the classes
# res is 5.78505808653e+13


import random
import numpy as np

MAGIC = 1

def good(digits):
    a = range(digits)
    for k in range(digits):
        p = random.randint(k, digits-1)
        q = a[p]
        a[p] = a[k]
        a[k] = q
    return a

def bad(digits):
    a = range(digits)
    for k in range(digits):
        p = random.randint(0, digits-1)
        q = a[p]
        a[p] = a[k]
        a[k] = q
    return a

def val(a):
    ret = 0
    for i in range(len(a)):
        ret += (len(a)-i)*(len(a)-i)*(a[i]-i)*(a[i]-i)
    return ret

def test(a):
    if val(a) > MAGIC:
        return "GOOD"
    else:
        return "BAD"

if __name__ == "__main__":
    N=1000
    iters = 600
    s = 0#np.zeros(N-1)
    ss = 0#np.zeros(N-1)
    #out = open("test.txt", 'w')
    for i in range(iters):
        #s += np.diff(np.array(good(N)))
        #ss += np.diff(np.array(bad(N)))
        
        ds = val(good(N))
        dss = val(bad(N))
        s += ds
        ss += dss
        #out.write(str(ds)+" "+str(dss)+"\n")
    #print float(s)/iters
    #print float(ss)/iters
    #print 0.5*(float(s)+float(ss))/iters
    MAGIC = 0.5*(float(s)+float(ss))/iters
    #out.close()

    '''correct = 0
    for i in range(120):
        if test(good(N)) == "GOOD":
            correct += 1
    print "found", correct, "out of", 120'''

    inp = open("C-small-attempt1.in", 'r')
    row = 0
    count = 1
    for line in inp:
        if (row%2)==0 and row > 0:
            s = line.split()
            a = []
            for i in range(1000):
                a.append(float(s[i]))
            print "Case #%d: "%(count),
            count += 1
            if test(a)=="GOOD":
                print "GOOD"
            else:
                print "BAD"
        row += 1
        
    

       
