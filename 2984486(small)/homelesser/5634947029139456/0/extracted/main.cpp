#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int INF = 2147483647;
int n, l;
string s[155], t[155], v[155];
int f[45];

bool check() {
    for (int i = 0; i < n; i++) {
        v[i] = s[i];
        for (int j = 0; j < l; j++)
            if (f[j])
                if (v[i][j] == '0') v[i][j] = '1';
                else v[i][j] = '0';
    }
    sort(v, v + n);
    for (int i = 0; i < n; i++)
        if (v[i] != t[i]) return false;
    return true;
}

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        sort(t, t + n);
        int ans = INF;
        for (int i = 0; i < n; i++) {
            memset(f, 0, sizeof (f));
            int cnt = 0;
            for (int j = 0; j < l; j++)
                if (s[0][j] != t[i][j]) {
                    f[j] = 1;
                    cnt++;
                }
            if (check()) {
                ans = min(ans, cnt);
            }
        }
        if (ans == INF) printf("Case #%d: NOT POSSIBLE\n", cas);
        else printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}