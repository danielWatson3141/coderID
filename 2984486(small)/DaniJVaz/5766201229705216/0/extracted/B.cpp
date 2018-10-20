#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

struct expResults {
	int remove;
	int nodes;
};

expResults explore(int node, int parent, int n, vector<int> * edges);

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n;
		int i, j;
		int t1, t2;
		scanf("%d", &n);

		vector<int> edges[n];
		for (j=0; j<n-1; j++) {
			scanf("%d %d", &t1, &t2);
			--t1; --t2;
			edges[t1].push_back(t2);
			edges[t2].push_back(t1);
		}

		int cost = n-1;
		for (i=0; i<n; i++) { // Node i is the root
			if (edges[i].size() == 1)
				continue;

			expResults r = explore(i, -1, n, edges);
			cost = min(cost, r.remove);
		}
		printf("Case #%d: %d\n", iC, cost);
	}
	return 0;
}

expResults explore(int node, int parent, int n, vector<int> * edges) {
	expResults r;
	r.remove = 0;
	r.nodes = 1;

	if (edges[node].size() == 1)
		return r;

	bool removeAll = false;
	if (edges[node].size() == 2 and (edges[node][0] == parent or edges[node][1] == parent))
		removeAll = true;

	int maxNodes[2] = {0, 0};
	for (int i=0; i<(int)edges[node].size(); i++) {
		if (edges[node][i] == parent)
			continue;
		expResults temp = explore(edges[node][i], node, n, edges);
		r.remove += temp.remove;
		r.remove += temp.nodes;
		
		int t = temp.nodes;
		if (t > maxNodes[0])
			swap (t, maxNodes[0]);
		if (t > maxNodes[1])
			swap (t, maxNodes[1]);
	}

	if (!removeAll) {
		// Then we add the two largest subtrees to the nodes (and remove from the removed)
		r.remove -= maxNodes[0] + maxNodes[1];
		r.nodes += maxNodes[0] + maxNodes[1];
	}
	//printf("%d %d %d %d\n", node, parent, r.remove, r.nodes);
	return r;
}