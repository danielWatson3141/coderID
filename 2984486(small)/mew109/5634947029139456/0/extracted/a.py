#!/usr/bin/env python
import sys

smallest = 999
frec = []

def flip(ques, req, offset, N, L, nflip):
    global smallest
    # end
    if nflip > smallest:
        return
    elif offset >= L:
        a = sorted(ques)
        b = sorted(req)
        res = 1
        for i in range(N):
            if a!=b:
                res = 0
                break
        if res == 1 and nflip < smallest:
            smallest = nflip
        return
    # not flip
    frec.append(0)
    flip(ques, req, offset+1, N, L, nflip)
    del frec[-1]
    # flip
    for i in range(N):
        a = int(ques[i][offset])
        tmp = list(ques[i])
        tmp[offset] = str(1-a)[0]
        ques[i] = ''.join(tmp)
    frec.append(1)
    flip(ques, req, offset+1, N, L, nflip+1)
    del frec[-1]
    # flip back
    for i in range(N):
        a = int(ques[i][offset])
        tmp = list(ques[i])
        tmp[offset] = str(1-a)[0]
        ques[i] = ''.join(tmp)



def runxor(ques, req, offset, N, L):
    xorr = 0;
    for i in range(N):
        a = int(ques[i][offset])
        b = int(req[i][offset])
        xorr = xorr ^ a ^ b
    return xorr

def same(ques, req, offset, N, L):
    for i in range(N):
        a = int(ques[i][offset])
        b = int(req[i][offset])
        if a != b:
            return 0
    return 1

line = sys.stdin.readline().strip()
cases = int(line)

for i in range(cases):
    N, L = map(int, sys.stdin.readline().strip().split(' ', 1))
    ques = sys.stdin.readline().strip().split(' ')
    req = sys.stdin.readline().strip().split(' ')
    smallest = 999
#    nflip = 0
#    impossible = 0
#    for j in range(L):
#        isxor =  runxor(ques, req, j, N, L)
#        issame =  runxor(ques, req, j, N, L)
#        if isxor == 1:
#            nflip += 1
#        if isxor==0 and issame==0:
#            impossible = 1
#            break
    flip(ques, req, 0, N, L, 0)
    sys.stdout.write("Case #%d: " % (i+1))
    if smallest == 999:
        sys.stdout.write("NOT POSSIBLE\n")
    else:
        sys.stdout.write("%d\n" % smallest)




