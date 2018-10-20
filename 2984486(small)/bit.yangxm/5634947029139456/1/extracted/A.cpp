#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 256

using namespace std;

typedef long long i64;

i64 a[MAX], b[MAX], c[MAX];

int bitCnt(i64 x) {
    int ret = 0;
    for ( ; x; x >>= 1) ret += (x & 1);
    return ret;
}

bool check(int n, i64 s) {
    int i;

    for (i = 0; i < n; ++i) c[i] = a[i] ^ s;
    sort(c, c + n);
    for (i = 0; i < n; ++i) {
        if (c[i] != b[i]) return false;
    }

    return true;
}

i64 readInt(int l) {
    i64 ret = 0;
    int i, x;
    for (i = 0; i < l; ++i) {
        scanf("%1d", &x);
        ret = (ret << 1) | (i64)x;
    }
    return ret;
}

int main() {
    int t, ct = 0, n, l, ans, i, j;
    i64 s;

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &l);
        for (i = 0; i < n; ++i) a[i] = readInt(l);
        for (i = 0; i < n; ++i) b[i] = readInt(l);
        sort(b, b + n);

        ans = l + 1;
        for (i = 0; i < n; ++i) {
            for (s = j = 0; j < l; ++j) {
                if (((a[0] >> j) & 1) != ((b[i] >> j) & 1)) s |= (1LL << j);
            }
            if (check(n, s)) ans = min(ans, bitCnt(s));
        }

        printf("Case #%d: ", ++ct);
        if (ans > l) printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}
