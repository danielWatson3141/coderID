// Template.cpp by kevinptt 20140306
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#define REP(I, N) for(int I=0; I<(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<30;

int mapp[1005][1005], flag[1005];
int child[1005];
int DFS(const int& n, const int& now, const int& par) {
	// printf("%d %d %d\n", n, now, par);
	int res[1005];
	child[now] = 1;
	bool root=true;
	REP(i, flag[now]) {
		if( mapp[now][i]!=par ) {
			res[i] = DFS(n, mapp[now][i], now);
			res[i] -= child[mapp[now][i]];
			// printf("%d : %d\n", mapp[now][i], res[i].F);
			child[now] += child[mapp[now][i]];
		}
		else res[i] = INF, root=false;
	}
	sort(res, res+flag[now]);
	// printf("%d : %d %d\n", now, res[0].F, res[1].F);
	if( res[0]==INF || res[1]==INF || (flag[now]==1 && root) ) return child[now]-1;
	return child[now]-1+res[0]+res[1];
}
int main() {
	DRI(N);
	REP(casen, N) {
		memset(flag, 0, sizeof(flag));
		DRI(n);
		int ans=n-1, a, b, tmp;
		REP(i, n-1) {
			scanf("%d %d", &a, &b);
			mapp[a][flag[a]++] = b;
			mapp[b][flag[b]++] = a;
		}
		REPP(i, 1, n+1) {
			tmp = DFS(n, i, -1);
			//printf("~~%d : %d\n", i, tmp);
			if( tmp<ans ) ans=tmp;
		}
		printf("Case #%d: %d\n", casen+1, ans);
	}

	return 0;
}

