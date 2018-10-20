#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define loop(i, c) for(int i = 0; i < (c); i++)

using namespace std;

struct Node {
	vector<int> adj;
	bool complete;
} tree[1000];

struct ip {
	int chil, cost;
};

int N, T;
bool seen[1000];

ip cost(int n) {
	seen[n] = true;
	ip res;
	res.chil = 0;
	loop(i, tree[n].adj.size()) if(!seen[tree[n].adj[i]]) res.chil++;
	if(res.chil == 0) {
		res.cost = 0;
		return res;
	}
	vector<ip> cCost;
	int tChil = 0;
	loop(i, tree[n].adj.size()) {
		if(seen[tree[n].adj[i]]) continue;
		ip v = cost(tree[n].adj[i]);
		cCost.push_back(v);
		tChil += v.chil;
	}
	
	if(res.chil == 1) {
		res.chil += tChil;
		res.cost = res.chil;
		
		return res;
	}
	int cost = -1;
	loop(i, cCost.size()) for(int j = i+1; j < cCost.size(); j++) {
		int ncost = res.chil-2 + tChil - cCost[i].chil - cCost[j].chil + cCost[i].cost + cCost[j].cost;
		if(cost == -1 || ncost < cost) cost = ncost;
	}
	res.chil += tChil;
	res.cost = cost < res.chil ? cost : res.chil;
	return res;
	
}

int main() {
	cin >> T;
	loop(t, T) {
		cin >> N;
		loop(i, N) tree[i].adj.clear();
		loop(i, N-1) {
			int x, y;
			cin >> x >> y;
			tree[x-1].adj.push_back(y-1);
			tree[y-1].adj.push_back(x-1);
		}
		int best = -1;
		loop(n, N) {
			loop(i, N) seen[i] = false;
			int nbest = cost(n).cost;
			loop(i, N) if(!seen[i]) nbest++;
			if(best == -1 || nbest < best) best = nbest;
		}
		printf("Case #%d: %d\n", t+1, best);
	}
}