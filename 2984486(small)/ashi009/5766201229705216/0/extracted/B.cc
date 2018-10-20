#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

int main() {
  int T, N;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> N;
    vector<vector<int>> link(N);
    map<pair<int, int>, int> memo, memo_cnt;
    int x, y;
    for (int i = 1; i < N; i++) {
      cin >> x >> y;
      x--, y--;
      link[x].push_back(y);
      link[y].push_back(x);
    }

    function<int(int, int)> count_sub = [&memo_cnt, &link, &count_sub](int root, int parent) {
      auto key = make_pair(root, parent);
      auto it = memo_cnt.find(key);
      if (it != memo_cnt.end())
        return it->second;
      auto &res = memo_cnt[key];
      res = 1;
      for (auto vertex : link[root]) {
        if (vertex != parent)
          res += count_sub(vertex, root);
      }
      return res;
    };
    function<int(int, int)> dp = [&memo, &link, &count_sub, &dp, &N](int root, int parent) {
      auto key = make_pair(root, parent);
      auto it = memo.find(key);
      if (it != memo.end())
        return it->second;
      auto &res = memo[key];
      vector<int> edges;
      for (int vertex : link[root])
        if (vertex != parent)
          edges.push_back(vertex);
      if (edges.size() == 0) {
        return res = 0;
      }
      if (edges.size() == 1) {
        return res = count_sub(edges.front(), root);
      }
      if (edges.size() == 2) {
        return res = dp(edges.front(), root) + dp(edges.back(), root);
      }
      int best = N;
      for (int i = 0; i < edges.size(); i++)
        for (int j = i + 1; j < edges.size(); j++) {
          int tmp = dp(edges[i], root) + dp(edges[j], root);
          for (int k = 0; k < edges.size(); k++) {
            if (k != i && k != j)
              tmp += count_sub(edges[k], root);
          }
          best = min(best, tmp);
        }
      return res = best;
    };
    int result = N - 1;
    for (int i = 0; i < N; i++) {
      result = min(result, dp(i, -1));
    }
    printf("Case #%d: %d\n", CASE, result);
  }
}
