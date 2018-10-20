#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int dfs(vector<vector<int>> const& adjl, int v, int from = -1)
{
    vector<int> subtrees;
    for (int w : adjl[v]) if (w != from) {
        int subtree = dfs(adjl, w, v);
        subtrees.push_back(subtree);
    }
    sort(subtrees.begin(), subtrees.end(), greater<int>());
    int deg = adjl[v].size();
    if (deg >= 3 || deg == 2 && from == -1) {
        return 1 + subtrees[0] + subtrees[1];
    }
    return 1;
}

int main()
{
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;
        vector<pair<int, int>> links(n - 1);
        vector<vector<int>> adjl(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adjl[a - 1].push_back(b - 1);
            adjl[b - 1].push_back(a - 1);
        }
        int result = n;
        for (int root = 0; root < n; ++root) if (adjl[root].size() >= 2) {
            result = min(result, n - dfs(adjl, root));
        }

        cout << "Case #" << test << ": " << (result == n ? 1 : result) << endl;
    }
}
