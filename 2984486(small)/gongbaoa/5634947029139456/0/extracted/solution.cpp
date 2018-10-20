#include <cstdio>
#include <algorithm>

int num[1024];
int now[10], des[10], a[10];

int main() {
    int T;
    scanf("%d", &T);
    num[0] = 0;
    for (int i = 1; i < 1024; ++ i)
        num[i] = 1 + num[i - (i & -i)];
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
        int full = 1 << l;
        for (int s = 0; s < full; ++ s) {
            std :: copy(now, now + n, a);
            for (int i = 0; i < l; ++ i)
                if (1 == (s >> i & 1))
                    for (int j = 0; j < n; ++ j)
                        a[j] ^= 1 << i;
            std :: sort(a, a + n);
            bool flag = true;
            for (int i = 0; i < n; ++ i)
                if (a[i] != des[i]) {
                    flag = false;
                    break;
                }
            if (flag)
                ans = std :: min(ans, num[s]);
        }
        if (l + 1 != ans)
            printf("Case #%d: %d\n", cas, ans);
        else
            printf("Case #%d: NOT POSSIBLE\n", cas);
    }
    return 0;
}
