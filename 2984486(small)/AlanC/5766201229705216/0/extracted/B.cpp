#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
#define LL long long int
#define N 100005

int TC, n, l[N], qd[N], qn[N], x, y, E, s[N];

void bd(int x, int y){
	qd[++E] = y;
	qn[E] = l[x];
	l[x] = E;
}

int DFS(int x, int y){
	int mx1 = 0, mx2 = 0, cnt = 0;
	s[x] = 1;
	for (int k=l[x];k;k=qn[k])
		if (qd[k] != y){
			cnt++;
			int r = DFS(qd[k], x);
			r = s[qd[k]] - r;
			s[x] += s[qd[k]];
			if (r > mx1) mx2 = mx1, mx1 = r;
			else if (r > mx2) mx2 = r;
		}
	//printf("X = %d, mx1 = %d, mx2 = %d\n", x, mx1, mx2);
	if (cnt == 0) return 0;
	if (cnt == 1) return s[x] - 1;
	return s[x] - mx1 - mx2 - 1;
}

void solve(int tc){
	scanf("%d", &n);
	CLR(l, 0); E = 0;
	FOR(i, 0, n - 1){
		scanf("%d%d", &x, &y);
		bd(x, y);
		bd(y, x);
	}
	int ret = n + 1;
	FOE(i, 1, n){
		CLR(s, 0);
		int t = DFS(i, 0);
		//printf("t[%d] = %d\n", i, t);
		ret = min(ret, t);
	}
	printf("Case #%d: %d\n", tc, ret);
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
