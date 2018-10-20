#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largest_complete_tree(vector<vector<int> > &g, int v, int p) {
    if (g[v].size() <= 1)
        return 1;

    int f = 0, s = 0;

    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            int n = largest_complete_tree(g, g[v][i], v);

            if (n >= f) {
                s = f;
                f = n;
            } else if (n > s)
                s = n;
        }
    }

    if (s > 0)
        return f + s + 1;
    else
        return 1;
}

int main() {

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        vector<vector<int> > g(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }

        int ans = 1;

        for (int i = 0; i < n; i++)
            ans = max(ans, largest_complete_tree(g, i, -1));

        cout << "Case #" << tc << ": " << (n - ans) << '\n';
    }

    return 0;
}
