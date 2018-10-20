#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;
vector<int> nxt[1111];
int n;

int solve(int root, int parent) {
	vector<int> depths;
	for(int i = 0; i < nxt[root].size(); i++) {
		int Q = nxt[root][i];
		if(Q != parent)
			depths.pb(solve(Q, root));
	}
	if(depths.size() < 2)
		return 1;
	sort(depths.begin(), depths.end());
	return 1+depths[depths.size()-2]+depths[depths.size()-1];
}

int main() {
	int T, testcase=1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		REP(i, n) nxt[i].clear();
		REP(i, n-1) {
			int x,y;
			scanf("%d%d", &x, &y);
			x--; y--;
			nxt[x].pb(y); nxt[y].pb(x);
		}
		int ans = n;
		REP(i, n) ans = min(ans, n-solve(i, -1));

		printf("Case #%d: ", testcase++);
		printf("%d", ans);
		printf("\n");
	}
	
	return 0;
}
