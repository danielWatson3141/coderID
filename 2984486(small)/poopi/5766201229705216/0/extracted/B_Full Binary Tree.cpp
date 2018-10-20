										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
vector <int> adj[1010];

int dfs(int idx, int par){
	int cnt = 0, mx1 = 0, mx2 = 0;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v == par)
			continue;
		cnt++;
		mx2 = max(mx2, dfs(v, idx));
		if(mx1 < mx2)
			swap(mx1, mx2);
	}
	if(cnt < 2)
		return 1;
	return mx1 + mx2 + 1;
}

int main(){
	freopen("B_Full Binary Tree.in", "r", stdin);
	freopen("B_Full Binary Tree.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> n;
		for(int i = 0; i < n; i++)
			adj[i].clear();
		int a, b;
		for(int i = 1; i < n; i++){
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int res = 0;
		for(int i = 0; i < n; i++)
			res = max(res, dfs(i, -1));
		cout << "Case #" << ++test << ": " << n - res << endl;
	}
	return 0;
}
