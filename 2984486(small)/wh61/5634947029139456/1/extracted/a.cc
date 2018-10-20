#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char s[222][111], a[222][111];
typedef unsigned long long LL;
const int inf = 1000000000;
const LL P = 100000007;
int main() {
    freopen("Al2014.in", "r", stdin);
    freopen("Al2014.out", "w", stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        int n, L;
        scanf("%d%d", &n, &L);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  //      for (int i = 0; i < n; ++i)
  //          for (int j = 0; j < L; ++j) a[i][j] -= '0', s[i][j] -= '0';

        int ans = inf;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<int> c;
                for (int k = 0; k < L; ++k) if (s[i][k] != a[j][k]) c.push_back(1); else c.push_back(0);
                int cnt = 0;
                for (int k = 0; k < L; ++k) if (c[k] == 1) cnt++;
                vector<LL> v1, v2;
                for (int k = 0; k < n; ++k) {
                    LL tmp1 = 0, tmp2 = 0;
                    for (int k_ = 0; k_ < L; ++k_) {
                        int bit1 = ((s[k][k_] - '0') ^ c[k_]) ? 7 : 5;
                        tmp1 = tmp1 * P + bit1;
                        int bit2 = ((a[k][k_] - '0')) ? 7 : 5;
                        tmp2 = tmp2 * P + bit2;
                    }
                    v1.push_back(tmp1);
                    v2.push_back(tmp2);
                }
                sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
                int flag = 1;
                for (int k = 0; k < n; ++k) if (v1[k] != v2[k]) flag = 0;
                if (flag) ans = min(ans, cnt);
            }
        }
        printf("Case #%d: ", ++ca);
        if (ans < inf) printf("%d\n", ans); else puts("NOT POSSIBLE");
    }
    return 0;
}
