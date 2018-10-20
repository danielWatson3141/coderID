#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

vector<int> e[1000];
bool used[1000];

Pii dfs(int id) {
	used[id] = true;
	int cur = 0;
	Pii ret(1,0);
	vector<int> v;
	for (auto p : e[id]) {
		if (!used[p]) {
			auto q = dfs(p);
			v.push_back(q.first);
			ret.second += q.second;
		}
	}
	if (sz(v) == 1) {
		ret.second += v[0];
	} else if (sz(v) >= 2) {
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < 2; i++) ret.first += v[i];
		for (int i = 2; i < sz(v); i++) ret.second += v[i];
	}

	return ret;
}

int main(){

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		FOR(i, 1000) e[i].clear();

		int n; cin >> n;
		FOR(i, n - 1) {
			int x, y; cin >> x >> y;
			x--; y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}

		int ans = 1000000;
		FOR(i, n) {
			memset(used, 0, sizeof(used));
			Pii p = dfs(i);
			ans = min(ans, p.second);
		}

		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
