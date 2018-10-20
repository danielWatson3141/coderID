#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1200;

int T, n, u, v;
vector<int> e[maxn];
int flag[maxn], siz[maxn];

int dfs(int u, int p) {
    vector<int> v; siz[u] = 1;
    for (size_t i = 0; i < e[u].size(); ++i) {
        int w = e[u][i];
        if (w == p) continue;
        v.push_back(dfs(w, u) - siz[w]);
        siz[u] += siz[w];
    }
    int ans = siz[u] - 1;
    sort(v.begin(), v.end());
    if (v.size() >= 2) {
        int ans2 = ans;
        for (size_t i = 0; i < 2; i++)
            ans2 += v[i];
        ans = min(ans, ans2);
    }
    return ans;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cs = 0;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i = 0; i < n; i++) e[i].clear();
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dfs(i, -1));
        }
        printf("Case #%d: %d\n", ++cs, ans);
    }
    return 0;
}
