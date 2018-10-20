#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

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
	vector<int> t, c;
	int sum = 0;
	for (int i = 0; i < g[node].size(); ++i) {
		int k = g[node][i];
		if (k != parent) {
			t.push_back(solve(node, k));
			c.push_back(cnt[k]);
			sum += c.back();
		}
	}
	int ret = sum;
	for (int i = 0; i < t.size(); ++i)
		for (int j = i + 1; j < t.size(); ++j) {
			int x = sum - c[i] - c[j] + t[i] + t[j];
			if (x < ret) ret = x;
		}
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