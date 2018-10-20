#include<cstdio>
#include<vector>
#include<cstring>
#define maxn 1009
#define INF 1000000
using namespace std;
vector<int>G[maxn];
int dp[maxn],num[maxn];
int n,root;
void dfs(int x,int fa)
{
    if(x!=root&&G[x].size()==1)
    {
        num[x]=1;
        dp[x]=0;
        return;
    }
    num[x]=1;int sum=0;
    for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(v!=fa)
		{
			dfs(v,x);
			num[x]+=num[v];
		}
	}
    sum=dp[x]=num[x]-1;
    int mx=INF,mxx=INF;
    for(int i=0;i<G[x].size();i++)
        {
            int v=G[x][i];
            if(v!=fa)
            {
                if(dp[v]-num[v]<mx)
                {
                    mxx=mx;
                    mx=dp[v]-num[v];
                }
                else if(dp[v]-num[v]<mxx)
                {
                    mxx=dp[v]-num[v];
                }
            }
        }

    dp[x]=min(dp[x],sum+mxx+mx);
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("BB.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    int cot=1;
    while(tt--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans=n-1;
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            root=i;
            dfs(root,-1);
            ans=min(ans,dp[root]);
        }
        printf("Case #%d: %d\n",cot++,ans);
    }
}
