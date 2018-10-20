from collections import deque,defaultdict

fin = open('A-small-attempt0.in')
fout = open('out.txt','w')

T = int(fin.readline())

cas = 1
while T!=0:
    T -= 1
    n, l = map(int,fin.readline().split())
    S1 = frozenset(fin.readline().split())
    S2 = frozenset(fin.readline().split())
    def trans(S,mask):
        def transone(s):
            sl = map(int,list(s))
            for i in range(l):
                if mask[i]=='1':
                    sl[i]= 1- sl[i]
            return ''.join(map(str,sl))
        return frozenset(map(transone,S))

    HSDict = defaultdict(lambda : 10000)

    fst = l/2
    snd = l - l/2
    for i in range(1<<fst):
    	mask = bin(i)[2:].zfill(fst) + ''.join(['0' * snd])
    	val = len(filter(lambda x:x=='1',mask))
    	HSDict[trans(S1,mask)] = min(HSDict[trans(S1,mask)],val)

    ans = 10000
    for i in range(1<<snd):
    	mask = ''.join(['0'*fst]) +  bin(i)[2:].zfill(snd)
    	val = len(filter(lambda x:x=='1',mask))
    	elem = trans(S2,mask)
    	if elem in HSDict:
    		ans = min(ans,HSDict[elem] + val)



    def out(casno,ans):
    	if ans!=10000:
        	outstr ='Case #%d: %d' % (casno,ans)
        else:
        	outstr = 'Case #%d: NOT POSSIBLE' % casno
        print outstr
        fout.write(outstr+'\n')
    out(cas,ans)
    cas+=1
