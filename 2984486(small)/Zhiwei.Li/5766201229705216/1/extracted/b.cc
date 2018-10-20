#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<set<int> > edges;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; }

pair<int, int> work(int v, vector<bool> *visited) {
  (*visited)[v] = true;
  vector<pair<int, int> > s;
  int total = 1;
  for (set<int>::iterator it = edges[v].begin(); it != edges[v].end(); ++it) {
    int p = *it;
    if (!(*visited)[p]) {
      pair<int, int> res = work(p, visited);
      s.push_back(res);
      total += res.second;
    }
  }
  if ((int)s.size() < 2) {
    return make_pair(1, total);
  }
  sort(s.begin(), s.end(), cmp);
  return make_pair(s[0].first + s[1].first + 1, total);
}

int main() {
  int tc;
  scanf("%d", &tc);
  int n;
  for (int cas = 1; cas <= tc; ++cas) {
    scanf("%d", &n);
    edges.clear();
    edges.resize(n, set<int>());
    for (int m = 1; m < n; ++m) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u; --v;
      edges[u].insert(v);
      edges[v].insert(u);
    }
    int ans = n;
    for (int r = 0; r < n; ++r) {
      vector<bool> visited(n, false);
      pair<int, int> res = work(r, &visited);
      if (res.second - res.first < ans) ans = res.second - res.first;
    }
    printf("Case #%d: %d\n", cas, ans);
  }
  return 0;
}
