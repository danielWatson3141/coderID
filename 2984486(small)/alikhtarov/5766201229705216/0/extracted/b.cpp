#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

map<int, int> szcache;
map<tuple<int, size_t, int>, int> dfscache;

int sz(const vvi& graph, int x, int parent) {
  auto it = szcache.find(x);
  if (it != szcache.end()) {
    return it->second;
  }

  int s = 1;
  for (auto y : graph[x]) {
    if (y != parent) {
      s += sz(graph, y, x);
    }
  }

  return szcache[x] = s;
}

int dfs(const vvi& graph, int x, size_t y, int k, int parent) {
  auto key = make_tuple(x, y, k);
  auto it = dfscache.find(key);
  if (it != dfscache.end()) {
    return it->second;
  }
  auto& ans = dfscache[key];
  if (y == graph[x].size()) return ans = (k == 1 ? 1000000 : 0);
  if (graph[x][y] == parent) return ans = dfs(graph, x, y+1, k, parent);
  int rm = sz(graph, graph[x][y], x) + dfs(graph, x, y+1, k, parent);
  if (!k) {
    return ans = rm;
  } else {
    int kp = dfs(graph, graph[x][y], 0, 2, x) + dfs(graph, x, y+1, k-1, parent);
    return ans = std::min(rm, kp);
  }
}

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int n, a, b;
    cin >> n;
    vvi graph(n, vi());
    for (int i = 0; i < n - 1 && cin >> a >> b; ++i) {
      graph[a-1].push_back(b-1);
      graph[b-1].push_back(a-1);
    }
    
    int best = 1000000;
    for (int root = 0; root < n; ++root) {
      szcache.clear();
      dfscache.clear();
      best = std::min(best, dfs(graph, root, 0, 2, -1));
    }

    cout << "Case #" << ncase << ": " << best << endl;
  }
}
