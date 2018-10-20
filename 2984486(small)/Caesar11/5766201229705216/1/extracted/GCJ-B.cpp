#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1010
#define oo 0x3f3f3f3f
using namespace std;

vector<int>tree[N];
int n;
int dp[N][3],size[N];

void dfs(int u,int p)
{
    size[u]=1;
    for (int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if (v!=p)
        {
            dfs(v,u);
            size[u]+=size[v];
        }
    }

    dp[u][0]=0;
    dp[u][1]=oo;
    dp[u][2]=oo;
    for (int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if (v!=p)
        {
            int cur[3];
            memcpy(cur,dp[u],sizeof(cur));
            for (int j=0;j<3;j++)
            {
                dp[u][j]=cur[j]+size[v];
                if (j>0)
                    dp[u][j]=min(dp[u][j],cur[j-1]+min(dp[v][0],dp[v][2]));
            }
        }
    }
}

int main()
{
    int t,ys=0;

	freopen("B-large.in","r",stdin);
	freopen("resB.out","w",stdout);
    scanf("%d", &t);
    while (t--)
    {
        for (int i=0;i<N;i++)
            tree[i].clear();

        scanf("%d",&n);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans=oo;
        for (int i=1;i<=n;i++)
        {
            dfs(i,0);
            ans=min(ans,dp[i][0]);
            ans=min(ans,dp[i][2]);
        }
        printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}
