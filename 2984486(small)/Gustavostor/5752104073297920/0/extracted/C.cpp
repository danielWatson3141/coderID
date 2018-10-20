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

double prob[1010][1010];

int main() {
	int N = 1000;
	for (int i = N-1; i >= 0; i--) {
		rp(j,N) prob[i][j] = 0.0;
		rp(j,i+1) {
			prob[i][j] = 1.0/N;
		}
		fr(j,i+1,N) {
			rp(k,N) {
				prob[i][k] += (1.0/N)*prob[j][k];
			}
		}
	}

	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int good = 0, bad = 0;
		rp(i,N) {
			int x;
			scanf("%d", &x);
			if (fabs(prob[x][i]-1.0/N) <= 1.0/N) good++;
			else bad++;
		}
		printf("Case #%d: ", cas++);
		if (bad < 50) printf("GOOD\n");
		else printf("BAD\n");
	}
}