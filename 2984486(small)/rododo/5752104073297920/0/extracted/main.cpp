#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, TC;
    scanf("%d", &T);
    TC = T;
    srand(time(0));
    while (TC--) {
        int N, x;
        double p1 = 0, p2 = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            if (x <= i) {
                p1 += (2.0 / (2 + N - i)) / (2.0 / (2 + N - i) + (1.0 * (2 * N - 2 * i - 2) / (3 * N - 3 * i - 1)));
				p2 += 1.0 - ((2.0 / (2 + N - i)) / (2.0 / (2 + N - i) + (1.0 * (2 * N - 2 * i - 2) / (3 * N - 3 * i - 1))));
            } else {
				p1 += 1.0 - ((2.0 / (2 + N - i)) / (2.0 / (2 + N - i) + (1.0 * (2 * N - 2 * i - 2) / (3 * N - 3 * i - 1))));
				p2 += (2.0 / (2 + N - i)) / (2.0 / (2 + N - i) + (1.0 * (2 * N - 2 * i - 2) / (3 * N - 3 * i - 1)));
            }
        }
        if (rand() * 1.0 / RAND_MAX < p1 / (p1 + p2))
            printf("Case #%d: GOOD\n", T - TC);
        else
            printf("Case #%d: BAD\n", T - TC);
    }
}