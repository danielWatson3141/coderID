#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		int n;
		scanf("%d", &n);
		vector<vector<int> > Adj(n+1);
		for (int it = 1; it < n; it++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (find(Adj[x].begin(), Adj[x].end(), y) == Adj[x].end()) {
				Adj[x].push_back(y);
				Adj[y].push_back(x);
			}
		}

		int ans = 1001;
		for (int it = 1; it <= n; it++) {
			if (Adj[it].size()%2 == 0) {
				queue<int> bfs;
				set<int> visited;
				// initial push;
				visited.insert(it);
				for (int i = 0; i < Adj[it].size(); i++) {
					bfs.push(Adj[it][i]);
					visited.insert(Adj[it][i]);
				}

				while (!bfs.empty()) {
					int current_node = bfs.front();
					bfs.pop();
					if ((Adj[current_node].size() % 2) == 1) {
						for (int i = 0; i < Adj[current_node].size(); i++){
							if (visited.find(Adj[current_node][i]) == visited.end()) {
								bfs.push(Adj[current_node][i]);
								visited.insert(Adj[current_node][i]);
							}
						}
					}
				}

				int del_node = n-visited.size();
				if (del_node < ans) {
					ans = del_node;
				}
			}
		}
		if (ans != 1001)
			printf("Case #%d: %d\n", t, ans);
		else
			printf("Case #%d: %d\n", t, 1);
	}
	return 0;
}