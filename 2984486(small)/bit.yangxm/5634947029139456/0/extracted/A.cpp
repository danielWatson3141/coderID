#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 256
#define LB(x) ((x) & -(x))

using namespace std;

int a[MAX], b[MAX], c[MAX];

int bitCnt(int x) {
    int ret = 0;
    for ( ; x; x -= LB(x)) ++ret;
    return ret;
}

bool check(int n, int x) {
    int i;

    for (i = 0; i < n; ++i) c[i] = a[i] ^ x;
    sort(c, c + n);
    for (i = 0; i < n; ++i) {
        if (c[i] != b[i]) return false;
    }

    return true;
}

int readInt(int l) {
    int i, x, ret = 0;
    for (i = 0; i < l; ++i) {
        scanf("%1d", &x);
        ret = (ret << 1) | x;
    }
    return ret;
}

int main() {
    int t, ct = 0, n, l, s, ans, i;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &l);
        for (i = 0; i < n; ++i) a[i] = readInt(l);
        for (i = 0; i < n; ++i) b[i] = readInt(l);
        sort(b, b + n);
        s = (1 << l); ans = l + 1;
        for (i = 0; i < s; ++i) {
            if (check(n, i)) ans = min(ans, bitCnt(i));
        }
        printf("Case #%d: ", ++ct);
        if (ans > l) printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}
