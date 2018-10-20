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
def solve(n,l):
    for i in range(n/70):
        if l[i]<=i:
            print i,l[i]
            return 'BAD'
    c=0
    for i in range(n/30):
        if l[i]<=i:
            c+=1;print i,l[i]
    if c>1:
        return 'BAD'
    c=0
    for i in range(n/15):
        if l[i]<=i:
            c+=1;print i,l[i]
    if c>2:
        return 'BAD'
    else:
        return 'GOOD'

def main():
    fi=file('c.in')
    fo=file('c.out','w')
    t=int(fi.readline())
    for ti in range(t):
        n=int(fi.readline())
        l=map(int,fi.readline().split())
        ans="Case #%d: %s"%(ti+1,solve(n,l))
        print ans
        fo.write(ans+'\n')
    fi.close()
    fo.close()

if __name__ == '__main__':
    main()
