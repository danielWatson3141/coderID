#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

int getChilds(MI &graph, int node, int parent) {
	int childs = 0;
	for(int i = 0; i < graph[node].size(); ++i) {
		if(graph[node][i] != parent) {
			++childs;
			childs += getChilds(graph, graph[node][i], node);
		}
	}
	return childs;
}

int calcLoss(MI &graph, int node, int parent) {
	int loss = 0;
	if(parent != -1 && graph[node].size() == 2) {
		loss += getChilds(graph, node, parent);
	} else if(graph[node].size() > 3 || (graph[node].size() == 3 && parent == -1)) {
		vector<pair<int,int> > losses;
		for(int i = 0; i < graph[node].size(); ++i) {
			if(graph[node][i] != parent) {
				pair<int,int> p;
				p.first = getChilds(graph, graph[node][i], node)+1;
				p.second = graph[node][i];
				losses.push_back(p);
			}
		}
		sort(losses.begin(), losses.end());
		int delnodes = graph[node].size();
		delnodes -= 3;
		if(parent == -1) {
			delnodes++;
		}
		for(int i = 0; i < delnodes; ++i) {
			loss +=  losses[i].first;
		}
		for(int i = delnodes; i < losses.size(); ++i) {
			loss += calcLoss(graph, losses[i].second, node);
		}
	} else if(graph[node].size() == 1 && parent == -1){
		loss += getChilds(graph, node, parent);
	} else {
		for(int i = 0; i < graph[node].size(); ++i) {
			if(graph[node][i] != parent) {
				loss += calcLoss(graph, graph[node][i], node);
			}
		}
	}
	return loss;
}

int calc(MI &graph, VI &conn) {
	if(graph.size() == 1) return 0;
	int minLoss = -1;
	for(int i = 0 ; i < conn.size(); ++i) {
		int loss = calcLoss(graph, i, -1);
		if (minLoss == -1 || loss < minLoss) minLoss = loss;
	}
	return minLoss;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		MI graph(n,VI(0));
		VI conn(n);
		for (int j = 0; j < n-1; ++j) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			graph[x].push_back(y);
			graph[y].push_back(x);
			conn[x]++;
			conn[y]++;
		}
		cout << "Case #" << i+1 << ": ";
		cout << calc(graph, conn) << endl;
	}
}