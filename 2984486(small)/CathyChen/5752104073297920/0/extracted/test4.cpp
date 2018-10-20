#define _N 1010

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

int num[_N], n;

int doit() {
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (num[i] > num[j]) tot++;
        }
    }
    return tot;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;

    scanf("%d%d", &t, &n);
    for (int cas = 1; cas <= t; ++cas) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
        }
        int cal = doit();
        printf("Case #%d: %s\n", cas, cal % 2 ? "GOOD" : "BAD");
    }

    return 0;
}
