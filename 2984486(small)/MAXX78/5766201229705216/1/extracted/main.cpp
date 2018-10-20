//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF=1000111222;
const double INFF=1e100;
const double eps=1e-8;
const int mod=1000000007;
const int NN=1005;
const int MM=401010;
/* ****************** */

struct G
{
    int v,next;
}E[NN*2];
int p[NN],T;
int dp[NN];

void add(int u,int v)
{
    E[T].v=v;
    E[T].next=p[u];
    p[u]=T++;
}

void dfs(int u,int fa)
{
    int i,v,m1,m2;

    m1=m2=-1000000;
    dp[u]=1;

    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(v==fa)
            continue;
        dfs(v,u);

        if(dp[v]>m1)
        {
            m2=m1;
            m1=dp[v];
        }
        else if(dp[v]>m2)
        {
            m2=dp[v];
        }
    }

    dp[u]=max(dp[u],1+m1+m2);
}

int main()
{
    freopen("E:\\B-large.in","r",stdin);
    freopen("E:\\B-large.out","w",stdout);

    int cas,ee=0;
    int n,i,u,v;
    int ans;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(p,-1,sizeof(p));
        T=0;

        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }

        ans=n;
        for(i=1;i<=n;i++)
        {
            dfs(i,-1);
            ans=min(ans,n-dp[i]);
        }

        printf("Case #%d: ",++ee);
        printf("%d\n",ans);
    }
    return 0;
}
