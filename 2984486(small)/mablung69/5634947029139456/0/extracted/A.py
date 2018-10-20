f = open('A-small-attempt1.in', 'r')
#f = open('B-large.in', 'r')

T = int(f.readline().strip())

for t in xrange(T):

    (N, L) = map(int, f.readline().strip().split(' '))
    temp_flip=[]
    temp_num=[0]*N
    temp_min=[0]*N

    out = f.readline().strip().split(' ')
    dev = f.readline().strip().split(' ')

    for o in xrange(N):

        num=0
        temp=list(['0']*L)
        tempO=list(out[o])
        tempD=list(dev[0]) 

        for l in xrange(L):
            if tempO[l]==tempD[l]:
                temp[l]='0'
            else:
                temp[l]='1'
                num+=1
        temp_flip.append(temp)
        temp_min[o]=num

    for d in xrange(N):
        for o in xrange(N):

            temp=list(['0']*L)            
            tempO=list(out[o])
            tempD=list(dev[d]) 

            for l in xrange(L):
                if tempO[l]==tempD[l]:
                    temp[l]='0'
                else:
                    temp[l]='1'
                    
            if temp in temp_flip:
                temp_num[o]+=1    

    min_val=[]
    total_num=0
    for d in xrange(N):
        if temp_num[d]==N:
            min_val.append(temp_min[d])
            total_num+=1

    if total_num==0:
            s="Case #%d: NOT POSSIBLE" % (t+1)
    else:
        min_=min(min_val)
        s="Case #%d: %d" % (t+1,min_)

    print s
