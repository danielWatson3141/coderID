#include <cstdio>
#include <cstring>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <utility>

using namespace std;

int N;
vector< vector<int> > G;
vector<int> rs;
#define MN 1001
int memo[MN][MN + 1];
void input() {
    cin >> N;
    G.clear();
    G.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        G[y].push_back(x);
        G[x].push_back(y);
    }
    memset(memo, -1, sizeof(memo));
    rs.clear();
    for (int i = 0; i < N; i++) {
        if (G[i].size() == 2) {
            rs.push_back(i);
        }
    }
}

int dfs(int v, int prev) {
    if (G[v].size() == 1) return 1;
    if (prev < MN && G[v].size() == 2) return 1;
    if (memo[v][prev] >= 0) return memo[v][prev];
    int a[2] = {0, 0};
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == prev) continue;
        int x = dfs(G[v][i], v);
        if (x > a[1]) {
            a[0] = a[1];
            a[1] = x;
        } else if (x > a[0]) {
            a[0] = x;
        }
    }
    //cout << v << " " << prev << " { " << a[0] << " " << a[1] << " } " << endl;
    return memo[v][prev] = a[0] + 1 + a[1];
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        int ans = 1;
        for (int i = 0; i < N; i++) {
            ans = max(ans, dfs(i, MN));
        }
        cout << "Case #" << t << ": ";
        cout << N - ans << endl;
    }
    return 0;
}
