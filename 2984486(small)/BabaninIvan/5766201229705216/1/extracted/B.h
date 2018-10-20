#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
	cerr << NAME << endl;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	clock_t start = clock();
#else 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	int t = 1;
	cin >> t;	 
	for (int i = 1; i <= t; ++i) {
		cerr << t << endl;
		cout << "Case #" << i << ": ";
		solve();
	}

#ifdef YA 
	//cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
}

int n;
vector <vector <int> > g;
vector <int> dp;
vector <int> sum;

void dfs(int v, int parent) {
	dp[v] = n + 1;
	sum[v] = 0;
	set < pair <int, int> > maxs;

	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == parent)
			continue;
		dfs(to, v);
		
		sum[v] += sum[to];

		maxs.insert(mp(dp[to], to));
		if (maxs.size() > 2) {
			maxs.erase(maxs.begin());	
		}
	}
	if (maxs.size() == 2) {
		dp[v] = 1 + (*maxs.begin()).first + (*maxs.rbegin()).first;
	}
	else {
		dp[v] = 1;
	}
	sum[v]++;
}


int sol(int root) {
	dp.resize(n);
	sum.resize(n);
	dfs(root, -1);
	return n - dp[root];
}

void solve() {
	cin >> n;
	g.clear();
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = n + 1;
	for (int i = 0; i < n; ++i) {
		int tmp = sol(i);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}