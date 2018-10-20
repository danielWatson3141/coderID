#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ret {
	int d, c; // number of nodes, cost of making it full
};

bool ret_cmp(const ret &a, const ret &b) {
	return a.d > b.d;
}

ret dfs(vector<vector<int> > &g, int n, int p) {
	vector<ret> rs;
	for (int i = 0; i < g[n].size(); i++) {
		if (g[n][i] != p) {
			rs.push_back( dfs(g, g[n][i], n) );
		}
	}
	sort(rs.begin(), rs.end(), ret_cmp);

	ret r = {1, 0};
	if (rs.size() < 2) {
		for (int i = 0; i < rs.size(); i++) {
			ret ch = rs[i];
			r.c += ch.d;
			r.d += ch.d;
		}
	} else {
		ret best = rs[0];
		ret sbest = rs[1];
		r.c += best.c + sbest.c;
		r.d += best.d + sbest.d;
		for (int i = 2; i < rs.size(); i++) {
			ret ch = rs[i];
			r.c += ch.d;
			r.d += ch.d;
		}
	}
	//cerr << "  from " << n << " with d " << r.d << " and c " << r.c << endl;
	return r;
}

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		cout << "Case #" << kase << ": ";

		int N;
		cin >> N;
		vector< vector<int> > g(N, vector<int>());
		for (int i = 0; i < N-1; i++) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int best = 1000000;
		for (int i = 0; i < N; i++) {
			//cerr << "root " << i << endl;
			ret r = dfs(g, i, -1);	
			if (r.c < best) best = r.c;
		}

		cout << best << endl;;
	}
	return 0;
}
