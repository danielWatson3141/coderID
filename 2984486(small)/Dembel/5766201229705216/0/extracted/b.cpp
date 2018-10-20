#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

int solve(int cur, int par, const vector < vector <int > > & ed, vector <int> & cnt, vector <int> & dp)
{
	int & res = dp[cur];
	cnt[cur] = 1;
	vector <int> child;
	vector <int> childRes;
	for (int i = 0; i < int(ed[cur].size()); ++i)
	{
		int v = ed[cur][i];
		if (v == par)
			continue;
		child.push_back(v);
		solve(v, cur, ed, cnt, dp);
		cnt[cur] += cnt[v];
		childRes.push_back(dp[v] - cnt[v]);
	}
	if (child.empty())
		res = 0;
	else if (child.size() == 1)
		res = cnt[child[0]];
	else
	{
		sort(childRes.begin(), childRes.end());
		int sum = cnt[cur] - 1;
		sum += childRes[0];
		sum += childRes[1];
		res = sum;
	}
}

int solve(int root, const vector < vector <int> > & ed)
{
	vector <int> cnt(ed.size());
	vector <int> dp(ed.size());
	solve(root, -1, ed, cnt, dp);
	return dp[root];
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n;
		scanf("%d", &n);
		vector < vector <int> > ed(n);
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		int res = n * 2;
		for (int i = 0; i < n; ++i)
			res = min(res, solve(i, ed));
		printf("%d\n", res);
	}

	return 0;
}
