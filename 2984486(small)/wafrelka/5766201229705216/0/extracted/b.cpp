#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


const int inf = (int)1e9;


int calc_subtree_size(int v, int from, vector<vector<int> > &g, vector<int> &sub)
{
	int ret = 1;

	for(int i = 0; i < g[v].size(); ++i) {
		int w = g[v][i];
		if(w == from)
			continue;
		ret += calc_subtree_size(w, v, g, sub);
	}

	return sub[v] = ret;
}


int calc_mincost(int v, int from, vector<vector<int> > &g, vector<int> &sub)
{
	int child_num = g[v].size() - 1;
	if(from < 0) child_num += 1;

	if(child_num == 0)
		return 0;
	if(child_num == 1)
		return sub[v] - 1;

	vector<int> c;
	int total = 0;

	for(int i = 0; i < g[v].size(); ++i) {

		int w = g[v][i];
		if(w == from)
			continue;
		int ret = calc_mincost(w, v, g, sub);
		c.push_back(sub[w] - ret);
		total += sub[w];
	}

	sort(c.begin(), c.end());

	return total - (c[c.size() - 1] + c[c.size() - 2]);
}


int calc(int root, vector<vector<int> > &g)
{
	vector<int> sub;

	sub.resize(g.size());

	calc_subtree_size(root, -1, g, sub);
	return calc_mincost(root, -1, g, sub);
}


int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 0; case_num < test_case; ++case_num) {

		int ans = inf;
		int n;
		vector<vector<int> > g;

		scanf("%d", &n);

		g.resize(n);

		for(int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			a -= 1; b -= 1;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for(int root = 0; root < n; ++root)
			ans = min(ans, calc(root, g));

		printf("Case #%d: %d\n", case_num + 1, ans);
	}

	return 0;
}