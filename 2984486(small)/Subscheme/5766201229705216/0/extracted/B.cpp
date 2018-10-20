#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define fo(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define range(i,a,b) for(int i = (a), _b = (b); i < _b; ++i)

const int MAX_N = 1100;
int T, N;
vector<int> adj[MAX_N];
typedef pair<int,int> pr;

int subtreeCache[MAX_N][MAX_N];
int subtreeSize(int node, int from) {
	if(subtreeCache[node][from] == -1) {
		subtreeCache[node][from] = 1;
		fo(i,adj[node].size()) if(adj[node][i] != from) subtreeCache[node][from] += subtreeSize(adj[node][i], node);
	}
	return subtreeCache[node][from];
}

int rootCache[MAX_N][MAX_N];
int rootAt(int node, int from) {
	if(rootCache[node][from] == -1) {
		int degree = 0;
		fo(i,adj[node].size()) if(adj[node][i] != from) ++degree;
		
		rootCache[node][from] = 0;
		if(degree < 2) {
			fo(i,adj[node].size()) if(adj[node][i] != from) rootCache[node][from] += subtreeSize(adj[node][i], node);
		} else if(degree > 2) {
			
			vector<int> childRootCost, childSubtreeCost;
			fo(i,adj[node].size()) if(adj[node][i] != from) childRootCost.push_back(rootAt(adj[node][i], node)), childSubtreeCost.push_back(subtreeSize(adj[node][i], node));

			vector<pr> ordered;
			fo(i,childRootCost.size()) ordered.push_back(pr(childRootCost[i] - childSubtreeCost[i], i));
			sort(ordered.begin(), ordered.end());
			fo(i,2) rootCache[node][from] += childRootCost[ordered[i].second];
			range(i,2,ordered.size()) rootCache[node][from] += childSubtreeCost[ordered[i].second];

		} else {
			fo(i,adj[node].size()) if(adj[node][i] != from) rootCache[node][from] += rootAt(adj[node][i], node);
		}
	}
	return rootCache[node][from];
}

int main() {
	cin >> T;
	fo(t,T) {
		fo(i,MAX_N) fo(j,MAX_N) rootCache[i][j] = subtreeCache[i][j] = -1;
		fo(i,MAX_N) adj[i].clear();
		cin >> N;
		fo(i,N-1) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int best = N;
		range(i,1,N+1) {
			best = min(best, rootAt(i, N+1));
		}
		cout << "Case #" << t + 1 << ": " << best << '\n';
	}
}