#include <cstdio>
#include <cstring>
#include <climits>
#include <set>
#include <algorithm>

const int N = 150;
const int M = 40;

int n, m;
char buffer[M + 1];
long long begin[N], end[N];

void parse(long long *number, int n, int m) {
    for (int i = 0; i < n; ++ i) {
        scanf("%s", buffer);
        number[i] = 0;
        for (int j = 0; j < m; ++ j) {
            number[i] = number[i] << 1 | buffer[j] - '0';
        }
    }
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; ++ t) {
        scanf("%d%d", &n, &m);
        parse(begin, n, m);
        parse(end, n, m);
        std::multiset <long long> ends;
        for (int i = 0; i < n; ++ i) {
            ends.insert(end[i]);
        }
        int result = INT_MAX;
        for (int j = 0; j < n; ++ j) {
            long long mask = begin[0] ^ end[j];
            std::multiset <long long> begins;
            for (int i = 0; i < n; ++ i) {
                begins.insert(begin[i] ^ mask);
            }
            if (begins == ends) {
                result = std::min(result, __builtin_popcount(mask));
            }
        }
        printf("Case #%d: ", t);
        if (result < INT_MAX) {
            printf("%d\n", result);
        } else {
            puts("NOT POSSIBLE");
        }
    }
    return 0;
}
