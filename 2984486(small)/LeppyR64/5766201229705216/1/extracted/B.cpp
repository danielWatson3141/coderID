#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> adj[1001];
vector<int> children[1001];
vector<int> binary[1001];

int set_children(int u, int p) {
	int result = 1;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v != p) {
			children[u][i] = set_children(v, u);
			result += children[u][i];
		}
	}
	return result;
}

int set_binary(int u, int p) {
	int total_children = 0;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == p)
			continue;
		total_children += children[u][i];
		binary[u][i] = set_binary(v,u);
	}

	int best = total_children;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == p)
			continue;
		for(int j = i+1; j < adj[u].size(); j++) {
			int w = adj[u][j];
			if(w == p)
				continue;
			best = min(best, binary[u][i]+binary[u][j]+(total_children-children[u][i]-children[u][j]));
		}
	}
	return best;
}

void handle_input() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		adj[i].clear();
		children[i].clear();
		binary[i].clear();
	}
	int u,v;
	for(int i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		children[u].push_back(0);
		binary[u].push_back(0);
		adj[v].push_back(u);
		children[v].push_back(0);
		binary[v].push_back(0);
	}
}

void process_testcase() {
	int best = N;
	for(int i = 1; i <= N; i++) {
		set_children(i, 0);
		
		best = min(best, set_binary(i,0));
	}
	cout << best << endl;
}
	
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cout << "Case #" << Z << ": ";
		handle_input();
		process_testcase();
	}
}