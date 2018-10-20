#include<iostream>
#include<queue>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

struct Solver {
  vector<vector<int> > edge;
  map<pair<int, int>, int> mem;
  map<pair<int, int>, int> mem2;

  int del(int a, int b) {
    if (edge[a].size() == 1u) return 1;
    if (mem2.count(make_pair(a, b))) return mem2[make_pair(a, b)];
    int res = 1;
    rep (i, edge[a].size()) if (edge[a][i] != b) res += del(edge[a][i], a);
    return mem2[make_pair(a, b)] = res;
  } 

  int solve(int a, int b) {
    if (edge[a].size() == 1u) return 0;
    if (mem.count(make_pair(a, b))) return mem[make_pair(a, b)];
    if (edge[a].size() == 2u) {
      if (b == edge[a][0]) return mem[make_pair(a, b)] = del(edge[a][1], a);
      if (b == edge[a][1]) return mem[make_pair(a, b)] = del(edge[a][0], a);
    }
    if (edge[a].size() == 3u) {
      int res = 0;
      rep (i, 3) if (edge[a][i] != b) res += solve(edge[a][i], a);
      return mem[make_pair(a, b)] = res;
    }
    int res = edge.size() - 1;
    rep (i, edge[a].size()) rep (j, i) {
      if (edge[a][i] == b || edge[a][j] == b) continue;
      int r = solve(edge[a][i], a) + solve(edge[a][j], a);
      rep (k, edge[a].size()) if (i != k && j != k && edge[a][k] != b) r += del(edge[a][k], a);
      res = min(res, r);
    }
    return mem[make_pair(a, b)] = res;
  }

  int solve() {
    int n;
    cin >> n;
    edge.resize(n);
    rep (i, n - 1) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
    int res = n - 1;
    rep (i, n) {
      edge[i].push_back(i);
      res = min(res, solve(i, i));
      edge[i].pop_back();
    }
    return res;
  }
};

int main() {
  int t;
  cin >> t;
  rep (i, t) {
    Solver solver;
    int res = solver.solve();
    cout << "Case #" << i + 1 << ": " << res << endl;
  }
}
