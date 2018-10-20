#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

void solve (int root, int parent, vvi &E, vi &sizes) {
	int i;
	if (sz(E[root]) == 1) {
		sizes[root] = 1;
		return;
	}
	for (i = 0; i < sz(E[root]); i++) {
		if (E[root][i] == parent) continue;
		if (sizes[E[root][i]] == -1) solve(E[root][i], root, E, sizes);
	}
	vi needs;
	for (i = 0; i < sz(E[root]); i++) {
		if (E[root][i] == parent) continue;
		else needs.pb(sizes[E[root][i]]);
	}
	sort(all(needs));
	if (sz(needs) == 1) sizes[root] = 1;
	else sizes[root] = needs[sz(needs)-1] + needs[sz(needs)-2] + 1;
}
int main() {

	int T, c, N, root, i, res;
	int killed;
	vi deg;
	vii edges;
	vvi E;
	vi sizes;
	fin >> T;
	for (c = 1; c <= T; c++) {
		deg.clear();
		edges.clear();
		E.clear();
		fin >> N;
		sizes.resize(N, -1);
		deg.resize(N, 0);
		edges.resize(N-1);
		E.resize(N, vi(0));

		for (i = 0; i < N-1; i++) {
			fin >> edges[i].first >> edges[i].second;
			edges[i].first--;
			edges[i].second--;
			deg[edges[i].first]++;
			deg[edges[i].second]++;
			E[edges[i].first].pb(edges[i].second);
			E[edges[i].second].pb(edges[i].first);
		}
		res = N-1;
		for (root = 0; root < N; root++) {
			sizes.clear();
			sizes.resize(N, -1);
			if (deg[root] < 2) continue;
			solve(root, -1, E, sizes);
			if (N - sizes[root] < res) res = N - sizes[root];
		}
		fout << "Case #" << c <<": " << res << endl;
	}


	return 0;
}
