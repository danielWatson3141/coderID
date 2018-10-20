#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a < b;
}

string s1[222], s2[222], ts1[222], ts2[222], cps[44444];
int cnt[44444];

int main()
{
    freopen("chaos.in","r",stdin);
    freopen("chaos.out","w", stdout);
    int testcase, n, len;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++) {
        scanf("%d%d", &n, &len);getchar();
        for (int i = 1; i <= n; i++) s1[i] = "";
        for (int i = 1; i <= n; i++) s2[i] = "";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= len; j++) {
                char c;
                c = getchar();
                s1[i] = s1[i] + c;
            }
            getchar();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= len; j++) {
                char c;
                c = getchar();
                s2[i] = s2[i] + c;
            }
            getchar();
        }

        int cptot = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cptot++;
                cps[cptot] = "";cnt[cptot] = 0;
                for (int p = 0; p < len; p++) {
                    if (s1[i][p] == s2[j][p]) cps[cptot] = cps[cptot] + '0';
                    else {
                            cps[cptot] = cps[cptot] + '1';
                            cnt[cptot]++;
                    }
                }
            }
        }

        //for (int i = 1; i <= cptot; i++)
        //    cout << cps[i] << " " <<cnt[i] << endl;

        sort(s1 + 1, s1 + 1 + n, cmp);
        int ans = len + 1;
        for (int i = 1; i <= cptot; i++) {
            for (int j = 1; j <= n; j++) {
                ts2[j] = s2[j];
            }
            for (int j = 0; j < len; j++) {
                if (cps[i][j] == '1') {
                    for (int p = 1; p <=n; p++) {
                        if (ts2[p][j] == '1') ts2[p][j] = '0';
                        else ts2[p][j] = '1';
                    }
                }
            }
            //sort(ts1 + 1, ts1 + 1 + n, cmp);
            sort(ts2 + 1, ts2 + 1 + n, cmp);

            //for (int j = 1; j <= n; j++) cout << ts1[j] << endl;
            //for (int j = 1; j <= n; j++) cout << ts2[j] << endl;

            bool pp = true;
            for (int j = 1; j <= n; j++) {
                if (s1[j] != ts2[j]) {
                    pp = false;
                    break;
                }
            }
            if (pp) if (cnt[i] < ans) ans = cnt[i];
        }
        if (ans > len) printf("Case #%d: NOT POSSIBLE\n", test);
        else printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
