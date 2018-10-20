#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
        int n;
        scanf("%d", &n);
        int tot = 0;
        for (int i = 0; i < n; ++ i) {
            int x;
            scanf("%d", &x);
            if (x >= i - 1)
                tot += x * i;
        }
        printf("Case #%d: ", cas);
        if (tot < 132000000)
            puts("GOOD");
        else
            puts("BAD");
    }
    return 0;
}
