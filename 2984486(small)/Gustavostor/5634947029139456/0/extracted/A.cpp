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
int out[200], in[200];
int mark[10000], passo;
char str[200];

int main() {
	int cas = 1;
	cl(mark,0); passo = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &L);
		rp(i,N) {
			scanf("%s", str);
			out[i] = 0;
			rp(j,L) out[i] = (out[i]<<1) + (str[j]-'0');
		}
		rp(i,N) {
			scanf("%s", str);
			in[i] = 0;
			rp(j,L) in[i] = (in[i]<<1) + (str[j]-'0');
		}

		int res = oo;
		int LIM = (1<<L);
		rp(mask,LIM) {
			passo++;
			rp(i,N) mark[out[i]^mask] = passo;
			rp(i,N) if (mark[in[i]] != passo) goto af;
			res = min(res, __builtin_popcount(mask));
			af:;
		}
		printf("Case #%d: ", cas++);
		if (res == oo) printf("NOT POSSIBLE\n");
		else printf("%d\n", res);
	}
}