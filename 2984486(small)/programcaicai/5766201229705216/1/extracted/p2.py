from collections import deque,defaultdict

fin = open('B-large.in')
fout = open('out.txt','w')

T = int(fin.readline())

cas = 1
while T!=0:
    T -= 1
    n = int(fin.readline())

    edges = defaultdict(list)


    for i in range(n-1):
    	u,v = map(int,fin.readline().split())
    	edges[u].append(v)
    	edges[v].append(u)


    val = [0]* (n+1)
    sz = [0]*(n+1)

    def calcsz(rt,pre=-1):
    	el = filter(lambda x: x!=pre,edges[rt])
    	for x in el:
    		if x!=pre:
    			calcsz(x,rt)
    	sz[rt] = 1+ sum(map(lambda x:sz[x],el),0)




    def calc(rt,pre=-1):
    	el = filter(lambda x: x!=pre,edges[rt])
    	for x in el:
    		if x!=pre:
    			calc(x,rt)
    	if len(el)>2:
    		dl = map(lambda x:sz[x]-val[x],el)
    		dl.sort(reverse=True)
    		val[rt]= sz[rt] - 1 - dl[0] - dl[1]
    	elif len(el)==1:
    		val[rt]=sz[rt] - 1
    	elif len(el)==0:
    		val[rt]=0
    	elif len(el)==2:
    		val[rt] = val[el[0]] + val[el[1]]
    	return val[rt]



    ans = 10000

    for i in range(1,n+1):
    	calcsz(i)
    	ans = min(ans, calc(i))

    def out(casno,ans):
    	if ans!=10000:
        	outstr ='Case #%d: %d' % (casno,ans)
        else:
        	outstr = 'Case #%d: NOT POSSIBLE' % casno
        print outstr
        fout.write(outstr+'\n')
    out(cas,ans)
    cas+=1
