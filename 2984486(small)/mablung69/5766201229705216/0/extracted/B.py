f = open('B-small-attempt1.in', 'r')
#f = open('B.in', 'r')

T = int(f.readline().strip())

for t in xrange(T):

    N = int(f.readline().strip())
    list_num=[0]*N

    for n in xrange(N-1):
        
        (x,y) = map(int, f.readline().strip().split(' '))
        list_num[x-1]+=1
        list_num[y-1]+=1

    count=0
    count2=0
    for n in xrange(N):

        if list_num[n]==2:
            count+=1
        if list_num[n]>=3:
            count2+=(list_num[n]-3)

    s="Case #%d: %d" % (t+1,(count-1)+count2)

    print s
