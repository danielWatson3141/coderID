#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int n;
std::vector<int> d;
std::vector<std::vector<int>> a;
std::vector<std::unordered_map<int, int>> f;

int compute_f(int u, int p) {
  if (f[u].count(p) == 0) {
    int deg = d[u];
    if (p != -1) {
      deg--;
    }
    if (deg <= 1) {
      f[u][p] = 1;
    } else {
      std::vector<int> r;
      for (int v : a[u]) {
        if (v == p) {
          continue;
        }
        r.push_back(compute_f(v, u));
      }
      std::sort(r.begin(), r.end());
      f[u][p] = 1 + r[deg - 2] + r[deg - 1];
    }
  }
  return f[u][p];
}

int main() {
  int t;
  std::cin >> t;
  for (int x = 1; x <= t; x++) {
    d.clear();
    a.clear();
    f.clear();
    std::cin >> n;
    d.resize(n);
    a.resize(n);
    f.resize(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--, v--;
      d[u]++;
      a[u].push_back(v);
      d[v]++;
      a[v].push_back(u);
    }
    int y = n;
    for (int r = 0; r < n; r++) {
      int z = compute_f(r, -1);
      y = std::min(y, n - z);
    }
    std::cout << "Case #" << x << ": " << y << std::endl;
  }
}
