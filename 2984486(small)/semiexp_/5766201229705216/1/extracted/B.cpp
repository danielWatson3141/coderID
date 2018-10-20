#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long i64;

int N;
vector<int> con[1000];

pair<int, int> solve(int p, int rt)
{
	//sol, size

	int sz = 1;
	vector<pair<int, int> > child;

	for(int i = 0; i < con[p].size(); i++) {
		if(con[p][i] == rt) continue;

		pair<int, int> tmp = solve(con[p][i], p);

		child.push_back(tmp);
		sz += tmp.second;
	}

	if(child.size() <= 1) {
		//printf("%d->%d %d %d\n", p, rt, sz-1, sz);
		return make_pair(sz-1, sz);
	}

	int c1 = 0, c2 = 0, sum = sz - 1;
	for(int i = 0; i < child.size(); i++) {
		int dif = child[i].second - child[i].first;

		if(c1 < dif) {
			c2 = c1;
			c1 = dif;
		} else if(c2 < dif) {
			c2 = dif;
		}

	}

	//printf("%d->%d %d %d\n", p, rt, sum-c1-c2, sz);
	return make_pair(sum - c1 - c2, sz);
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d", &N);

		for(int i = 0; i < N; i++) con[i].clear();

		for(int i = 0; i < N-1; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;

			con[x].push_back(y);
			con[y].push_back(x);
		}

		int ret = 1000;

		for(int i = 0; i < N; i++) {
			ret = min(ret, solve(i, -1).first);
		}

		printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
