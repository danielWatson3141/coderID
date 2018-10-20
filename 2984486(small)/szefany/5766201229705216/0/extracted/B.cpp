#include <cstdio>
#include <cstring>
#include <vector>

const int N = 1000 + 10;
const int INF = 1 << 29;

std::vector<int> neighbors[N];
int dp[N][3], size[N], n;

void solve(int u, int p) {
    size[u] = 1;
    for (int i = 0; i < neighbors[u].size(); ++ i) {
        int v = neighbors[u][i];
        if (v != p) {
            solve(v, u);
            size[u] += size[v];
        }
    }
    dp[u][0] = 0;
    dp[u][1] = INF;
    dp[u][2] = INF;
    for (int i = 0; i < neighbors[u].size(); ++ i) {
        int v = neighbors[u][i];
        if (v != p) {
            int current[3];
            memcpy(current, dp[u], sizeof(current));
            for (int j = 0; j < 3; ++ j) {
                dp[u][j] = current[j] + size[v];
                if (j > 0) {
                    dp[u][j] = std::min(dp[u][j], current[j - 1] + std::min(dp[v][0], dp[v][2]));
                }
            }
        }
    }
}

int main() {
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; ++ t) {
        for (int i = 0; i < N; ++ i) {
            neighbors[i].clear();
        }
        scanf("%d", &n);
        for (int i = 1; i < n; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
        }

        int answer = INF;
        for (int root = 1; root <= n; ++ root) {
            solve(root, 0);
            answer = std::min(answer, dp[root][0]);
            answer = std::min(answer, dp[root][2]);
        }
        printf("Case #%d: %d\n", t, answer);
    }
    return 0;
}
