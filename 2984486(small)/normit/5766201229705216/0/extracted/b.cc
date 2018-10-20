#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

	vector<int> link[1100];

int bfs(int node, int parent)
{
	int marked[1100] = {0, };
	marked[parent] = 1;
	marked[node] = 1;

	queue<int> q;
	q.push(node);

	int cnt = 0;

	while(!q.empty()) {
		++cnt;
		int x = q.front();
		q.pop();
		for(int i = 0; i < link[x].size(); ++i) {
			int next = link[x][i];
			if (marked[next]) continue;
			marked[next] = 1;
			q.push(next);
		}
	}
	return cnt;
}

pair<int,int> go(int node, int parent)
{
	//cout << node << "," << parent << endl;

	int num_children = link[node].size();
	if(parent != -1) {
		num_children--;
	}

	if(num_children == 0) {
		return mp(0, 1);
	}

	int num_nodes = bfs(node, parent);
	//cout << "BFS " << node << " " << parent << " " << num_nodes << endl;

	if(num_children == 1) {
		//cout << "11111" << node << "," << parent << ":" << num_nodes-1 << "-" << num_nodes << endl;
		return mp(num_nodes-1, num_nodes);
	}

	vector<	pair<int, int> > result_pairs;

	for(int i = 0; i < link[node].size(); ++i) {
		
		int next = link[node][i];

		if(next == parent) continue;
		result_pairs.pb(go(next, node));
	}

	if (result_pairs.size() == 2) {
		//cout << "22222" << node << "," << parent << ":" << result_pairs[0].first+result_pairs[1].first << "-" << num_nodes << endl;
		return mp(result_pairs[0].first+result_pairs[1].first, num_nodes);
	}

	int min_val = 10000;

	for(int i = 0; i < result_pairs.size()-1; ++i) {
		for(int j = i+1; j < result_pairs.size(); ++j) {
			int val = 0;
			for(int k = 0; k < result_pairs.size(); ++k) {
				if (k == i || k == j) val += result_pairs[k].first;
				else val += result_pairs[k].second;
			}
			if(min_val > val) min_val = val;
		}
	}

	//cout << "33333" << node << "," << parent << ":" << min_val << "-" << num_nodes << endl;

	return mp(min_val, num_nodes);
}

void solve()
{
	int N;
	int adj[1100][1100] = {0, };

	cin >> N;
	for(int i = 0; i <= N; ++i) {
		link[i].clear();
	}

	for(int i = 0; i < N-1; ++i) {
		int x,y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;

		link[x].pb(y);
		link[y].pb(x);
	}

	int min_val = 10000;

	for(int i = 0; i < N; ++i) {
		int val = go(i+1, -1).first;
		if(val < min_val) min_val = val;
	}

	cout << min_val << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}