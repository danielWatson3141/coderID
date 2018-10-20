#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1005;
int dp[2 * N];
vector <pair <int, int> > g[N];
vector <pair <int, int> > edges;

void calc(int id) {
    if (dp[id] != -1)
        return;
    int from = edges[id].first;
    int v = edges[id].second;
    dp[id] = 1;
    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < g[v].size(); ++i) {
        int toV = g[v][i].first;
        int toId = g[v][i].second;
        if (toV == from) continue;
        calc(toId);
        if (dp[toId] > mx1) {
            mx2 = mx1;
            mx1 = dp[toId];
        } else if (dp[toId] > mx2)
            mx2 = dp[toId];
    }
    if (mx1 != -1 && mx2 != -1)
        dp[id] = max(dp[id], 1 + mx1 + mx2);
}

void solve() {
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    edges.clear();
    for (int i = 0; i < n; ++i)
        g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        edges.push_back(make_pair(x, y));
        edges.push_back(make_pair(y, x));

        g[x].push_back(make_pair(y, 2 * i));
        g[y].push_back(make_pair(x, 2 * i + 1));
    }

    for (int i = 0; i < edges.size(); ++i)
        calc(i);
    int ans = 1;
    for (int v = 0; v < n; ++v) {
        int mx1 = -1, mx2 = -1;
        for (int i = 0; i < g[v].size(); ++i) {
            int toV = g[v][i].first;
            int toId = g[v][i].second;
            if (dp[toId] > mx1) {
                mx2 = mx1;
                mx1 = dp[toId];
            } else if (dp[toId] > mx2)
                mx2 = dp[toId];
        }
        if (mx1 != -1 && mx2 != -1)
            ans = max(ans, 1 + mx1 + mx2);
    }
    cout << n - ans << endl;
    //for (int i = 0; i < edges.size(); ++i) cout << dp[i] << " ";cout << endl;
}

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
