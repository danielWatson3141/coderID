#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define P 1000000007
#define LL long long
#define N 1007
#define M 2007
using namespace std;
int fir[N],next[M],ver[M],d[N],f1[N],f2[N],f[N];
int n,tot;
void add(int a,int b)
{
    ver[++tot]=b;
    next[tot]=fir[a];
    fir[a]=tot;
}
void dfs(int x,int fa)
{
    d[x]=0;
    f1[x]=f2[x]=0;
    for (int p=fir[x];p;p=next[p])
        if (ver[p]!=fa)
        {
            dfs(ver[p],x);
            d[x]++;
            if (f[ver[p]]>=f1[x])
            {
                f2[x]=f1[x];
                f1[x]=f[ver[p]];
            }
            else if (f[ver[p]]>f2[x])
                f2[x]=f[ver[p]];
        }
    if (d[x]>=2)
        f[x]=1+f2[x]+f1[x];
    else
        f[x]=1;
}
int main()
{
    //freopen("B.in","r",stdin);
    //freopen("a.out","w",stdout);
    int cnt,a,b,ans;
    scanf("%d",&cnt);
    for (int run=1;run<=cnt;run++)
    {
        scanf("%d",&n);
        tot=0;
        memset(fir,0,sizeof fir);
        for (int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
            d[a]++,d[b]++;
        }
        ans=1;
        for (int i=1;i<=n;i++)
            {
                dfs(i,0);
                if (f[i]>ans) ans=f[i];
                //printf("%d %d\n",i,f[i]);
            }
        printf("Case #%d: %d\n",run,n-ans);
    }
    return 0;
}
