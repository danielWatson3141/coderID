#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef long long ll;
typedef pair<ll,ll> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define MOD 10007

int T, N, L;
ll out[200], in[200];
char str[200];

set<ll> mark;

int test(ll mask) {
	mark.clear();
	rp(i,N) mark.insert(out[i]^mask);
	rp(i,N) if (!mark.count(in[i])) goto af;
	return __builtin_popcount(mask);
	af:;
	return oo;
}

int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &L);
		rp(i,N) {
			scanf("%s", str);
			out[i] = 0;
			rp(j,L) out[i] = ll(out[i]<<1LL) + (str[j]-'0');
		}
		rp(i,N) {
			scanf("%s", str);
			in[i] = 0;
			rp(j,L) in[i] = ll(in[i]<<1LL) + (str[j]-'0');
		}

		int res = oo;
		rp(i,N) {
			res = min(res, test(in[0]^out[i]));
		}

		if (res == oo) printf("Case #%d: NOT POSSIBLE\n", cas++);
		else printf("Case #%d: %d\n", cas++, res);
	}
}

