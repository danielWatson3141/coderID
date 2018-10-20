
if __name__=='__main__':
    T = int(input())
    
    for i in range(1,T+1):
        N = int(input().rstrip())
        vl = N
        L = []
        for x in range(N-1):
            inp = input().rstrip().split(' ')
            L.append((int(inp[0])-1,int(inp[1])-1))
        for x in range(1<<N):
            Lm = []
##            print(x,end=':')
            
            for elem in L:
                if ((1<<(elem[0]))& x) == 0 and  ((1<<(elem[1]))& x) == 0:
                    Lm.append(elem)
##            print(Lm)
            for y in range(N):
                if (1<<y)&x != 0:
                    continue
                Q = []
                Q.append(y)
                vis = set([])
                poss = True
##                print('Y='+str(y))
                while len(Q)!=0:
##                    print(Q)
                    te = Q.pop()
                    nl = []
 
                    for el in Lm:
                        if el[0] in vis or el[1] in vis:
                            continue
                        if el[0]==te:
                           nl.append(el[1])
                        if el[1]==te:
                            nl.append(el[0])
                    vis.add(te)
                    if len(nl)==2:
##                        print('Enters Good')
                        Q.append(nl[0])
                        Q.append(nl[1])
                        continue
                    if (len(nl)==0):
                        continue
                    else:
                        poss = False
##                        print('Inside')
                        break
                if(len(vis)) != N-bin(x).count("1"):
                    poss = False
                if poss:
                    vl = min(vl,bin(x).count("1"))
##                    print('Sets '+str(vl))
                    break
                

        ans =  'Case #'+str(i)+': '+str(vl)
        print(ans)
