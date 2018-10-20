#include<stdio.h>
#include<string.h>
int tree[1020][1020];
int dp[1020];
void dfs(int father,int node)
{
	int tmp;
	if (tree[node][0]==1||tree[node][0]==2) tmp = 1;
	else
	{
		int Max1 = 0, Max2 = 0;
		int flag;
		for (int j=1;j<=tree[node][0];j++)
		{
			int ison = tree[node][j];
			if (ison==father) continue;
			if (dp[ison]==-1) dfs(node,ison);
			if (dp[ison]>Max1) {Max1 = dp[ison]; flag = ison;}
		}
		for (int j=1;j<=tree[node][0];j++)
		{
			int ison = tree[node][j];
			if (ison==father) continue;
			if (dp[ison]==-1) dfs(node,ison);
			if (dp[ison]>Max2&&ison!=flag) Max2 = dp[ison];
		}
		tmp = Max1 + Max2 + 1;
	}
	if (tmp>dp[node]) dp[node] = tmp;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int k=1;k<=t;k++)
	{
		int n;
		scanf("%d",&n);
		memset(tree,0,sizeof(tree));
		for (int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			tree[x][++tree[x][0]] = y;
			tree[y][++tree[y][0]] = x;
		}
		int ans = 0;
		for (int i=1;i<=n;i++)
		{
			memset(dp,-1,sizeof(dp));
			tree[i][++tree[i][0]] = 0; //模拟一个根节点
			dfs(0,i);
			tree[i][0]--;
			if (dp[i]>ans) ans = dp[i];
		//	int tmp;
		//	if (tree[i][0]<3)
		//	{
		//		for (int j=1;j<=tree[i][0];j++)
		//		{
		//			int ison = tree[i][j];
		//			if (ison==i) continue;
		//			if (dp[ison]==-1) dfs(ison);
		//			tmp = dp[ison];
		//		}
		//	}
		//	else
		//	{
		//		int Max1 = 0, Max2 = 0;
		//		int flag;
		//		for (int j=1;j<=tree[i][0];j++)
		//		{
		//			int ison = tree[i][j];
		//			if (ison==i) continue;
		//			if (dp[ison]==-1) dfs(ison);
		//			if (dp[ison]>Max1) {Max1 = dp[ison]; flag = ison;}
		//		}
		//		for (int j=1;j<=tree[i][0];j++)
		//		{
		//			int ison = tree[i][j];
		//			if (ison==i) continue;
		//			if (dp[ison]==-1) dfs(ison);
		//			if (dp[ison]>Max2&&ison!=flag) Max2 = dp[ison];;
		//		}
		//		tmp = Max1 + Max2;
		//	}
		//	tmp++;//根节点
		//	if (tmp>ans) ans = tmp;
		}
		printf("Case #%d: %d\n",k,n-ans);
	}
	return 0;
}
