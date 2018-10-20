#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=155, maxl=45;

int N, L, ans, A[maxn][maxl], B[maxn][maxl], sw[maxl];
vector<int> C[maxn], D[maxn];

int gen(int x, int y)
{
	int ret(0);
	for (int i=1;i<=L;i++)
		ret+=(sw[i]=(A[x][i]^B[y][i]));
	return ret;
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
		for (int i=1;i<=N;i++)
		{
			int tmp=gen(1,i);
			if (tmp>=ans) continue;
			for (int j=1;j<=N;j++)
			{
				C[j].clear();
				D[j].clear();
				for (int k=1;k<=L;k++)
				{
					C[j].push_back(B[j][k]^sw[k]);
					D[j].push_back(A[j][k]);
				}
			}
			sort(C+1,C+N+1);
			sort(D+1,D+N+1);
			bool ok(true);
			for (int j=1;j<=N;j++) if (C[j]!=D[j])
			{
				ok=false;
				break;
			}
			if (ok) ans=tmp;
		}
		if (ans==L+1) printf("Case #%d: NOT POSSIBLE\n",TT); else printf("Case #%d: %d\n",TT,ans);
	}
	return 0;
}

