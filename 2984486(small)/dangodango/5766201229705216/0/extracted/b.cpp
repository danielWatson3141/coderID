#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int min_delete;

vector<vector<int> > g;
vector<bool> visited;

int n;

vector<int> del_tree;
vector<int> del_all;

void check(int s) {
	visited[s] = true;
	vector<int> nei_del_all;
	vector<int> nei_del_tree;
	del_all[s] = 1;
	nei_del_all.clear();
	nei_del_tree.clear();
	for (int i=0; i<g[s].size(); i++) {
		if (visited[g[s][i]]==false) {
			check(g[s][i]);
			del_all[s] += del_all[g[s][i]];
			nei_del_all.push_back(del_all[g[s][i]]);
			nei_del_tree.push_back(del_tree[g[s][i]]);
		}
	}
	int ret;
	int unvisited_neighbor = nei_del_all.size();
	if (unvisited_neighbor == 0) {
		del_tree[s] = 0;
	} else if (unvisited_neighbor == 1) {
		del_tree[s] = nei_del_all[0];
	} else {
		del_tree[s] = -1;
		for (int i=0; i<unvisited_neighbor; i++) {
			for (int j=0; j<unvisited_neighbor; j++) {
				int tmp = 0;
				for (int k=0; k<unvisited_neighbor; k++) {
					if (k==i || k==j) tmp += nei_del_tree[k];
					else tmp += nei_del_all[k];
				}
				if (del_tree[s] == -1 || tmp < del_tree[s] ){
					del_tree[s] = tmp;
				}
			}
		}
	}
	// cout << s << " " << unvisited_neighbor << " " << del_tree[s] << " " << del_all[s] << endl;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int cs=1; cs<=T; cs++ ){
		scanf("%d", &n);
		g.clear();
		g.resize(n);
		for (int i=0; i<n-1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		min_delete = n -1;
		visited.resize(n);
		del_tree.resize(n);
		del_all.resize(n);
		for (int i=0; i<n; i++) {
			// cout << i << " : " << endl;
			for (int i=0; i<n; i++) {
				visited[i] = false;
			}
			check(i);
			if (del_tree[i] < min_delete) {
				min_delete = del_tree[i];
			}
		}

        cout << "Case #" << cs << ": " << min_delete << endl;
	}
	return 0;
}