#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 100000;

vector<int> tr[1005];
int vis[1005], scnt[1005];

int cnt (int u) {
    vis[u] = 1;
    int n = tr[u].size(), ret = 0;
    for(int i = 0; i < n; i++) {
        int v = tr[u][i];
        if(!vis[v]) {
            ret += cnt(v);
        }
    }
    return scnt[u] = ret + 1;
}

int dfs(int u) {
    vis[u] = 1;
    int n = tr[u].size(), ret = 0;

    int sn = 0;

    for(int i = 0; i < n; i++) {
        int v = tr[u][i];
        if(!vis[v]) {
            ret += dfs(v);
            sn ++;
        }
    }

    if(sn == 0) return 0;
    else if(sn == 1) return scnt[u] - 1;
    else return ret + (sn - 2);
}

int main()
{
    freopen("b-small.in", "r", stdin);
    freopen("b-small.out", "w", stdout);
    int ci, cn;

    cin >> cn;

    for(ci = 1; ci <= cn; ci++) {
    int N, i, ans = INF, u, v;

    cin >> N;

    for(i = 0; i < N; i++) tr[i].clear();

    for(i = 0; i < N - 1; i++) {
        cin >> u >> v;
        tr[u - 1].push_back(v - 1);
        tr[v - 1].push_back(u - 1);
    }


    for(u = 0; u < N; u++) {
        memset(vis, 0, sizeof(vis));
        memset(scnt, 0, sizeof(scnt));

        cnt(u);

        memset(vis, 0, sizeof(vis));

        int ret = dfs(u);
        ans = min(ans, ret);
    }
    cout << "Case #"<< ci <<": ";
    cout << ans << endl;
    }
    return 0;
}
