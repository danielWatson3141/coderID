
sss = []
fff = []
ddd = []
el = []
import sys

def go(par,now):
    global ddd,fff,sss,el
    if par>=0:
        ddd[now] = ddd[par]+1
    else:
        #print now,len(ddd)
        ddd[now] = 0
    bf = [0,0]
    bs = [0,0]
    cnt = 0
    for x in el[now]:
        if x!=par:
            cnt += 1
            go(now,x)
            sss[now] += sss[x]
            tmp = sss[x]-fff[x]
            if sss[x]>bs[0]:
                bs[1] = bs[0]
                bs[0] = sss[x]
            else:
                bs[1] = sss[x]
            if tmp>bf[0]:
                bf[1] = bf[0]
                bf[0] = tmp
            elif tmp>bf[1]:
                bf[1] = tmp
    if cnt==0:
        fff[now] = 0
    elif cnt==1:
        fff[now] = bs[0]
    elif cnt==2:
        fff[now] = sss[now]-1-bf[0]-bf[1]
    elif cnt>=3:
        fff[now] = sss[now]-1-bf[0]-bf[1]
    #print "[INFO] now = %d, par = %d, cnt = %d. sss[now] = %d, fff[now] = %d, ddd[now] = %d" %(now,par,cnt,sss[now],fff[now],ddd[now])

def main(ifn='bin.txt',ofn='bout.txt'):
    sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n = int(inf.readline())
                global el
                el = [[] for i in xrange(n)]
                #print len(el)
                for i in xrange(n-1):
                    x,y = map(int,inf.readline().strip().split())
                    x -= 1
                    y -= 1
                    el[x].append(y)
                    el[y].append(x)
                #print el
                bestAnswer = n
                for i in xrange(n):
                    global ddd
                    ddd = [-1 for x in xrange(n)]
                    global sss
                    sss = [1 for x in xrange(n)]
                    global fff
                    fff = [0 for x in xrange(n)]
                    go(-1,i)
                    bestAnswer = min(bestAnswer,fff[i])
                    #print "[INFO] ================================"
                    #print "[INFO] bestAnswer = %d" %(bestAnswer)
                ouf.write("%d\n" %(bestAnswer))
                print bestAnswer
