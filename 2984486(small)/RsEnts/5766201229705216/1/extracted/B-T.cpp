#include <algorithm> 
#include <cassert> 
#include <cctype> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <deque> 
#include <functional> 
#include <iterator> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <string> 
#include <valarray> 
#include <vector> 
#include <iomanip>

#define MaxN 5010

using namespace std;
typedef long long ll;
typedef long double ld;

int head[MaxN], prep[MaxN], v[MaxN], m0, f[MaxN], siz[MaxN], N, T, Ans;
bool vis[MaxN];

void AddEdge(int a, int b) {
	++m0; v[m0] = b; prep[m0] = head[a]; head[a] = m0;
}

void Dp(int now, int pre) {
	f[now] = 0; siz[now] = 1;
	int cnt = 0;
	vis[now] = 1;
	for(int i = head[now]; i; i = prep[i]) {
		if(v[i] != pre) Dp(v[i], now);
		siz[now] += siz[v[i]];
		++cnt;
		f[now] += siz[v[i]];
	}
	if(cnt == 1) {
		f[now] = siz[now] - 1; return;
	}
	if(cnt == 0) {
		return;
	}
	int mx = 10000, mx1 = 10000;
	for(int i = head[now]; i; i = prep[i]) {
		if(v[i] != pre)
		if(f[v[i]] - siz[v[i]] < mx) {
			mx1 = mx; mx = f[v[i]] - siz[v[i]];
		}
		else if(f[v[i]] - siz[v[i]] < mx1) {
			mx1 = f[v[i]] - siz[v[i]];
		}
	}
	f[now] += mx + mx1;
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int i, j, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		scanf("%d", &N);
		memset(head, 0, sizeof(head));
		for(i = 1; i < N; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			AddEdge(a, b);
			AddEdge(b, a);
		}
		Ans = N;
		for(i = 1; i <= N; ++i) {
			Dp(i, 0);
			memset(vis, 0, sizeof(vis));
			if(f[i] < Ans) Ans = f[i];
		}
		printf("Case #%d: %d\n", ++T0, Ans);
	}
	while(1);
	return 0;
}
