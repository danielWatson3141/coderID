#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> T[1111];

void update(int &x, int &y, int z) {
    if (z > x) {
        y = x;
        x = z;
    } else if (z > y)
        y = z;
}

int dfs(int id, int fa) {
    int max1 = -1, max2 = -1;
    for (auto ii = T[id].begin(); ii != T[id].end(); ii++) 
        if (*ii != fa)
            update(max1, max2, dfs(*ii, id));
    if (max2 == -1 || max1 == -1)
        return 1;
    return max2 + max1 + 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        T[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        T[x].push_back(y);
        T[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i, i));
    cout << n - ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
