import os
import math
import copy
import sys

def tempt(h,w,k,need1):
    #print(h,need1,k)
    if sorted(h)==w:
        return need1
    elif k==len(mark):
        return -1
    else:
        try1 = tempt(h,w,k+1,need1)
        h1 = copy.deepcopy(h)
        for i in range(n):
            h1[i][mark[k]] = 1-h[i][mark[k]]
        try2 = tempt(h1,w,k+1,need1+1)
        #print(try1,try2)
        if try2==-1 and try1==-1:
            return -1
        elif try2!=-1 and try1==-1:
            return try2
        elif try1!=-1 and try2==-1:
            return try1
        else:
            return min(try1,try2)
        

os.chdir('C:/Python33/20141A')
f = open('A-small-attempt2.in','r')
fo = open('A-small.out','w')
#f = open('A-large.in','r')
#fo = open('A-large.out','w')
T = int(f.readline())
for ite in range(T):
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    temp = str.split(f.readline())
    n,l = int(temp[0]),int(temp[1])
    have = [[0 for j in range(l)] for i in range(n)]
    want = [[0 for j in range(l)] for i in range(n)]
    haven = [0]*l
    wantn = [0]*l
    temp = str.split(f.readline())
    for i in range(n):
        for j in range(l):
            have[i][j] = int(temp[i][j])
            if have[i][j]==1:
                haven[j] = haven[j]+1
    temp = str.split(f.readline())
    for i in range(n):
        for j in range(l):
            want[i][j] = int(temp[i][j])
            if want[i][j]==1:
                wantn[j] = wantn[j]+1
    # count
    want = sorted(want)
    #print(have,want)
    flag = 1
    for i in range(l):
        if haven[i]!=wantn[i] and haven[i]!=n-wantn[i]:
            flag = 0
    if flag==0:
        fo.write('NOT POSSIBLE\n')
    else:
        mark = list()
        need = 0
        for j in range(l):
            if haven[j]==n-wantn[j] and 2*haven[j]!=n:
                for i in range(n):
                    have[i][j] = 1-have[i][j]
                need = need+1
            if 2*haven[j]==n:
                mark.append(j)
        #print(have,want)
        res = tempt(have,want,0,need)
        if res==-1:
            fo.write('NOT POSSIBLE\n')
        else:
            fo.write(str(res))
            fo.write('\n')
    print(ite)
fo.close()

