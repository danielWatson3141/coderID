#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=15, maxl=15;

int N, L, ans, A[maxn][maxl], B[maxn][maxl], sw[maxl];

bool Check()
{
	//static bool flag[maxn];
	//memset(flag,0,sizeof flag);
	for (int i=1;i<=N;i++)
	{
		bool ok(false);
		for (int j=1;j<=N;j++) //if (!flag[j])
		{
			bool match(true);
			for (int k=1;k<=L;k++) if (A[i][k]^B[j][k]^sw[k])
			{
				match=false;
				break;
			}
			if (match)
			{
				ok=true;
				//flag[j]=true;
				break;
			}
		}
		if (!ok) return false;
	}
	return true;
}

void Dfs(int x, int t)
{
	if (t>=ans) return;
	if (x>L)
	{
		if (Check()) ans=t;
		return;
	}
	Dfs(x+1,t);
	sw[x]=1, Dfs(x+1,t+1), sw[x]=0;
}

int main()
{
	freopen("outlet.in","r",stdin);
	freopen("outlet.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d%d",&N,&L);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=L;j++) 
			{
				char c;
				scanf(" %c",&c);
				A[i][j]=c-'0';
			}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=L;j++)
			{
				char c;
				scanf(" %c",&c);
				B[i][j]=c-'0';
			}
		ans=L+1;
		Dfs(1,0);
		if (ans==L+1) printf("Case #%d: NOT POSSIBLE\n",TT); else printf("Case #%d: %d\n",TT,ans);
	}
	return 0;
}

