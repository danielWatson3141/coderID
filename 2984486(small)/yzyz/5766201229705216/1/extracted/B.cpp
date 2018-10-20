#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 1010

using namespace std;

ofstream fout ("Blarge.out");
ifstream fin ("Blarge.in");

int T;
int n;
vector<int> e[MAXN],csz[MAXN];
int del[MAXN],sz[MAXN];

void dfs(int x, int par) {
	for (int i = 0; i < e[x].size(); i++) {
		if (e[x][i] == par) continue;
		//cout << x << ' ' << e[x][i] << endl;
		dfs(e[x][i],x);
		csz[x].push_back(sz[e[x][i]]);
		del[x] += del[e[x][i]];
		//cout << x << " A" << endl;
	}
	int len = csz[x].size();
	if (len < 2) {
		sz[x] = 1;
		if (len == 1) del[x] += csz[x][0];
		return;
	}
	sort(csz[x].begin(),csz[x].end());
	for (int i = 0; i < len-2; i++) del[x] += csz[x][i];
	sz[x] = csz[x][len-2] + csz[x][len-1] + 1;
}

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> n;
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
		for (int i = 0; i < n-1; i++) {
			int x,y;
			fin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = MAXN;
		for (int i = 1; i <= n; i++) {
			memset(del,0,sizeof(del));
			memset(sz,0,sizeof(sz));
			for (int j = 1; j <= n; j++) csz[j].clear();
			dfs(i,0);
			ans = min(ans,del[i]);
		}
		fout << "Case #" << tc << ": ";
		fout << ans << '\n';
		//cout << ans << endl;
	}
    return 0;
}