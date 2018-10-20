// B.cpp
//

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <functional>
using namespace std;

int vis[1005];

int dfs(int root, const vector<vector<int> > &graph) {
    vis[root] = 1;
    vector<int> children;
    for (int x = 0; x < graph[root].size(); ++x) {
        int next = graph[root][x];
        if (vis[next]) continue;
        int child = dfs(next, graph);
        children.push_back(child);
    }
    sort(children.begin(), children.end(), greater<int>());
    int ans = 1;
    if (children.size() <= 1) return ans;
    else return ans + children[0] + children[1];
}

int check(int root, const vector<vector<int> > &graph) {
//cout << endl << "check " << root << ' ' << mask << endl;
    int N = graph.size();
    memset(vis, 0, sizeof vis);
    return dfs(root, graph);
}

void solve(int tcase)
{
    cout << "Case #" << tcase << ": ";
    int N; cin >> N;
    vector<vector<int> > graph(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int num_nodes = check(i, graph);
        ans = max(ans, num_nodes);
    }
    cout << N - ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
