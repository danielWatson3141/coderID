#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, n, dp[5000];
bool vis[5000];
vector <int> adj[2000];

int calc(int pos) {
    int r0 = 0;
    int r1 = 0;
    int res = dp[pos];
    vis[pos] = true;
    if (res == -1) {
        res = 1;
        vector <int> to;
        for (int i = 0; i < (int) adj[pos].size(); i++)
            if (!vis[adj[pos][i]])
                to.push_back(adj[pos][i]);
        if ((int) to.size() < 2)
            return dp[pos] = res;
        for (int i = 0; i < (int) to.size(); i++) {
            int val = calc(to[i]);
            if (val > r0) {
                r1 = r0;
                r0 = val;
            } else if (val > r1) {
                r1 = val;
            }
        }
    }
    return dp[pos] = res + r0 + r1;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++)
            adj[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = -1;
                vis[j] = false;
            }
            res = max(res, calc(i));
        }
        printf("Case #%d: %d\n", t, n - res);
    }

    return 0;

}
