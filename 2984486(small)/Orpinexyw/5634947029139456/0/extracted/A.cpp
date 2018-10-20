#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int T, n, m;
string s[200], t[200], tt[200];
bool flag[200];
void work()
{
    int ans = ~0u>>1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin>>s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin>>t[i];
    }
	sort(s + 1, s + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			for (int k = 0; k < m; k++) {
				if (s[i][k] != t[j][k]) {
					flag[k] = true;
					cnt++;
				} else {
					flag[k] = false;
				}
			}
			for (int l = 1; l <= n; l++) {
				tt[l] = t[l];
				for (int k = 0; k < m; k++) {
					if (flag[k] == true) {
						if (tt[l][k] == '0')
							tt[l][k] = '1';
						else
							tt[l][k] = '0';
					}
				}
			}
			sort(tt + 1, tt + 1 + n);
			bool f = true;
			for (int l = 1; l <= n; l++) {
				if (tt[l] != s[l]){f = false; break;}
			}
			if (f) ans = min(ans, cnt);
		}
	}
	if (ans == ~0u>>1) puts("NOT POSSIBLE");
    else printf("%d\n", ans);
}
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
}
