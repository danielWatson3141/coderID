#include <stdio.h>
#include <set>
using namespace std;

int cases, kejs;
int i, j, N, L;
long long a[150], b[150];
char s[1000];
set<long long> as, bs, cs;
set<long long>::iterator it;

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

				int m = 200;
				for (i = 0; i < (1 << L); i++) {
					cs.clear();
					for (it = as.begin(); it != as.end(); ++it) {
						long long q = *it;
						for (j = 0; j < L; j++) {
							if (i & (1LL << j)) q ^= (1LL << j);
						}
						cs.insert(q);
					}
					if (cs == bs) {
						if (__builtin_popcount(i) < m) {
							m = __builtin_popcount(i);
						}
					}
				}
				if (m == 200) printf("NOT POSSIBLE\n");
				else printf("%d\n", m);
    }
    return 0;
}
