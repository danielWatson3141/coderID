#include <cstdio>
#include <algorithm>
#define N 2005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, f[N], o[N], v[N], p, dp[N], ans;

void add(int a, int b){
	v[++p] = b; o[p] = f[a]; f[a] = p;
}

void go(int x, int y){
	dp[x] = 1;
	int fir = -1, sec = -1;
	fe(i, f[x], o) if(y != v[i]){
		go(v[i], x);
		if(dp[v[i]] >= fir){
			sec = fir;
			fir = dp[v[i]];
		}else if(dp[v[i]] > sec){
			sec = dp[v[i]];
		}
	}
	
	if(sec > -1) dp[x] += fir + sec;
	ans = max(ans, dp[x]);
}

void solve(){
	scanf("%d", &n);
	p = 0;
	FI(i, 1, n) f[i] = 0;
	ans = 0;
	
	fi(i, 1, n){
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	FI(i, 1, n) go(i, 0);
	printf("%d\n", n - ans);
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
