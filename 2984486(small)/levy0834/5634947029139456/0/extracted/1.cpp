#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <set>
using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define INF 0x7fffffff
#define EPS 1e-8

typedef long long LL;

int n, l;
string s[155], d[155], e[155];
int ns[40], ne[40];

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cs;
	scanf("%d", &T);
	for (cs = 1; cs <= T; ++cs)
	{
		int n, l, i, j, k;
		scanf("%d%d", &n, &l);
		for (i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		for (i = 0; i < n; ++i)
		{
			cin >> e[i];
		}
		int ans = INF;
		sort(e, e + n);
		for (i = 0; i < (1 << l); ++i)
		{
			int t = 0;
			for (k = 0; k < n; ++k)
			{
				d[k] = s[k];
			}
			for (j = 0; j < l; ++j)
			{
				if (!((1 << j) & i))
				{
					continue;
				}
				++t;
				for (k = 0; k < n; ++k)
				{
					if (d[k][j] == '0')
					{
						d[k][j] = '1';
					}
					else
					{
						d[k][j] = '0';
					}
				}
			}
			sort(d, d + n);
			for (j = 0; j < l; ++j)
			{
				if (d[j] != e[j])
				{
					break;
				}
			}
			if (j == l)
			{
				ans = min(ans, t);
			}
		}
		printf("Case #%d: ", cs);
		if (ans == INF)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
}