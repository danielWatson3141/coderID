#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double a[2000], b[2000];
    int c[2000], d[2000];
    int t, n;
    double r = 2 / 3.1415927;
    scanf("%d", &t);
    for (int xx = 1; xx <= t; ++xx) {
        scanf("%d", &n);
        for (int i = 0; i <= 1500; ++i) {
            a[i] = b[i] = 0;
            d[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
            d[c[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = (double) c[i] / ((double) (n - i + 1));
        }
        for (int i = n - 1; i >= 0; --i) {
            b[i] = (double) c[i] / ((double) n);
            int j = d[i];
            d[i] = i;
            d[c[i]] = j;
            c[j] = c[i];
            c[i] = i;
        }
        double p = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            p = p + sin(a[i] * 3.1415927);
            q = q + sin(b[i] * 3.1415927);
        }
        p /= n;
        q /= n;
        printf("Case #%d: ", xx);
        if ((abs(p - r)) < (abs(q - r))) printf("Good\n"); else printf("Bad\n");

    }
} 
