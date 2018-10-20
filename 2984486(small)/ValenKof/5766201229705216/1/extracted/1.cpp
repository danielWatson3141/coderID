#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

template <typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template <typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }
template <typename T> inline int sz(const T& x) { return (int) x.size(); }

#define PATH "C:\\Users\\Valenkof\\Desktop\\"
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair

const int INF = 1000000;

vector<int> g[1000];

vector<pair<int, int> > dp[1000];

const pair<int, int> UNDEF = make_pair(-1, INF);

pair<int, int> DP(int node, int iParent) {
	if (dp[node][iParent] != UNDEF) {
		return dp[node][iParent];
	}
	vector<int> children;
	vector<int> ourIndex;
	
	forn (i, sz(g[node])) {
		if (i != iParent) {
			int child = g[node][i];
			children.push_back(child);
			ourIndex.push_back(lower_bound(all(g[child]), node) - g[child].begin());
		}
	}
	
	int max1 = 0;
	int max2 = 0;
	
	int totalSize = 1;
	forn (iChild, sz(children)) {
		auto nextDp = DP(children[iChild], ourIndex[iChild]);
		totalSize += nextDp.first;
		int save = nextDp.first - nextDp.second;		
		if (save > max1) {
			max2 = max1;
			max1 = save;
		} else if (save > max2) {
			max2 = save;
		}
	}
	
	
	if (sz(children) == 0) {
		return dp[node][iParent] = mp(1, 0);
	}
	if (sz(children) == 1) {
		return dp[node][iParent] = mp(totalSize, totalSize - 1);
	}
	
	
	// debug(node);
	// debug(iParent);
	// debug(ans);
	// debug(totalSize);
	return dp[node][iParent] = mp(totalSize, totalSize - max1 - max2 - 1);
}

int solve(int n) {
	forn (i, n) {
		sort(all(g[i]));
	}
	forn (i, n) {
		dp[i].assign(sz(g[i]) + 1, UNDEF);
	}
	
	int ans = INF;
	forn (i, n) {
		mn(ans, DP(i, g[i].size()).second);
	}
	
	return ans;
}

int main() {
	freopen(PATH"B-large.in", "r", stdin);
	freopen(PATH"output.txt", "w", stdout);	
	ios_base::sync_with_stdio(false);
	
	int nTests;
	cin >> nTests;
	forn (iTest, nTests) {
		cout << "Case #" << iTest + 1 << ": ";
		int n;
		cin >> n;
		forn (i, n) {
			g[i].resize(0);
		}
		forn (i, n - 1) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << solve(n) << endl;
	}
	return 0;
}