#include <cstdio>

int a[10000]; 

void testCase()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i])
                ++r;
        }
    }
    //printf("%d\n", r);
    if (r > 244000)
        printf("GOOD\n");
    else
        printf("BAD\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        testCase();
    }
}