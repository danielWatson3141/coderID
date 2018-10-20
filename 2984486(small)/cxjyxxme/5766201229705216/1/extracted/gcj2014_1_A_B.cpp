#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1005;

struct line
{
	int to, next;
}li[maxn * 5];

int T, n, be[maxn], f[maxn * 5], b[maxn * 5], l, d[maxn];

void makeline(int fr, int to)
{
	++l;
	li[l].next = be[fr];
	be[fr] = l;
	li[l].to = to;
}

void get(int now, int no, int last)
{
	if (b[no]) return;
	if (d[now] <= 2)
	{
		f[no] = 1;
		b[no] = 1;
		return;
	}
	int mx1 = 0, mx2 = 0;
	for (int i = be[now]; i; i = li[i].next)
	{
		int to = li[i].to;
		if (to == last) continue;
		get(to, i, now);
		int t = f[i];
		if (t > mx1)
		{
			mx2 = mx1;
			mx1 = t;
		}
		else
		if (t > mx2) mx2 = t;
	}
	f[no] = mx1 + mx2 + 1;
	b[no] = 1;
	return;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	for (int test = 0; test < T; ++test)
	{
		memset(b, 0, sizeof(b));
		memset(be, 0, sizeof(be));
		memset(f, 0, sizeof(f));
		memset(d, 0, sizeof(d));
		l = 0;
		scanf("%d", &n);
		for (int i = 1; i < n; ++i)
		{
			int fr, to;
			scanf("%d%d", &fr, &to);
			++d[fr], ++d[to];
			makeline(fr, to);
			makeline(to, fr);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tans = 0;
			if (d[i] <= 1) tans = 1;
			else
			{
				int mx1 = 0, mx2 = 0;
				for (int j = be[i]; j; j = li[j].next)
				{
					int to = li[j].to;
					get(to, j, i);
					int t = f[j];
					if (t > mx1)
					{
						mx2 = mx1;
						mx1 = t;
					}
					else
					if (t > mx2) mx2 = t;
				}
				tans = mx1 + mx2 + 1;
			}
			ans = max(ans, tans);
		}
		printf("Case #%d: %d\n", test + 1, n - ans);
	}
	fclose(stdin);fclose(stdout);
}
