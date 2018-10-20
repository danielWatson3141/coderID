#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x) * (x))
#define EPS 1e-9
const int maxint = -1u>>1;
typedef long long LL;
const int maxn = 150 + 3;

LL a[maxn], b[maxn];
int n, l;
char s[50];
bool used[maxn];
int mat[maxn];

LL get_input() {
    scanf("%s", s);
    LL res = 0;
    for (int i = 0; s[i]; ++i) {
        res = (res << 1) + (s[i] - '0');
    }
    return res;
}

int get_length(LL ans) {
    int res = 0;
    while (ans) {
        ans = ans & (ans - 1);
        ++res;
    }
    return res;
}

bool dfs(int x, int h) {
    for (int i = 0; i < n; ++i) {
        if ((a[x] ^ b[i]) != h) continue;
        if (used[i]) continue;
        used[i] = true;
        if (mat[i] < 0 || dfs(mat[i], h)) {
            mat[i] = x;
            return true;
        }
    }
    return false;
}

bool ok(int x) {
    int cnt = 0;
    memset(mat, -1, sizeof(mat));
    for (int i = 0; i < n; ++i) {
        memset(used, 0, sizeof(used));
        if (dfs(i, x)) ++cnt;
    }
    return cnt == n;
}

int main() {
    freopen("a.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++i) {
            a[i] = get_input();
        }
        for (int i = 0; i < n; ++i) {
            b[i] = get_input();
        }
        vector<LL> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back(a[i] ^ b[j]);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        LL ans = -1;
        for (int i = 0; i < SZ(v); ++i) {
            if (ok(v[i])) {
                ans = v[i];
                break;
            }
        }
        if (ans < 0) printf("NOT POSSIBLE\n");
        else printf("%d\n", get_length(ans));
    }
    return 0;
}

