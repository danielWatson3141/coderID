#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2000;

const int INF = 1e8;

int N;
vector<int> adj[MAXN];

//return pair of size, max for keeping
pii dfs(int cur, int par = -1) {
	int sz = 1;
	int m1 = 0; // number that we keep
	int m2 = 0; // number that we keep
	for(int i = 0; i < adj[cur].size(); i++) {
		int nxt = adj[cur][i];
		if(nxt == par) continue;
		pii v = dfs(nxt, cur);
		sz += v.first;
		int k = v.second;
		if(k > m2) m2 = k;
		if(m2 > m1) swap(m1, m2);
	}
	int kp = 1;
	if(m1 && m2) {
		kp += m1 + m2;
	}
	return make_pair(sz, kp);
}

int go() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		adj[i].clear();
	}

	for(int i = 0; i < N - 1; i++) {
		int x, y; cin >> x >> y; x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int res = N - 1;
	for(int i = 0; i < N; i++) {
		pii v = dfs(i);
		assert(v.first == N);
		int cost = v.first - v.second;
		if(cost < res) res = cost;
	}
	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int res = go();
		cout << "Case #" << t << ": " << res << '\n';
	}
}
