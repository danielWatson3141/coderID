#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 1200;

int T, N;
vector<int> edges[MAXN];

int dropped;
int dfs(int node, int parent) {
	vector<int> children;
	for (int child : edges[node]) {
		if (child == parent) continue;
		children.push_back(child);
	}
	if (children.empty()) {
		return 1;
	}
	if (children.size() == 1) {
		dropped += dfs(children[0], node);
		return 1;
	}
	vector<int> sizes;
	for (int child : children) {
		sizes.push_back(dfs(child, node));
	}
	sort(sizes.begin(), sizes.end());
	int n1 = sizes.back(); sizes.pop_back();
	int n2 = sizes.back(); sizes.pop_back();
	for (int s : sizes) {
		dropped += s;
	}
	return 1 + n1 + n2;
}

int main() {
	scanf("%d", &T);
	REP(t,T) {
		REP(i,MAXN) edges[i].clear();
		scanf("%d", &N);
		REP(n,N-1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		int best = N-1;
		REP(i,N) {
			dropped = 0;
			dfs(i, i);
			best = min(best, dropped);
		}
		printf("Case #%d: %d\n", t+1, best);
	}
	return 0;
}
