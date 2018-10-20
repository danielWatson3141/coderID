#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int n;
int g[1010][1010];
int dp[1010][1010];
int fpcost[1010][1010];
vector<int> neighs[1010];

const int SENTINEL = 1005;

// if we are in vertex `y', coming from `x', what's the minimum cost (# of deletions) to
// completely prune the rest of the tree, with `y' included?
int cost_fullpruning(int x, int y)
{
	if (fpcost[x][y] == -1) {
		fpcost[x][y] = 1; // self
		for (int i = 0; i < n; i++) if (i != x && i != y && g[y][i])
			fpcost[x][y] += cost_fullpruning(y, i);
// 		printf("cost_fullpruning(%d, %d) = %d\n", x, y, fpcost[x][y]);
	}
	return fpcost[x][y];
}

// if we are in vertex `y', coming from `x', what's the minimum cost (# of deletions) to
// turn the rooted tree with root 'y' a full binary tree?
int f(int x, int y)
{
	int& d = dp[x][y];
	if (d != -1) return d;
	
	int nChildren = 0;
	int costPrune[neighs[y].size()];
	int costF[neighs[y].size()];
	
	int totalPrune = 0;
	for (int i = 0; i < (int) neighs[y].size(); i++) {
		int z = neighs[y][i];
		if (z == x) continue;
		costPrune[nChildren] = cost_fullpruning(y, z);
		costF    [nChildren] = f(y, z);
		
		totalPrune += costPrune[nChildren];
		nChildren++;
	}
	
	//
	// we have two options:
	// 1) prune all children of `y':
	d = totalPrune;
	
	// 2) leave two children:
	for (int i = 0; i < nChildren; i++)
		for (int j = i + 1; j < nChildren; j++)
			d = min(d, totalPrune - costPrune[i] - costPrune[j] + costF[i] + costF[j]);
	
// 	printf("f(%d, %d) = %d\n", x, y, d);
	return d;
}

int solve(void)
{
	int result = 9999;
	memset(dp, 0xff, sizeof(dp));
	memset(fpcost, 0xff, sizeof(fpcost));
	for (int i = 0; i < n; i++) neighs[i].clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j]) neighs[i].push_back(j);
	for (int i = 0; i < n; i++) {
		result = min(result, f(SENTINEL, i));
	}
	return result;
}

int main(void)
{
// 	freopen("/home/vesko/gcj/b.in", "rt", stdin);
	int TC;
	scanf("%d", &TC);
	for (int T = 1; T <= TC; T++) {
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			g[x][y] = g[y][x] = 1;
		}
		printf("Case #%d: %d\n", T, solve());
	}
	return 0;
}
