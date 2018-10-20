#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=1001;
int g[Maxn], x[Maxn*2], next[Maxn*2], s[Maxn], f[Maxn];

void dfs(int v, int fa)
{
	int cnt=0, max1=0, max2=0;
	s[v]=1;
	for (int p=g[v]; p; p=next[p])
		if (x[p]!=fa)
		{
			dfs(x[p], v);
			++cnt;
			s[v]+=s[x[p]];
			if (f[x[p]]>max1) max2=max1, max1=f[x[p]];
			else if (f[x[p]]>max2) max2=f[x[p]];
		}
	if (cnt<2) f[v]=1; else f[v]=max1+max2+1;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, n, u, v, i, ans;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		scanf("%d", &n);
		memset(g, 0, sizeof g);
		for (i=1; i<n; ++i)
		{
			scanf("%d%d", &u, &v);
			x[i]=v; next[i]=g[u]; g[u]=i;
			x[n+i]=u; next[n+i]=g[v]; g[v]=n+i;
		}
		ans=n-1;
		for (i=1; i<=n; ++i)
		{
			dfs(i, 0);
			ans=min(ans, n-f[i]);
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}

