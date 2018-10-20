#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int t, n, a[1010], b[1010], cnt[1010];
double e[1010], val[210], val1[210];

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &a[i]);
            b[i] = i;
        }
        bool flag = true;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i ++ ) {
            for (int j = i; j < n; j ++ )
                if (b[j] == a[i]) {
                    swap(b[j], b[i]);
                    cnt[j - i] ++ ;
                    break;
                }
        }
        e[n] = 0;
        val[ca] = 0;
        for (int i = n - 1; i >= 0; i -- ) {
            e[i] = e[i + 1] + 1.0 / (i + 1);
            val[ca] += (e[i] - cnt[i]) * (e[i] - cnt[i]);
        }
        val1[ca] = val[ca];
        //cout<<t<<" "<<ca<<" "<<val1[ca]<<endl;
    }
    sort(val, val + t);
    for (int ca = 1; ca <= t; ca ++ ) {
        printf("Case #%d: %s\n", ca, val1[ca] < val[60] ? "GOOD" : "BAD");
    }
    return 0;
}
