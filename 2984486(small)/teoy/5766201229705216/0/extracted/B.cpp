#include "cstring"
#include "cstdio"
#include "vector"
#include "set"
#include "algorithm"
using namespace std;
const int N = 1010;
const int INF = 1 << 20;

vector<int> edge[N];
int dp[N][3], size[N], n;

void solve(int u, int p) {
    size[u] = 1;
    for (int i = 0; i < edge[u].size(); ++ i) {
        int v = edge[u][i];
        if (v != p) {
            solve(v, u);
            size[u] += size[v];
        }
    }
    dp[u][0] = 0;
    dp[u][1] = INF;
    dp[u][2] = INF;
    for (int i = 0; i < edge[u].size(); ++ i) {
        int v = edge[u][i];
        if (v != p) {
            int val[3];
            for (int j = 0; j < 3; ++ j) {
            	val[j] = dp[u][j];
            }
            for (int j = 0; j < 3; ++ j) {
                dp[u][j] = val[j] + size[v];
                if (j > 0) {
                    dp[u][j] = min(dp[u][j], val[j - 1] + min(dp[v][0], dp[v][2]));
                }
            }
        }
    }
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
    int T, g = 0;
    scanf("%d", &T);
    while(T --) {
        for (int i = 0; i < N; ++ i) {
            edge[i].clear();
        }
        scanf("%d", &n);
        for (int i = 1; i < n; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        int ans = INF;
        for (int u = 1; u <= n; ++ u) {
            solve(u, 0);
            ans = min(ans, min(dp[u][0], dp[u][2]));
        }
        printf("Case #%d: %d\n", ++ g, ans);
    }
    return 0;
}
