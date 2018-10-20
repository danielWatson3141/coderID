#include <cstdio>

int cs;

inline void work() {
    int n, judge = 0;
    scanf("%d", &n);
    int score = 500;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x > i)
            judge += score + i + 1 - x;
        else if (i < 800)
            judge += -x;
    }
    printf("Case #%d: %s\n", ++cs, judge > 0 ? "BAD" : "GOOD");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        work();
    return 0;
}
