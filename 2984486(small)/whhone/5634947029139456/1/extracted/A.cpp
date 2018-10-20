#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int T, N, L;
char sa[155][45];
char sb[155][45];
long long a[155];
long long b[155];
int ca[45];
int cb[45];

int ans;

bool check() {
	long long x[155];
	long long y[155];
	
	for (int i=0;i<N;++i) {
		x[i] = a[i];
		y[i] = b[i];
		// printf("abab %lld %lld\n", a[i], b[i]);
	}
	//puts("");
	
	sort(x, x + N);
	sort(y, y + N);
	
	for (int i=0;i<N;++i) {
	//	printf("----  %lld %lld\n", x[i], y[i]);
		if (x[i] != y[i]) return false;
	}
	
	return true;
}

void flip(int p) {
	for (int i=0;i<N;++i) {
		a[i] ^= (1LL << (L-p-1));
	}
}

void dfs(int p, int f, int d) {
	// printf("%d %d %d\n", p, f, d);
	if (check()) {
		if (ans > f) ans = f;
		return;
	}
	
	if (p >= L || f >= ans || d >= 10) return;
	
	if (min(ca[p], N-ca[p]) != min(cb[p], N-cb[p])) {
		return;
	}
	
	if (ca[p] == cb[p] && ca[p] != N-cb[p]) {
		dfs(p+1, f, d);
		return;
	}
	
	if (ca[p] != cb[p]) {
		flip(p);
		dfs(p+1, f+1, d);
		flip(p);
		return;
	}
	
	dfs(p+1, f, d+1);
	
	flip(p);
	dfs(p+1, f+1, d+1);
	flip(p);	
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ", tc);
		scanf("%d%d", &N, &L);
		
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));
		ans = 10000;
		
		for (int i = 0; i < N; ++i) {
			scanf("%s", sa[i]);
			for (int j = 0; j < L; ++j) {
				a[i] *= 2LL;
				if (sa[i][j] == '1') {
					ca[j]++;
					a[i]++;
				}
			}
		}
		
		for (int i = 0; i < N; ++i) {
			scanf("%s", sb[i]);
			for (int j = 0; j < L; ++j) {
				b[i] *= 2LL;
				if (sb[i][j] == '1') {
					cb[j]++;
					b[i]++;
				}
			}
		}
		
		dfs(0, 0, 0);
		
		if (ans == 10000) {
			puts("NOT POSSIBLE");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}