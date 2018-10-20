#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 99999
typedef long long ll;

int t, n, l; long long ds[155], outs[155]; char r, s[155];
ll rd() {
	ll res = 0;
	for (int i = 0; i < l; i++) {
		scanf(" %c", &r);
		res = (res<<1) + (r-'0');
	}
	return res;
}
ll bc(ll a) {
	ll res = 0;
	for (ll i = 0; i < 50; i++) if (a & (1LL << i)) res++;
	return res;
}
int main() {
	freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d %d", &n, &l);
		ll ans = INF;
		for (int i = 0; i < n; i++) ds[i] = rd();
		for (int i = 0; i < n; i++) outs[i] = rd();
		for (int i = 0; i < n; i++) {
			ll ch = ds[0] ^ outs[i], bits = bc(ch); char g1 = 1;
			for (int j = 0; j < n; j++) s[j] = 0;
			s[i] = 1;
			for (int j = 1; j < n; j++) {
				char g = 0;
				for (int k = 0; k < n; k++) if (!s[k] && (outs[k] ^ ch) == ds[j]) {
					g = 1; s[k] = 1; break;
				}
				if (!g) {
					g1 = 0; break;
				}
			}
			if (g1) ans = min(ans, bits);
		}
		printf("Case #%d: ", tc+1);
		if (ans==INF) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}

	return 0;
}