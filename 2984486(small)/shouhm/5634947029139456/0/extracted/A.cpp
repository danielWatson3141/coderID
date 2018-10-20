#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 200;
const int MAXL = 50;

char a[MAXN][MAXL],aa[MAXN][MAXL], b[MAXN][MAXL], model[MAXL];
int n, L;
bool flip[MAXL];

void ssort(char a[][MAXL]) {
    for (int i = 0; i < n; i ++)
        for (int j = i + 1; j < n; j ++)
    if (strcmp(a[i],a[j])<0) {
        char tmp[MAXL];
        strcpy(tmp, a[i]);
        strcpy(a[i], a[j]);
        strcpy(a[j], tmp);
    }
}
void init() {
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", &b[i]);
	}
	ssort(b);
}

void solve() {
	//enumerate
	int best = -1;
	for (int i = 0; i < n; i++) {
		strcpy(model, a[i]);
		int ct = 0;
		for (int p = 0; p < L; p++) {
			flip[p] = (model[p] != b[0][p]);
			if (flip[p]) ct++;
		}
		for (int j = 0; j < n; j++) {
			strcpy(aa[j], a[j]);
			for (int p = 0; p < L; p++) {
                    if (flip[p])
                    {

                        if (aa[j][p] == '0')
                            aa[j][p] = '1';
                        else
                            aa[j][p] = '0';
                    }
			}
		}
		ssort(aa);
		bool succ = true;
		for (int j = 0; j < n; j++) {
			if (strcmp(aa[j], b[j]) != 0) {
				succ = false;
				break;
			}
		}
		if (succ) {
			if (best == -1) best = ct; else
			if (ct < best) best = ct;
		}
	}
	if (best == -1)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", best);
}

int main() {
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		init();
		printf("Case #%d: ", ti);
		solve();
	}
	return 0;
}
