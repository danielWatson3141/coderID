#include <cstdio>
#include <algorithm>

using namespace std;
int N,L;
int v[20];
int priza[20];
int app[20];
int tstCASE;

int binaryto10(char c[20])
{
    int x = L;
    int put = 0,rez = 0;
    for(int i = x - 1; i >= 0; --i,++put)
        rez += (1<<put)*(c[i]-48);
    return rez;
}

int nrb(int x)
{
    int nrb = 0;
    while(x)
    {
        if(x % 2 == 1) ++ nrb;
        x /= 2;
    }
    return nrb;
}

void read()
{
    scanf("%d%d\n",&N,&L);
    char line[20];
    for(int i = 1; i <= N; ++i)
    {
        scanf("%s",line);
        priza[i] = binaryto10(line);
    }
    for(int i = 1; i <= N; ++i)
    {
        scanf("%s",line);
        app[i] = binaryto10(line);
    }
}

void solve()
{
    for(int i =1 ; i <= N; ++i)
        v[i] = i;
    int bad = 1;
    int best = 9999;
    do
    {
        int i,ans = app[1] ^ priza[v[1]];
        for(i = 2; i <= N; ++i)
            if(ans != (app[i]^priza[v[i]]))
                break;
        if(i == N+1)
        {
            int rz = nrb(ans);
            if(best > rz)
                best = rz;
        }
    }while(next_permutation(v+1,v+N+1));
    if(best == 9999)
        printf("Case #%d: NOT POSSIBLE\n",tstCASE);
    else printf("Case #%d: %d\n",tstCASE,best);
}

int main()
{
    freopen("chaos.in","r",stdin);
    ///freopen("chaos.out","w",stdout);
    freopen("chaos.txt","w",stdout);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        ++tstCASE;
        read();
        solve();
    }
    return 0;
}
