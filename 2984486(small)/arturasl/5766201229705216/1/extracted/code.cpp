#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int oo = numeric_limits<int>::max();

vector< vector<int> > tree;

pair<int, int> dfs(int p, int pp) { // best, subtree
	vector< pair<int, int> > childResults;
	for (int i = 0; i < (int)tree[p].size(); i += 1) {
		if (tree[p][i] != pp) childResults.push_back(dfs(tree[p][i], p));
	}
	sort(childResults.begin(), childResults.end(), greater< pair<int, int> >());

	pair<int, int> r;
	for (int i = 0; i < (int)childResults.size(); i += 1) r.second += childResults[i].second;
	r.first = r.second, r.second += 1;

	// if (childResults.size() >= 2) {
	// 	int fullBest = childResults[0].first + childResults[1].first;
	// 	fullBest += r.second - (childResults[0].second + childResults[1].second) - 1;
	// 	r.first = min(fullBest, r.first);
	// }

	for (int i = 0; i < (int)childResults.size(); i += 1) {
		for (int j = 0; j < (int)childResults.size(); j += 1) {
			if (i == j) continue;
			int fullBest = childResults[i].first + childResults[j].first;
			fullBest += r.second - (childResults[i].second + childResults[j].second) - 1;
			r.first = min(fullBest, r.first);
		}
	}

	return r;
}

int solve() {
	int N, a, b;
	cin >> N;
	tree.clear();
	tree.resize(N);
	for (int i = 0; i < N - 1; i += 1) {
		cin >> a >> b;
		a -= 1, b -= 1;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int r = +oo;
	for (int i = 0; i < N; i += 1) {
		r = min(r, dfs(i, -1).first);
	}
	return r;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
