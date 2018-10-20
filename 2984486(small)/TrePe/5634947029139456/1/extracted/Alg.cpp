#include <stdio.h>
#include <set>
#include <map>
using namespace std;

int cases, kejs;
int i, j, k, N, L, m;
long long a[150], b[150];
char s[1000];
set<long long> as, bs, cs;
set<long long>::iterator it;
set<long long> was[151];

void go(int k, long long mask) {
	if (!was[k].insert(mask).second) return;
	if (k >= N) {
		if (__builtin_popcount(mask) < m) {
			m = __builtin_popcount(mask);
		}
		return;
	}
	long long q = b[k];
	for (int i = 0; i < N; i++) {
		long long newmask = mask;
		int j;
		for (j = 0; j < L; j++) {
			if ((q & (1LL << j)) && ((a[i] & (1LL << j)) ^ (mask & (1LL << j)))) ;
			else if (!(q & (1LL << j)) && !((a[i] & (1LL << j)) ^ (mask & (1LL << j)))) ;
			else if (mask & (1LL << j)) break;
			else if (k == 0) newmask |= (1LL << j);
			else break;
		}
		if (j < L) continue;
		go(k+1, newmask);
	}
}

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
				scanf("%d%d", &N, &L);
				as.clear();
				for (i = 0; i < N; i++) {
					scanf("%s", s);
					a[i] = 0;
					for (j = 0; j < L; j++) a[i] = 2 * a[i] + (s[j] == '1');
					as.insert(a[i]);
				}
				bs.clear();
				for (i = 0; i < N; i++) {
					scanf("%s", s);
					b[i] = 0;
					for (j = 0; j < L; j++) b[i] = 2 * b[i] + (s[j] == '1');
					bs.insert(b[i]);
				}

				m = 200;
				for (i = 0; i <= N; i++) was[i].clear();
				go(0, 0);
				if (m == 200) printf("NOT POSSIBLE\n");
				else printf("%d\n", m);
    }
    return 0;
}
