#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct tmp
{
    int x,y;
    bool operator <(const tmp &o) const
    {
        return y>o.y;
    }
} l[1005][1005];
int T,n,h[1005],v[2005],next[2005],tot,ans,f[1005],w[1005];
void ae(int x,int y) {v[++tot]=y; next[tot]=h[x]; h[x]=tot;}
int go(int x,int y)
{
    w[x]=1; int c=0;
    for(int i=h[x];i;i=next[i]) if(v[i]!=y)
    {
        go(v[i],x); w[x]+=w[v[i]];
        l[x][c].x=v[i]; l[x][c++].y=w[v[i]]-f[v[i]];
    }
    if(!c) f[x]=0;
    else if(c==1) f[x]=w[l[x][0].x];
    else
    {
        sort(l[x],l[x]+c); f[x]=f[l[x][0].x]+f[l[x][1].x];
        for(int i=2;i<c;++i) f[x]+=w[l[x][i].x];
    }
    return f[x];
}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d",&n); int x,y;
        memset(h,0,sizeof(h)); tot=0; ans=n;
        for(int i=1;i<n;++i) {scanf("%d%d",&x,&y); ae(x,y); ae(y,x);}
        for(int i=1;i<=n;++i) ans=min(ans,go(i,0));
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
