#include <cstdio>
#include <algorithm>

int T, n, x, y;
int a[1 << 10];
double f[2][1 << 10];

#define SQR(X) ((X) * (X))

double solve() {
    double sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += SQR(a[i] - f[x][i]);
    }
    return sum;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for(int test = 1; test <= T; ++test) {
        scanf("%d", &n);
        for(int i = 0; i< n; ++i) {
            scanf("%d", &a[i]);
        }
        x = 0, y = 1;
        for(int i = 0; i < n; ++i) {
            f[x][i] = i;
        }
        for(int i = 0; i < n; ++i, std::swap(x, y)) {
            for(int j = 0; j < n; ++j) {
                f[y][j] = f[x][j];
            }
            double sum = 0;
            for(int j = i; j < n; ++j) {
                sum += f[x][j];
            }
            int t = n - i;
            f[y][i] = sum / t;
            for(int j = i + 1; j < n; ++j) {
                f[y][j] = f[x][j] * (t - 1) / t + f[x][i] / t;
            }
        }
        double delta1 = solve();
        for(int i = 0; i < n; ++i) {
            f[x][i] = i;
        }
        for(int i = 0; i < n; ++i, std::swap(x, y)) {
            for(int j = 0; j < n; ++j) {
                f[y][j] = f[x][j];
            }
            double sum = 0;
            for(int j = 0; j < n; ++j) {
                sum += f[x][j];
            }
            int t = n - 0;
            f[y][i] = sum / t;
            for(int j = 0 + 1; j < n; ++j) {
                f[y][j] = f[x][j] * (t - 1) / t + f[x][i] / t;
            }
        }
        double delta2 = solve();
        //printf("%lf %lf\n", delta1, delta2);
        printf("Case #%d: ", test);
        puts(delta1 <= delta2 ? "GOOD" : "BAD");
    }
    return 0;
}
