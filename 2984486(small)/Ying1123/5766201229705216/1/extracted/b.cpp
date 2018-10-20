#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T, n;
int b[2100], next[2100], head[1100], tot;
int f[1100], s[1100];
bool vis[1100];

void makeedge(int a0, int b0)
{
	b[++tot] = b0;
	next[tot] = head[a0];
	head[a0] = tot;
}

void dp(int v)
{
	int q[1100];	
	vis[v] = true;
	s[v] = 1; f[v] = 0;
	q[0] = 0;
	for (int i = head[v]; i; i = next[i])
		if (!vis[b[i]])
		{
			dp(b[i]);
			s[v] += s[b[i]];
			f[v] += f[b[i]];
			q[++q[0]] = s[b[i]] - f[b[i]];
		}
	if (q[0] == 1)
	{
		f[v] += q[1];
	} else
	if (q[0] > 2)
	{
		sort(q + 1, q + q[0] + 1);
		for (int i = 1; i <= q[0] - 2; ++i)
			f[v] += q[i];
	}
}

void work()
{
	scanf("%d", &n);
	memset(head, 0, sizeof(head));
	memset(next, 0, sizeof(next));
	tot = 0;
	int a0, b0;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d%d", &a0, &b0);
		makeedge(a0, b0);
		makeedge(b0, a0);
	}
	int ans = n;
	for (int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		dp(i);
		ans = min(ans, f[i]);
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
