#define _N 200

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
long long dev[_N], out[_N];

int cntBit(long long x) {
    int cnt = 0;
    while (x) {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

bool canFit(long long mask) {
    long long tranOut[_N];
    for (int i = 0; i < n; ++i) {
        tranOut[i] = out[i] ^ mask;
    }
    sort(tranOut, tranOut + n);
    for (int i = 0; i < n; ++i) {
        if (tranOut[i] != dev[i]) return false;
    }
    return true;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int t, len;
    char buf[0x20];

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d%d", &n, &len);
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            dev[i] = 0;
            for (int j = 0; j < len; ++j) {
                dev[i] = dev[i] * 2 + buf[j] - '0';
            }
        }
        sort(dev, dev + n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            out[i] = 0;
            for (int j = 0; j < len; ++j) {
                out[i] = out[i] * 2 + buf[j] - '0';
            }
        }

        int ret = len + 1;
        for (int i = 0; i < n; ++i) {
            long long mask = dev[0] ^ out[i];
            if (canFit(mask)) {
                int bit = cntBit(mask);
                ret = min(ret, bit);
            }
        }
        if (ret > len) printf("Case #%d: NOT POSSIBLE\n", cas);
        else printf("Case #%d: %d\n", cas, ret);
    }

    return 0;
}
