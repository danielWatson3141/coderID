#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

std::pair<int, int> dfs(int r, int p, std::vector<std::vector<int>> &G) {
  int all_sum = 1;
  std::vector<int> ch, cost, sum;
  for (int &u : G[r]) {
    if (u != p) {
      ch.push_back(u);
      auto e = dfs(u, r, G);
      cost.push_back(e.second);
      sum.push_back(e.first);
      all_sum += e.first;
    }
  }
  int ans = all_sum - 1;
  for (int i = 0; i < ch.size(); ++i) {
    for (int j = i + 1; j < ch.size(); ++j) {
      int that =  cost[i] + cost[j] + (all_sum - 1 - sum[i] - sum[j]);
      ans = std::min(ans, that);
    }
  }
  // std::cout << r << " " << ans << std::endl;
  return std::make_pair(all_sum, ans);
}

int main() {
  int T;
  std::cin >> T;
  for (int t = 1, n; t <= T; ++t) {
    std::cin >> n;
    std::vector<std::vector<int>> G(n);
    for (int i = 1, u, v; i < n; ++i) {
      std::cin >> u >> v;
      -- u;
      -- v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int ans = n;
    for (int r = 0; r < n; ++r) {
    ans = std::min(ans, dfs(r, r, G).second);
    // ans = std::min(ans, dfs(2, 2, G).second);
    }
    std::cout << "Case #" << t << ": " << ans << std::endl;
  }
  return 0;
}
