#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_EDGES 1000
#define MAX_NODES 1000

int min_delete_given_root(int root, int parent);
int compute_total_nodes(int root, int parent);

struct NODE {
	int nedges;
	int edge[MAX_EDGES+1];
} node[MAX_NODES+1]; // need plus 1 for one-based enumeration

int N;

void clear_edges() {
	for (int u = 1; u <= N; u++)
		node[u].nedges = 0;
}

void add_edge(int u, int v) {
	int nedges = node[u].nedges;
	node[u].edge[nedges] = v;
	node[u].nedges++;
}

int compute_total_nodes(int root, int parent) {
	int i;
	int subroot;
	int root_edges = node[root].nedges;
	vector<int> cost, total_nodes;
	
	cost.resize(root_edges);
	total_nodes.resize(root_edges);
	
	int sum = 1; // include self
	for (i = 0; i < root_edges; i++) {
		// compute subtree information
		subroot = node[root].edge[i];
		if (subroot == parent)
			continue;
		sum += compute_total_nodes(subroot, root);
	}
	return sum;
}

int min_delete_given_root(int root, int parent) {
	int i, j;
	int subroot;
	int root_edges = node[root].nedges;
	vector<int> cost, total_nodes;
	
	cost.resize(root_edges);
	total_nodes.resize(root_edges);
	
	for (i = 0; i < root_edges; i++) {
		// compute subtree information
		subroot = node[root].edge[i];
		if (subroot == parent)
			continue;
		cost[i] = min_delete_given_root(subroot, root);
		total_nodes[i] = compute_total_nodes(subroot, root);
	}
	/*cout << "root,parent = " << root << "," << parent << endl;
	cout << "costs... ";
	for (i = 0; i < root_edges; i++) {
		subroot = node[root].edge[i];
		if (subroot == parent)
			cout << " N/A";
		else cout << " " << cost[i];
	}
	cout << endl << "nodes...";
	for (i = 0; i < root_edges; i++) {
		subroot = node[root].edge[i];
		if (subroot == parent)
			cout << " N/A";
		else cout << " " << total_nodes[i];
	}
	cout << endl;*/
	
	int res = 0;
	
	// option 1: delete EVERYTHING beneath current node
	
	for (i = 0; i < root_edges; i++) {
		subroot = node[root].edge[i];
		if (subroot == parent)
			continue;
		res += total_nodes[i];
	}
	
	// among all combinations of 2 children, minimize deletions
	
	int killall = res;
	for (i = 0; i < root_edges; i++) {
		subroot = node[root].edge[i];
		if (subroot == parent)
			continue;
		for (j = 0; j < root_edges; j++) {
			subroot = node[root].edge[j];
			if (subroot == parent)
				continue;
			if (j == i)
				continue;
			// combo chosen as subnodes: i and j
			int tmp = killall - total_nodes[i] + cost[i] - total_nodes[j] + cost[j];
			res = min(res, tmp);
			//cout << i << " " << j << " " << tmp << endl;
		}
	}
	
	return res;
}

int min_num_nodes_to_delete() {
	int res = N;
	for (int root = 1; root <= N; root++) {
		res = min(res, min_delete_given_root(root, 0)); // no parent
		//cout << "root = " << root << ", dels = " << min_delete_given_root(root, 0) << endl;
	}
	return res;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		clear_edges();
		for (int i = 0; i < N-1; i++) {
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
			add_edge(v, u);
		}
		
		/*for (int i = 1; i <= N; i++)
			cout << i << " " << node[i].nedges << endl;
		cout << "PRINTED" << endl;*/
		
		int res = min_num_nodes_to_delete();
		
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
