'''
Created on 12/04/2014

@author: tianyizhu
'''
from multiprocessing import Process, Manager

def dfs(ci, res, n, l, fl, de, pos, bits):
    if res[ci] != "NOT POSSIBLE" and bits >= res[ci]:
        return
    if pos > l:
        return;
    fl.sort()
    match = True
    for i in xrange(n):
        if fl[i] != de[i]:
            match = False
            break
    if match:
        if res[ci] == "NOT POSSIBLE":
            res[ci] = bits
        if res[ci] > bits:
            res[ci] = bits
        return
    if pos == l:
        return
    fl1 = 0
    de1 = 0
    for i in xrange(n):
        if fl[i] & 1 << pos:
            fl1 += 1
        if de[i] & 1 << pos:
            de1 += 1
    if fl1 != de1 and fl1 != n - de1:
        return
    if fl1 == de1:
        dfs(ci, res, n, l, fl, de, pos + 1, bits)
    if fl1 == n - de1:
        for i in xrange(n):
            fl[i]^= 1 << pos
        dfs(ci, res, n, l, fl, de, pos + 1, bits + 1)
        for i in xrange(n):
            fl[i] ^= 1 << pos
    

def f(ci, res, n, l, fl, de):
    res[ci] = "NOT POSSIBLE"
    dfs(ci, res, n, l, fl, de, 0, 0)
    
if __name__ == "__main__":
    ps = []
    manager = Manager()
    fin = open("cc.in", "r")
    fout = open("cc.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in xrange(t):
        line = fin.readline().split(" ")
        n = int(line[0])
        l = int(line[1])
        fl = fin.readline().strip().split(" ")        
        de = fin.readline().strip().split(" ")
        for i in xrange(n):
            fl[i] = int(fl[i], 2)
            de[i] = int(de[i], 2)
        de.sort()
        p = Process(target=f, args=(ci, res, n, l, fl, de))
        ps.append(p)
        p.start()
    for ci in xrange(t):
        ps[ci].join()
        fout.write("Case #%d: %s\n" % (ci + 1, str(res[ci])))
    fout.close()
    fin.close()
