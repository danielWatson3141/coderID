#include <bits/stdc++.h>

using namespace std;


vector<vector<int> > g;


int dfs(int v, int p = -1) {
    vector<int> ans;
    for (int to : g[v]) {
        if (to != p) {
            ans.push_back(dfs(to, v));
        }
    }
    if (ans.size() <= 1) {
        return 1;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    return ans[0]+ans[1] + 1;
}

void solve(int test) {
    cout << "Case #" << test << ": ";
    int n;
    cin >> n;
    g.clear();
    g.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(i));
    }

    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cerr << i << endl;
        solve(i + 1);
    }
    return 0;
}
