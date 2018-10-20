#include <stdio.h>
#include <set>
using namespace std;

int cases, kejs;
int i, j, k;
set<int> a[1001], b[1001];
bool d[1001], dd[1001];
int N;

bool ok(int i) {
	int ch = 0;
	set<int>::iterator it;
	dd[i] = true;
	for (it = b[i].begin(); it != b[i].end(); ++it) {
		if (!dd[*it]) {
			ch++;
			if (!ok(*it)) return false;
		}
	}
	if (ch == 0 || ch == 2) return true;
	return false;
}

bool isbinary() {
	int i, j;
	for (i = 1; i <= N; i++) {
		if (!d[i]) {
			for (j = 1; j <= N; j++) dd[j] = false;
			if (ok(i)) {
				for (j = 1; j <= N; j++) {
					if (!d[j] && !dd[j]) break;
				}
				if (j > N) return true;
			}
		}
	}
	return false;
	
}

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
				scanf("%d", &N);
				for (i = 1; i <= N; i++) a[i].clear();
				for (i = 1; i < N; i++) {
					scanf("%d%d", &j, &k);
					a[j].insert(k);
					a[k].insert(j);
				}
				int m = N;
				for (i = 0; i < (1 << N); i++) {
					for (j = 1; j <= N; j++) b[j] = a[j], d[j] = false;
					for (j = 0; j < N; j++) {
						if (i & (1 << j)) {
							d[j+1] = true;
							while (b[j+1].begin() != b[j+1].end()) {
								b[*(b[j+1].begin())].erase(j+1);
								b[j+1].erase(b[j+1].begin());
							}
						}
					}
					if (isbinary()) {
						if (__builtin_popcount(i) < m) {
							m = __builtin_popcount(i);
						}
					}
				}
				if (N == 2) m = 1;
				printf("%d\n", m);
    }
    return 0;
}
