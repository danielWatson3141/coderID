
if __name__=='__main__':
    T = int(input())
    
    for i in range(1,T+1):
        inp = input().rstrip().split(' ')
        N = int(inp[0])
        L = int(inp[1])
        given = input().rstrip().split(' ')
        req = input().rstrip().split(' ')
        req.sort()
        ans = -1
        for x in range(1<<L):
            gt = given[:]
            for y in range(L):
                if (x & (1<<y))!=0:
                    
                    for ei in range(len(gt)):
                        tl = list(gt[ei])
                        tl[y] = str(1 - int(tl[y]))
                        gt[ei] = ''.join(tl)
                gt.sort()
##            print(x,end=':')
##            print(gt)
            if gt == req:
##                print('Yes')
                if ans == -1:
                    ans = bin(x).count("1")
                else:
                    ans = min(ans,bin(x).count("1"))
        
        if ans == -1:
            ans = 'NOT POSSIBLE'
        ans = 'Case #'+str(i)+': '+str(ans)
        print(ans)
        
        
