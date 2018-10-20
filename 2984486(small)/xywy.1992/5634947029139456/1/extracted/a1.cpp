#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <algorithm>

int T, n, m;
char s[2][150][41];

bool rev[40];

int solve(int x, int y) {
    memset(rev, 0, sizeof(rev));
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        rev[i] |= (s[0][x][i] != s[1][y][i]);
        if(rev[i]) {
            cnt++;
        }
    }
    std::vector<long long> a, b;
    for(int i = 0; i < n; ++i) {
        long long u = 0, v = 0;
        for(int j = 0; j < m; ++j) {
            v = v << 1 | (s[1][i][j] == '1');
            if(rev[j]) {
                u = u << 1 | (s[0][i][j] == '0');
            } else {
                u = u << 1 | (s[0][i][j] == '1');
            }
        }
        a.push_back(u), b.push_back(v);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            return INT_MAX;
        }
    }
    return cnt;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    for(int test = 1; test <= T; ++test) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%s", s[i][j]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            ans = std::min(ans, solve(0, i));
        }
        if(ans == INT_MAX) {
            printf("Case #%d: NOT POSSIBLE\n", test);
            continue;
        }
        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
