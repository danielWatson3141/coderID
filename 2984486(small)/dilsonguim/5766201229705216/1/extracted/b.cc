#include <bits/extc++.h>
#include <iostream>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int dfs(const vector<vector<int>>& g, vector<bool>& vis, const int u){
	vis[u] = true;
	int rem = 1;
	vector<int> children_rem;
	for(const auto& v : g[u])
		if(not vis[v])
			children_rem.push_back(dfs(g, vis, v));

	sort(children_rem.begin(), children_rem.end(), greater<int>());
	if(children_rem.size() > 1){
		rem += children_rem[0] + children_rem[1];
	}

	return rem;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0; tc < ntc; tc++){
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		for(int i = 0; i < n - 1; i++){
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		int invsol = 1;
		vector<bool> vis(n);
		for(int root = 0; root < n; root++){
			fill(vis.begin(), vis.end(), false);
			int rem = dfs(g, vis, root);
			invsol = max(invsol, rem);
		}
		
		int sol = n - invsol;
		cout << "Case #" << (tc + 1) << ": " << sol << "\n";
	}
}
