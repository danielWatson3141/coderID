#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector> 
using namespace std;

const int N = 1010, M = 5010;

int hd[N], nxt[N], to[N], mr;
void link (int a, int b)
{
	nxt[mr] = hd[a], to[mr] = b; hd[a] = mr++;
}
int pere[N], del[N], ans[N];

void dp (int x)
{
	int cnt = 0;
	int sum = 1, t1 = 0, t2 = 0;
	for (int p = hd[x]; p != -1; p = nxt[p])
	{
		if (to[p] != pere[x])
		{
			pere[to[p]] = x, dp(to[p]), ++cnt;
			sum += del[to[p]];
			int tt = del[to[p]] - ans[to[p]];
			// printf("TT = %d\n", tt);
			if (tt > t1) t2 = t1, t1 = tt;
			else if (tt > t2) t2 = tt;
			// printf("%d %d\n", t1, t2);
		}
	}
	if (cnt == 0) del[x] = 1, ans[x] = 0;
	else if (cnt == 1) del[x] = sum, ans[x] = sum - 1;
	else
	{
		del[x] = sum;
		ans[x] = sum - 1 - t1 - t2;
	}
	// printf("%d: %d %d\n", x, del[x], ans[x]);
}

int main ()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int n, T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &n);
		mr = 0; memset(hd, -1, sizeof hd);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			link(a - 1, b - 1);
			link(b - 1, a - 1);
		}
		int an = -1;
		for (int i = 0; i < n; i++)
		{
			pere[i] = -1; dp(i);
			if (an == -1 || ans[i] < an) an = ans[i];
		}
		printf("Case #%d: %d\n", kase, an);
	}
	return 0;
}
