// When all ways fail, try randomizail.
#include <bits/stdc++.h>
using namespace std;

vector<int> origAdjList[1024], adjList[1024];
bool vis[1024];
int N;

void formTree(int cur, int parent) {
	if (vis[cur])
		return;
	vis[cur] = 1;
	if (parent != -1)
		adjList[parent].push_back(cur);
	for (unsigned int i = 0; i < origAdjList[cur].size(); ++i)
		formTree(origAdjList[cur][i], cur);
}

pair<int, int> arr[1024];
pair<int, int> arr2[1024];	//The second here isn't needed .. bas fakes :D
pair<int, int> DFS(int x) {
	int children = adjList[x].size(), nodesSum = 0, deletedSum = 0;
	for (int i = 0; i < children; ++i)
		arr[i] = DFS(adjList[x][i]), nodesSum += arr[i].first, deletedSum += arr[i].second,
		arr2[i].first = arr[i].first - arr[i].second, arr2[i].second = N - arr[i].second;
	if (children == 0 || children == 2)
		return make_pair(nodesSum + 1, deletedSum);

	sort(arr2, arr2 + children);
	if (children > 2)
		for (int i = 2; i < children; ++i)
			deletedSum += arr2[i].first;
	else
		deletedSum += arr2[0].first;

	return make_pair(nodesSum + 1, deletedSum);
}

int main() {
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small-attempt1.out", "wt", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int mn = 1000;

		int x, y;
		cin >> N;
		for (int i = 0; i < N; ++i)
			origAdjList[i].clear();
		for (int i = 1; i < N; ++i) {
			cin >> x >> y, --x, --y;
			origAdjList[x].push_back(y);
			origAdjList[y].push_back(x);
		}

		for (int i = 0; i < N; ++i) {
			//Choose i as the root.
			for (int j = 0; j < N; ++j)
				adjList[j].clear();
			memset(vis, 0, sizeof(vis));
			formTree(i, -1);
			mn = min(mn, DFS(i).second);
		}

		cout << "Case #" << t + 1 << ": " << mn << "\n";
	}
	return 0;
}
