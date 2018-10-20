#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
#define LL long long

int count_bit(LL x) {
    int ret = 0;
    while (x) {
        ++ret;
        x &= x-1;
    }
    return ret;
}

LL a[200], b[200];
char s[200];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n, L;
        scanf("%d%d", &n, &L);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; s[j]; ++j) a[i] = (a[i] << 1) | (s[j] == '1');
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; s[j]; ++j) b[i] = (b[i] << 1) | (s[j] == '1');
        }
        int ans = 10000;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            LL d = a[i] ^ b[j];
            unordered_map<LL, int> mp;
            for (int k = 0; k < n; ++k) {
                LL c = a[k] ^ d;
                mp[c]++;
            }
            bool fail = false;
            for (int k = 0; k < n && !fail; ++k) {
                if (mp[b[k]] <= 0) fail = true;
                --mp[b[k]];
            }
            if (!fail) ans = min(ans, count_bit(d));
        }
        printf("Case #%d: ", cas);
        if (ans == 10000) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
