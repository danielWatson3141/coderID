#include <cstdio>
#include <algorithm>

using namespace std;

int n, dev[0x10], out[0x10];

bool canFit(int mask) {
    int tranOut[0x10];
    for (int i = 0; i < n; ++i) {
        tranOut[i] = out[i] ^ mask;
    }
    sort(tranOut, tranOut + n);
    for (int i = 0; i < n; ++i) {
        if (dev[i] != tranOut[i]) return false;
    }
    return true;
}

int cntBit(int x) {
    int cnt = 0;
    while (x) {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

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
        for (int i = 0; i < (1 << len); ++i) {
            if (canFit(i)) {
                int bit = cntBit(i);
                ret = bit < ret ? bit : ret;
            }
        }
        if (ret > len) printf("Case #%d: NOT POSSIBLE\n", cas);
        else printf("Case #%d: %d\n", cas, ret);
    }

    return 0;
}
