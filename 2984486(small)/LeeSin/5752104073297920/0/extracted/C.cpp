#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, a[N];

void solve(){
	scanf("%d", &n);
	fi(i, 0, n) scanf("%d", &a[i]);
	if(a[n - 1] < n / 2) puts("BAD");
	else puts("GOOD");
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
