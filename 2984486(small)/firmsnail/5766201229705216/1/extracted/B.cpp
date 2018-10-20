#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int Len = 1000;
const int inf = (1<<30);
struct node{
	int id;
	node *next;
}*P[Len+5];
int dp0[Len+5], dp1[Len+5], dis[Len+5];
int n;
int ans;
void add(int x, int y)
{
	node *ptr = new node;
	ptr->id = y;
	ptr->next = P[x];
	P[x] = ptr;
}
void dfs0(int id, int fa)
{
	int sum = 1;
	for (node *ptr = P[id]; ptr; ptr = ptr->next)
		if (ptr->id != fa)
		{
			dfs0(ptr->id, id);
			sum += dp0[ptr->id];
		}
	dp0[id] = sum;
}
void dfs1(int id, int fa)
{
	int len = 0, sum = 0;
	for (node *ptr = P[id]; ptr; ptr = ptr->next)
		if (ptr->id != fa)
		{
			++len;
			dfs1(ptr->id, id);
		}
	if (len == 0) dp1[id] = 0;
	else if (len == 1)
	{
		for (node *ptr = P[id]; ptr; ptr = ptr->next)
			if (ptr->id != fa)
				sum += dp0[ptr->id];
		dp1[id] = sum;
	}
	else
	{
		sum = 0;
		len = 0;
		int first = inf, second = inf, k = -1;
		for (node *ptr = P[id]; ptr; ptr = ptr->next)
			if (ptr->id != fa)
			{
				sum += dp0[ptr->id];
				dis[len++] = dp1[ptr->id] - dp0[ptr->id];
				if (first > dis[len-1])
				{
					first = dis[len-1];
					k = len-1;
				}
			}
		for (int i = 0; i < len; ++i)
			if (i != k) second = min(second, dis[i]);
		dp1[id] = sum + first + second;
	}
}
void solve()
{
	ans = inf;
	for (int root = 1; root <= n; ++root)
	{
		dfs0(root, -1);
		dfs1(root, -1);
		ans = min(ans, dp1[root]);
	}
	printf("%d\n", ans);
}
int main()
{
	//freopen("E:\\My Code\\GCJ\\R1A\\B-large.in", "r", stdin);
	//freopen("E:\\My Code\\GCJ\\R1A\\B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) P[i] = NULL;
		for (int i = 0; i < n-1; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}