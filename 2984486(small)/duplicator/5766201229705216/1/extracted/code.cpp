#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <map>
#include <vector>

const int maxN = 1000 + 10;

using namespace std;


vector<int> A[maxN];
int num_nodes[maxN];
int N;


int getMinDelete(const vector<int>& del, const vector<int>& v, int total_v) {
	if (v.size() == 0)
		return 0;
	if (v.size() == 1)
		return num_nodes[v[0]];

	int min_del = INT_MAX;
	for (int i=0; i<v.size()-1; ++i)
		for (int j=i+1; j<v.size(); ++j) {
			int a = v[i];
			int b = v[j];
			int this_del = total_v - num_nodes[a] - num_nodes[b] + del[i] + del[j];
			if (this_del < min_del)
				min_del = this_del;
		}
	return min_del;
}

// returns the minimum number of nodes to delete in subtree rooted at "the" root
int dfs(int root, int parent) {
	int my_num_node = 0;
	vector<int> num_del;
	vector<int> vert;
	for (int i=0; i<A[root].size(); ++i)
		if (A[root][i] != parent) {
			num_del.push_back(dfs(A[root][i], root));
			vert.push_back(A[root][i]);
			my_num_node += num_nodes[A[root][i]];
		}
	num_nodes[root] = my_num_node + 1;
	return getMinDelete(num_del, vert, my_num_node);
}

// returns the minimum node to delete if root is "the" root
int solve(int root) {
	for (int i=0; i<N; ++i)
		num_nodes[i] = -1;

	return dfs(root, -1);
}

int main() {
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		cin >> N;
		for (int i=0; i<N; ++i)
			A[i].clear();
		for (int i=0; i<N-1; ++i) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			A[a].push_back(b);
			A[b].push_back(a);
		}
		int res = solve(0);
		for (int i=1; i<N; ++i) {
			int temp = solve(i);
			if (temp < res)
				res = temp;
		}
		cout << "Case #" << tt << ": " << res << endl;
	}
	return 0;
}
