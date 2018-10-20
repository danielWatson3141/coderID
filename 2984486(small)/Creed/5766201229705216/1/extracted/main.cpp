#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
#define mp make_pair
#define pb push_back
const int N = 1010, INF = 1e9;
class Solver {
public:
    int T, curTest;

    int n, x, y;
    vector <int> g[N];
    int toDel[N], makeBin[N];

    void getData() {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    void init() {
        for(int i = 1; i <= n; i++) {
            toDel[i] = makeBin[i] = INF;
        }
    }
    void dfs(int v, int p = -1) {
        int all = 0;
        for(int i = 0; i < (int)g[v].size(); i++) {
            if (g[v][i] == p) continue;
            dfs(g[v][i], v);
            all += toDel[g[v][i]] + 1;
        }
        if ((int)g[v].size() == 1 && p != -1) {
            toDel[v] = makeBin[v] = 0;
        } else if ((int)g[v].size() == 2 && p != -1 || (int)g[v].size() == 1 && p == -1) {
            for(int i = 0; i < (int)g[v].size(); i++) {
                if (g[v][i] == p) continue;
                toDel[v] = toDel[g[v][i]] + 1;
                makeBin[v] = toDel[v];
            }

        } else if ((int)g[v].size() > 2 || (int)g[v].size() == 2 && p == -1) {
            for(int i = 0; i < (int)g[v].size(); i++) {
                if (g[v][i] == p) continue;
                for(int j = i + 1; j < (int)g[v].size(); j++) {
                    if (g[v][j] == p) continue;
                    int ost = all - toDel[g[v][i]] - toDel[g[v][j]] - 2;
                    makeBin[v] = min(makeBin[v], ost + makeBin[g[v][i]] + makeBin[g[v][j]]);
                }
            }
            toDel[v] = all;
        }
    }
    void solve() {
        if (n == 1) {
            cout << "Case #" << curTest << ": " << 0 << endl;
        } else {
            int result = INF;
            for(int i = 1; i <= n; i++) {
                init();
                dfs(i);
                result = min(result, makeBin[i]);
            }
            cout << "Case #" << curTest << ": " << result << endl;
        }
    }
    void run() {
        cin >> T;
        for(int i = 0; i < T; i++) {
            curTest = i + 1;
            getData();
            solve();
        }
    }
};
int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solver* s = new Solver();
    s->run();
    return 0;
}
