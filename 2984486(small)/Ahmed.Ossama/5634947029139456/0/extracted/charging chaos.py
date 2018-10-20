fin=open("A-small-attempt2.in","r")
fout=open("OUTPUT1A.out","w")




def Solve(x,msk):
    if(x==L):
        e=0
        for i in range(n):
            if(O[i] in D):
                e+=1
        if(e!=n):
            return 1000000
        return 0
    if((x,msk) in Mem):
        return Mem[(x,msk)]
    for i in range(n):
        if(O[i][x]=='0'):
            O[i][x]='1'
        else:
            O[i][x]='0'
    ans=1+Solve(x+1,msk+2**x)
    for i in range(n):
        if(O[i][x]=='0'):
            O[i][x]='1'
        else:
            O[i][x]='0'
    ans=min(ans,Solve(x+1,msk))
    Mem[(x,msk)]=ans
    return ans

Mem={}


T=int(fin.readline())
Ans=""
for t in range(T):
    Mem={}
    Ans+="Case #"+str(t+1)+": "
    n,L=map(int,fin.readline().split())
    O=list(map(list,fin.readline().split()))
    D=list(map(list,fin.readline().split()))
    q=Solve(0,0)
    if(q>=1000000):
        Ans+="NOT POSSIBLE\n"
    else:
        Ans+=str(q)+"\n"
fout.write(Ans)
fout.close()
