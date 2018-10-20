#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N,a,b;
vector<int> edge[1010];
int dp[1010],ch[1010];

void DFS(int u,int p)
{
	int sondp=0;
	int notdel1=0,notdel2=0;
	ch[u]=dp[u]=0;
	for(int i=edge[u].size()-1;i>=0;i--)
		if(edge[u][i]!=p)
		{
			DFS(edge[u][i],u);
			ch[u]+=ch[edge[u][i]];
			if(dp[edge[u][i]]>=notdel1)
			{
				notdel2=notdel1;
				notdel1=dp[edge[u][i]];
			}
			else if(dp[edge[u][i]]>notdel2)
				notdel2=dp[edge[u][i]];
		}
	if(edge[u].size()-(p!=0)==1)
		dp[u]=1;
	else
		dp[u]=notdel1+notdel2+1;
	ch[u]++;
}

int main()
{
	int T,casenum,ans;
	scanf("%d",&T);
	for(casenum=1;casenum<=T;casenum++)
	{
		printf("Case #%d: ",casenum);
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			edge[i].clear();
		for(int i=1;i<N;i++)
		{
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		ans=N;
		for(int i=1;i<=N;i++)
		{
			DFS(i,0);
			ans=min(ch[i]-dp[i],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
