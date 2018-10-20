#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
const int INF = 0x3fffffff;

vector<int> G[N];
int dp1[N], dp2[N], dp3[N];

void dfs(int u, int fa) {
    dp1[u] = 0;
    dp2[u] = dp3[u] = INF;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v != fa) {
            dfs(v, u);
            int c = dp1[v] + 1;
            int d = min(dp1[v], dp3[v]);
            dp3[u] = min(dp3[u] + c, dp2[u] + d);
            dp2[u] = min(dp2[u] + c, dp1[u] + d);
            dp1[u] += c;
        }
    }
}

void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        G[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        ans = min(ans, dp1[i]);
        ans = min(ans, dp3[i]);
    }
    printf("%d\n", ans);
}

int main() {
//freopen("data.in", "r", stdin);
//freopen("data.out", "w", stdout);
    int T, C = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++C);
        work();
    }
}
