// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> G;
int req_[1024][1024];
int size_[1024][1024];

constexpr int no_p = 1000;

int size(int v, int p) {
	if(size_[v][p] == -1) {
		int val = 1;
		for(int x : G[v]) {
			if(x == p) continue;
			val += size(x, v);
		}
		size_[v][p] = val;
	}
	return size_[v][p];
}

int req(int v, int p) {
	if(req_[v][p] == -1) {
		int e = G[v].size();
		if(p != no_p) --e;
		
		int val;
		if(e == 1) {
			if(G[v][0] == p) {
				val = size(G[v][1], v);
			} else {
				val = size(G[v][0], v);
			}
		} else {
			vector<pair<int, int>> subtrees;
			for(int x : G[v]) {
				if(x == p) continue;
				subtrees.emplace_back(req(x, v) - size(x, v), x);
			}
			sort(subtrees.begin(), subtrees.end());
			
			val = 0;
			for(int x : G[v]) {
				if(x == p) continue;
				if(x == subtrees[0].second || x == subtrees[1].second) {
					val += req(x, v);
				} else {
					val += size(x, v);
				}
			}
		}
		
		req_[v][p] = val;
	}
	return req_[v][p];
}

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		G.clear();
		fill((int*)req_, (int*)req_ + 1024 * 1024, -1);
		fill((int*)size_, (int*)size_ + 1024 * 1024, -1);
		
		int N;
		cin >> N;
		G.resize(N);
		
		for(int i = 0; i < N - 1; ++i) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		
		int best = INT_MAX;
		for(int root = 0; root < N; ++root) {
			best = min(best, req(root, no_p));
		}
		
		cout << "Case #" << t + 1 << ": " << best << "\n";
	}
	
	return 0;
}
