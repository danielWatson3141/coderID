#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Check {
  Check(int n_, const vector<pair<int, int>>& tree_)
      : n(n_), tree(tree_), edge(n), decode(n), reach(n) {
    for (auto t : tree) {
      edge[t.first].push_back(t.second);
      edge[t.second].push_back(t.first);
    }
  }
  int countbits(int i) {
    int ans = 0;
    while (i) {
      if (i & 1) ans++;
      i>>=1;
    }
    return ans;
  }
  int search() {
    int m = n + 10;
    for (int i = 0; i < (1 << n); i++) {
      if (istree(i)) {
        m = min(m, n - countbits(i));
      }
    }
    return m;
  }
  bool istree(int pos) {
    for (int i = 0; i < n; i++) {
      decode[i] = ((pos >> i)&1) == 1;
    }
    for (int j = 0; j < n; j++) {
      if (isroot(j) && canreach(j)) return true;
    }
    return false;
  }
  bool canreach(int root) {
    fill(reach.begin(), reach.end(), false);
    paint(root);
    for (int i = 0; i < n; i++) {
      if (decode[i] && !reach[i]) return false;
    }
    return true;
  }
  void paint(int node) {
    reach[node] = true;
    for (auto x : edge[node]) {
      if (decode[x] && !reach[x]) {
        paint(x);
      }
    }
  }
  bool isroot(int root) {
    if (!decode[root]) return false;
    for (int i = 0; i < n; i++) {
      int c = 0;
      if (!decode[i]) continue;
      for (auto x : edge[i]) {
        if (decode[x]) c++;
      }
      if (i == root && c != 2) {
        //cout << " root = " << c << "\n";
        return false;
      }
      if (i != root && (c !=1 && c!=3)) {
        //cout << "node = " << i << " -> " << c << "\n";
        return false;
      }
    }
    return true;
  }
  int n;
  const vector<pair<int, int>>& tree;
  vector<vector<int>> edge;
  vector<bool> decode;
  vector<bool> reach;
};

int main() {
  int tot;
  cin >> tot;
  for (int t = 1; t <= tot; t++) {
    int n;
    cin >> n;
    vector<pair<int,int>> tree;
    for (int i = 0; i < n - 1; i++) {
      int a,b;
      cin >> a >> b;
      tree.push_back(make_pair(a-1,b-1));
    }
    Check c(n, tree);
    cout << "Case #" << t << ": " << c.search() << "\n";
  }
  return 0;
}
