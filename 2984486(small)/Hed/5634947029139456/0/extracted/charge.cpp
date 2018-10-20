#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

const int maxn = 155;
const int maxl = 45;
int T,N,L,ans;
char s[maxn][maxl],opt[maxn][maxl];
int cs1[maxl],op1[maxl];
bool UN;

bool check()
{
	fo(i,1,N)
	{
		bool find = 0;
		fo(j,1,N)
		{
			bool match = 1;
			fo(k,1,L)
				if (s[i][k] != opt[j][k])
				{
					match = 0;
					break;
				}
			if (match)
			{
				find = 1;
				break;
			}
		}
		if (!find) return 0;
	}
	return 1;
}

void dfs(int x,int tot)
{
	if (tot > ans) return;
	if (x > L)
	{
		if (check() && tot < ans) ans = tot;
		return;
	}
	if (cs1[x] == op1[x]) dfs(x+1,tot);
	if (UN) return;
	if (cs1[x] == N-op1[x])
	{
		int temp[maxn];
		fo(i,1,N) temp[i] = s[i][x];
		fo(i,1,N)
			if (s[i][x] == '1') s[i][x] = '0';
			else s[i][x] = '1';
		dfs(x+1,tot+1);
		fo(i,1,N) s[i][x] = temp[i];
	}
	if (UN) return;
	if (cs1[x] != op1[x] && cs1[x] != N-op1[x])
	{
		UN = 1;
		return;
	}
}

int main()
{
	freopen("charge.in","r",stdin);
	freopen("charge.out","w",stdout);
	scanf("%d",&T);
	fo(cs,1,T)
	{
		scanf("%d%d",&N,&L);
		memset(cs1,0,sizeof cs1);
		memset(op1,0,sizeof op1);
		fo(i,1,N) scanf("%s",s[i]+1);
		fo(i,1,N) scanf("%s",opt[i]+1);
		fo(i,1,L) fo(j,1,N) cs1[i] += (s[j][i] == '1'), op1[i] += (opt[j][i] == '1');
		ans = 0x7fffffff;
		UN = 0;
		dfs(1,0);
		printf("Case #%d: ",cs);
		if (ans > (int)1e9) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
