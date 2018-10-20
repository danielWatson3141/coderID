// Bsmall.cpp
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
using namespace std;

int vis[20];

int count_bit(int mask)
{
    int cnt = 0;
    while (mask) {
        cnt++;
        mask &= mask-1;
    }
    return cnt;
}

bool dfs(int root, int mask, const vector<vector<int> > &graph) {
    vis[root] = 1;
    int cnt = 0;
    for (int x = 0; x < graph[root].size(); ++x) {
        int next = graph[root][x];
        if (!(1<<next & mask)) continue;
        if (vis[next]) continue;
        cnt++;
        if (!dfs(next, mask, graph)) return false;
    }
//cout << "dfs " << root << ' ' << mask << ' ' << cnt << endl;
    return cnt == 0 || cnt == 2;
}

bool check(int root, int mask, const vector<vector<int> > &graph) {
//cout << endl << "check " << root << ' ' << mask << endl;
    int N = graph.size();
    memset(vis, 0, sizeof vis);
    if (!dfs(root, mask, graph)) return false;
    for (int i = 0; i < N; ++i) if (1<<i & mask)
        if (!vis[i]) return false;
    return true;
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
    for (int mask = 0; mask < (1<<N); ++mask) {
        int num_nodes = count_bit(mask);
        for (int i = 0; i < N; ++i) {
            if (check(i, mask, graph)) ans = max(ans, num_nodes);
        }
    }
    cout << N - ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
