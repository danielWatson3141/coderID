/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;

pair<int, int> dfs(int r, int p, vector<vector<int> > &G) {
    int all_sum = 1;
    std::vector<int> ch, cost, sum;
    for (int i = 0; i < G[r].size(); ++i) {
        int u = G[r][i];
        if (u != p) {
            ch.push_back(u);
            pair<int, int> e = dfs(u, r, G);
            cost.push_back(e.second);
            sum.push_back(e.first);
            all_sum += e.first;
        }
    }
    int ans = all_sum - 1;
    for (int i = 0; i < ch.size(); ++i) {
        for (int j = i + 1; j < ch.size(); ++j) {
            int that = cost[i] + cost[j] + (all_sum - 1 - sum[i] - sum[j]);
            ans = std::min(ans, that);
        }
    }
    return make_pair(all_sum, ans);
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    std::cin >> T;
    for (int t = 1, n; t <= T; ++t) {
        cin >> n;
        vector < vector<int> > G(n);
        for (int i = 1, u, v; i < n; ++i) {
            std::cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = n;
        for (int r = 0; r < n; ++r)
            ans = std::min(ans, dfs(r, r, G).second);
        std::cout << "Case #" << t << ": " << ans << std::endl;
    }
    return 0;
}
