def solve():
    global N,nodes,s
    N = input()
    nodes = [[] for i in range(N)]
    s = [N+1 for i in range(N)]
    best = 0
    for i in range(N-1):
        n1,n2 = [int(n) for n in raw_input().split()]
        nodes[n1-1].append(n2-1)
        nodes[n2-1].append(n1-1)

    for i in range(N):
        if(len(nodes[i])==1):
            s[i]=1

    while(N+1 in s):
        possible=False
        for i in range(N):
            if(s[i]==N+1):
                tmp = list()
                for j in nodes[i]:
                    if(s[j]!=N+1):
                        tmp.append((s[j],j))
                if(len(tmp)>1):
                    possible=True
                    tmp.sort()
                    s[i]=tmp[-1][0]+tmp[-2][0]+1
                    s[tmp[-1][1]]=N+2
                    s[tmp[-2][1]]=N+2
                    break
        if(possible==False):
            z = s.index(min(s))
            s[z]=N+2
            for i in nodes[z]:
                if(s[i]!=N+2):
                    s[i]=1
                    break

    for i in range(len(s)):
        if(s[i]==N+1 or s[i]==N+2):
            s[i]=-1
    return N-max(s) 

if __name__=='__main__':
    T = input()

    for t in range(1,T+1):
        res = solve()
        print("Case #%d: %d" % (t,res)) 

