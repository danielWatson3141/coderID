#include <cstdio>
#include <algorithm>

long long now[150], des[150], a[150];

int getNum(long long x) {
    if (0 == x)
        return 0;
    else
        return 1 + getNum(x - (x & -x));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
        int n, l;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++ i) {
            now[i] = 0;
            for (int j = 0; j < l; ++ j) {
                char c;
                scanf(" %c", &c);
                now[i] = now[i] * 2 + c - '0';
            }
        }
        for (int i = 0; i < n; ++ i) {
            des[i] = 0;
            for (int j = 0; j < l; ++ j) {
                char c;
                scanf(" %c", &c);
                des[i] = des[i] * 2 + c - '0';
            }
        }
        std :: sort(des, des + n);
        int ans = l + 1;
        for (int s = 0; s < n; ++ s) {
            long long chg = now[0] ^ des[s];
            std :: copy(now, now + n, a);
            for (int i = 0; i < n; ++ i)
                a[i] ^= chg;
            std :: sort(a, a + n);
            bool flag = true;
            for (int i = 0; i < n; ++ i)
                if (a[i] != des[i]) {
                    flag = false;
                    break;
                }
            if (flag)
                ans = std :: min(ans, getNum(chg));
        }
        if (l + 1 != ans)
            printf("Case #%d: %d\n", cas, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", cas);
    }
    return 0;
}
