#coding=utf8
#-------------------------------------------------------------------------------
# Name:        modulea
# Purpose:
#
# Author:      Administrator
#
# Created:     26/04/2014
# Copyright:   (c) Administrator 2014
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import copy

def solve(n,l,ei,eo):
    ci=[li.count(0) for li in zip(*ei)]
    co=[li.count(0) for li in zip(*eo)]
    res=[[0,copy.deepcopy(ei)]]
    for i in range(l):
        if ci[i]==co[i]:
            if ci[i]+co[i]==n:
                tmp=copy.deepcopy(res)
                for ri in res:
                    ri[0]+=1
                    for j in range(n):
                        ri[1][j][i]^=1
                res+=tmp
        elif ci[i]+co[i]==n:
            for ri in res:
                ri[0]+=1
                for j in range(n):
                    ri[1][j][i]^=1
        else:
            return "NOT POSSIBLE"
    res.sort()
    for ri in res:
        if sorted(ri[1])==sorted(eo):
            return str(ri[0])
    return "NOT POSSIBLE"

def main():
    fi=file('as.in')
    fo=file('a.out','w')
    t=int(fi.readline())
    for ti in range(t):
        n,l=map(int,fi.readline().split())
        ei=map(list,fi.readline().split())
        ei=[map(int,li) for li in ei]
        eo=map(list,fi.readline().split())
        eo=[map(int,li) for li in eo]
        ans="Case #%d: %s"%(ti+1,solve(n,l,ei,eo))
        print ans
        fo.write(ans+'\n')
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
