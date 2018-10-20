#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 1010;
int dp[MN][MN];
bool g[MN][MN];
int n;
int dfs(int a, int b) {
    if (b != -1 && dp[a][b] != -1) return dp[a][b];
    int r1 = -1, r2 = -1;
    int c = 0, rs = 0;
    for (int i = 0; i < n; i++) {
        if (i != a && i != b && g[a][i]) {
            c++;
            int r = dfs(i, a);
            rs += r;
            if (r > r1) {
                r2 = r1;
                r1 = r;
            } else if (r > r2) {
                r2 = r;
            }
        }
    }
    int res = 1;
    if (c == 2) {
        res += rs;
    } else if (c > 1) {
        res += r1+r2;
    }
    if (b != -1) dp[a][b] = res;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        fill_n(dp[0], MN*MN, -1);
        fill_n(g[0], MN*MN, false);
        cin >> n;
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a][b] = g[b][a] = true;
        }
        int r = -1;
        for (int i = 0; i < n; i++) {
            r = max(r, dfs(i, -1));
        }
        printf("Case #%d: %d\n", t, n-r);
    }
    return 0;
}
