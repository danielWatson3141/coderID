#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char s[210][50], d[210][50];
int a[210], b[210], c[210];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    int t, n, l;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i ++ ) {
            scanf("%s", s[i]);
            a[i] = 0;
            for (int j = 0; j < l; j ++ )
                if (s[i][j] == '1') a[i] = a[i] * 2 + 1;
                else a[i] = a[i] * 2;
        }
        for (int i = 0; i < n; i ++ ) {
            scanf("%s", d[i]);
            b[i] = 0;
            for (int j = 0; j < l; j ++ ) {
                if (d[i][j] == '1') b[i] = b[i] * 2 + 1;
                else b[i] = b[i] * 2;
            }
        }
        vector<int> ass;
        for (int i = 0; i < n; i ++ )
            ass.push_back(b[i] ^ a[0]);
        sort(b, b + n);
        int ans = l + 1;
        for (int ss = 0; ss < ass.size(); ss ++ ) {
            int i = ass[ss];
            for (int k = 0; k < n; k ++ )
                c[k] = a[k] ^ i;
            sort(c, c + n);
            bool flag = true;
            for (int k = 0; k < n; k ++ )
                if (b[k] != c[k]) {
                    flag = false;
                    break;
                }
            if (flag) {
                int cnt = 0;
                for (int j = 0; j < l; j ++ )
                    if (i & (1 << j)) cnt ++ ;
                ans = min(ans, cnt);
            }
        }
        if (ans == l + 1) printf("Case #%d: NOT POSSIBLE\n", ca);
        else printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
