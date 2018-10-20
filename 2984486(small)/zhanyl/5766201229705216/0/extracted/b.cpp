#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

const int maxn=1005;
int begin[maxn],end[maxn*2],next[maxn*2],k;
int n,u,v;
int dp[maxn];

void ini()
{
    memset(begin,-1,sizeof(begin));
    k=0;
}

void insert(const int &u,const int &v)
{
    end[k]=v;
    next[k]=begin[u];
    begin[u]=k++;
}

void dfs(int u,int fa)
{
    int a=0,b=0,v;
    for(int i=begin[u];i!=-1;i=next[i])
    {
        v=end[i];
        if(v==fa)continue;
        dfs(v,u);
        if(dp[v]>b)
        {
            b=dp[v];
            if(b>a)swap(a,b);
        }
    }
    if(b)dp[u]=a+b+1;
    else dp[u]=1;
}

int main()
{
    //freopen("b-in.txt","r",stdin);
    //freopen("b-out.txt","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    //freopen("B-large.in","r",stdin);
    //freopen("B-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            insert(u,v);
            insert(v,u);
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            dfs(i,-1);
            if(dp[i]>ans)ans=dp[i];
        }
        printf("Case #%d: %d\n",cas,n-ans);
    }
    return 0;
}
