#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

#define cin fin
#define cout fout

int n;
vector<int> g[1000];
int cnt[1000];

void count(int parent, int node) {
	cnt[node] = 1;
	for (int i = 0; i < g[node].size(); ++i) {
		int k = g[node][i];
		if (k != parent) {
			count(node, k);
			cnt[node] += cnt[k];
		}
	}
}

int solve(int parent, int node) {
	int sum = 0;
	int k1 = 10000, k2 = 10000;
	for (int i = 0; i < g[node].size(); ++i) {
		int k = g[node][i];
		if (k != parent) {
			int t = solve(node, k);
			int c = cnt[k];
			sum += c;
			int tt = t - c;
			if (tt < k1) {
				k2 = k1; k1 = tt;
			} else if (tt < k2) k2 = tt;
		}
	}
	int ret = sum;
	if (g[node].size() >= 3) ret = sum + k1 + k2;
	return ret;
}

void run() {
	cin>>n;
	for (int i = 0; i < n; ++i)
		g[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin>>x>>y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int best = n;
	for (int i = 0; i < n; ++i) {
		count(-1, i);
		int t = solve(-1, i);
		if (t < best) best = t;
	}
	cout<<best<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}