#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

const int maxn = 200, maxL = 50;
int n, L, T, cases;
char o[maxn][maxL], d[maxn][maxL], t[maxL];
bool s[maxL];

int main(){
	for (scanf("%d", &T), cases = 1; cases <= T; ++cases) {
		scanf("%d%d\n", &n, &L);
		for (int i = 0; i < n; ++i) scanf("%s", o[i]);
		for (int i = 0; i < n; ++i) scanf("%s", d[i]);

		int ans = L + 1;
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			for (int k = 0; k < L; ++k) {
				s[k] = o[0][k] != d[j][k];
				cnt += s[k];
			}
			
			bool ok = true;
			memset(t, 0, sizeof(t));
			for (int i = 0; i < n; ++i) {
				strcpy(t, o[i]);
				for (int k = 0; k < L; ++k)
					if (s[k]) {
						if (t[k] == '0') t[k] = '1';
						else t[k] = '0';
					}

				bool found = false;
				for (int k = 0; k < n; ++k)
					if (strcmp(t, d[k]) == 0) {
						found = true;
						break;
					}
				if (!found) {
					ok = false;
					break;
				}
			}
			if (ok) ans = min(ans, cnt);
		}

		printf("Case #%d: ", cases);
		if (ans == L + 1) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
}
