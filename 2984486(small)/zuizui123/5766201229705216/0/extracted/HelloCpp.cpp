#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fi "B-small-attempt1.in"
#define fo "out.txt"
const int MAXN = 1000;
const int INF = 1000000000;

struct Data {
	int sub, num;

	Data(int s, int n) {
		sub = s;
		num = n;
	}
};

int cmp(Data d1, Data d2) {
	int g1 = d1.num - d1.sub;
	int g2 = d2.num - d2.sub;
	if (g1 != g2) return g1 - g2;
	return d1.num - d2.num;
}

int T, N;
vector<int> graph[MAXN];

int dfs(int, int, int &);

int main(void) {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> N;
		for (int i = 0; i < N; ++i) graph[i].clear();
		for (int i = 0; i < N - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int res = INF;
		for (int i = 0; i < N; ++i) {
			int temp;
			int g = dfs(i, -1, temp);
			res = min(res, g);
//			cout << i << " " << g << endl;
		}
		cout << res << endl;
	}
	return 0;
}

int dfs(int u, int parent, int &count) {
	vector<Data> node;
	count = 1;
	for (int i = 0; i < graph[u].size(); ++i) {
		int v = graph[u][i];
		if (v != parent) {
			int temp;
			int sub = dfs(v, u, temp);
			count += temp;
			node.push_back(Data(sub, temp));
		}
	}

//	cout << "u " << u << endl;
//	cout << "node " << node.size() << endl;
//	for (int i = 0; i < node.size(); ++i) {
//		cout << node[i].num << " " << node[i].sub << endl;
//	}

//	sort(node.begin(), node.end(), cmp);
	if (node.size() == 0) {
		return 0;
	} else {
		if (node.size() == 1) {
			return node[0].num;
		} else {
			int ret = INF;
			int sum = 0;
			for (int i = 0; i < node.size(); ++i) {
				sum += node[i].num;
			}
			for (int i = 0; i < node.size(); ++i) {
				for (int k = i + 1; k < node.size(); ++k) {
					ret = min(ret, sum - node[i].num - node[k].num + node[i].sub + node[k].sub);
				}
			}
			return ret;
		}
	}
}
