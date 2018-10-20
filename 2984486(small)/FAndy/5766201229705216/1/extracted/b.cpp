#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int maxn = 1000 + 10;
vector<int> g[maxn];
int n;
int d[maxn];
int ans;
int sum[maxn];

void init() {
    for (int i = 0; i < maxn; i++)
        g[i].clear();
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int cur, int fa) {
    for (int i = 0; i < g[cur].size(); i++)
        if (g[cur][i] != fa) {
            dfs(g[cur][i], cur);
        }
    vector<int> c;
    sum[cur] = 0;
    for (int i = 0; i < g[cur].size(); i++)
        if (g[cur][i] != fa) {
            c.push_back(d[g[cur][i]] - sum[g[cur][i]]);
            sum[cur] += sum[g[cur][i]];
        }
    d[cur] = sum[cur];
    sort(c.begin(), c.end());
    
    if (c.size() >= 2 && c[0] + c[1] + sum[cur] < d[cur])
        d[cur] = c[0] + c[1] + sum[cur];
     
    sum[cur] += 1;
}

void solve() {
    ans = n;
    int bl = 0;
    for (int i = 0; i < n; i++) {
        dfs(i, -1);
        if (d[i] < ans) {
            ans = d[i];
            bl = i;
        }
    }    
}

int main() {    
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        init();
        solve();
        printf("Case #%d: ", t);
        printf("%d", ans);
        printf("\n");
    }
}

