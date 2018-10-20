#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> adj[16];
int nignore;
bool ignore[16];
int visited;

bool is_full_binary(int u, int p) {
	int children = 0;
	visited++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(ignore[v] || v == p)
			continue;
		children++;
		if(!is_full_binary(v,u))
			return false;
	}
	return (children==0 || children==2);
}


void handle_input() {
	cin >> N;
	for(int i = 1; i <= N; i++)
		adj[i].clear();
	int u,v;
	for(int i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void process_testcase() {
	int best = N;
	for(int i = 0; i < (1<<N); i++) {
		nignore = 0;
		int x = i;
		for(int j = 1; j <= N; j++) {
			if(x&1) {
				nignore++;
				ignore[j] = true;
			}
			else
				ignore[j] = false;
			x >>= 1;
		}
		for(int j = 1; j <= N; j++) {
			if(!ignore[j]) {
				visited = 0;
				if(is_full_binary(j,0))
					if(visited == (N - nignore))
						best = min(best,nignore);
			}
		}
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