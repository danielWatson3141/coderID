#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1005
#define INF 100000

int n,ans;
int dp[MAXN][3];
vector<int> e[MAXN];
void dfs(int u,int p)
{
    int s=e[u].size();
    dp[u][0]=0;
    for (int i=0;i<s;i++)
    {
        int v=e[u][i];
        if (v==p) continue;
        dfs(v,u);
        dp[u][0]+=(dp[v][0]+1);
    }
    dp[u][2]=INF;
    for (int i=0;i<s;i++)
        for (int j=i+1;j<s;j++)
        {
            int x=e[u][i], y=e[u][j];
            if (x==p||y==p) continue;
            int tmp=dp[u][0]-dp[x][0]-dp[y][0]-2;
            tmp+=min(dp[x][0],dp[x][2])+min(dp[y][0],dp[y][2]);
            dp[u][2]=min(dp[u][2],tmp);
        }
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B1.out","w",stdout);
    int cas,u,v;
    scanf("%d",&cas);
    for (int h=1;h<=cas;h++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=n-1;
        for (int i=1;i<=n;i++)
        {
            dfs(i,0);
            ans=min(ans,dp[i][2]);
        }
        printf("Case #%d: %d\n",h,ans);
    }
    return 0;
}

