#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define NE(x, y) ++ne, e[ne]=y, h[ne]=s[x], s[x]=ne
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 100005;
int n, ne = 0, s[N], e[N], h[N], f[N];
bool v[N];
int dp(int x, int fa, int fr) {
	if (fr && f[fr] != -1) return f[fr];
	int mx1 = 0, mx2 = 0, t;
	for (int w=s[x]; w; w=h[w]) if (e[w] != fa) {
		t = dp(e[w], x, w);
		if (t > mx1) mx2 = mx1, mx1 = t; else
		if (t > mx2) mx2 = t;
	}
	t = mx2 ? mx1+mx2+1 : 1;
	return (f[fr] = t);
}
void run(int C) {
	printf("Case #%d: ", C);
	R(n); ne = 0;
	for (int i=1; i<=n; ++i) s[i] = 0;
	int x, y;
	for (int i=1; i<n; ++i) {
		R(x); R(y);
		NE(x, y); NE(y, x);
	}
	int ans = n;
	for (int i=1; i<=ne; ++i) f[i] = -1;
	for (int i=1; i<=n; ++i)
		ans = min(ans, n - dp(i, 0, 0));
	printf("%d\n", ans);
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i)
		run(i);
	return 0;
}
