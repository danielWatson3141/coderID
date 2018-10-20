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

int n;
vector<vector<int> > v;

int dfs(int t, int p)
{
	int i;
	vector<int> s;
	for (i = 0; i < v[t].size(); ++i)
	{
		if (v[t][i] == p)
		{
			continue;
		}
		s.push_back(dfs(v[t][i], t));
	}
	if (s.size() < 2)
	{
		return 1;
	}
	sort(s.begin(), s.end(), greater<int>());
	return s[0] + s[1] + 1;
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cs;
	scanf("%d", &T);
	for (cs = 1; cs <= T; ++cs)
	{
		int i, ans, p, q;
		scanf("%d", &n);
		v.clear();
		v.resize(n + 1);
		ans = -1;
		for (i = 0; i < n - 1; ++i)
		{
			scanf("%d%d", &p, &q);
			v[p].push_back(q);
			v[q].push_back(p);
		}
		for (i = 1; i <= n; ++i)
		{
			ans = max(ans, dfs(i, 0));
		}
		ans = n - ans;

		printf("Case #%d: ", cs);
		printf("%d\n", ans);
	}
}