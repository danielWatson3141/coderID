#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std; 

const int N=2000;
const int INF=100000000;

int n;
vector<int> h[N];
int ans, f[N], s[N];

void init()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) h[i].clear();
	for (int i=1; i<n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		h[x].push_back(y);
		h[y].push_back(x);
	}
}

void dfs(int x, int last)
{
	s[x]=1; f[x]=INF;
	int t1=0, t2=0, ti1;
	for (int i=0; i<h[x].size(); ++i)
	{
		int v=h[x][i];
		if (last==v) continue;
		dfs(v, x);
		if (t1 < s[v]-f[v]) 
		{
			t1=s[v]-f[v];
			ti1=i;
		}
		s[x]+=s[v];
	}
	for (int i=0; i<h[x].size(); ++i)
	{
		int v=h[x][i];
		if (last==v) continue;
		if (t2 < s[v]-f[v] && ti1!=i) 
			t2=s[v]-f[v];
	}
	if (t1!=0&&t2!=0) f[x]=min(f[x], s[x]-1-t1-t2);
//	cout << t1 << ' ' << t2 << endl;
	f[x]=min(f[x], s[x]-1);
}

void work()
{
	ans=INF;
	for (int i=1; i<=n; ++i)
	{
		dfs(i, 0);
		ans=min(ans, f[i]);
//		cout << f[i] << endl;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("bbb.in","r",stdin);
	freopen("bbb.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int k=1; k<=cas; ++k)
	{
		printf("Case #%d: ", k);
		init();
		work();
	}
	return 0;
}
