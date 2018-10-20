#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef int Weight;
struct Edge{
  int src, dest;
  bool operator < (const Edge &rhs) const {
    return make_pair(src,dest) < make_pair(rhs.src,rhs.dest);
  }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool flag[1024];
int solve_memo[1024];
int dfs_memo[1024];

int dfs(Graph &g, int v) {
  if (flag[v]) return 0;
  if (dfs_memo[v] >= 0) return dfs_memo[v];
  flag[v] = true;
  int res = 0;
  REP(i,g[v].size()) {
    res += dfs(g, g[v][i].dest);
  }
  flag[v] = false;
  return dfs_memo[v] = res + 1;
}

int solve(Graph &g, int v) {
  if (flag[v]) return 0;
  if (solve_memo[v] >= 0) return solve_memo[v];
  flag[v] = true;
  int cnt = 0;
  REP(i,g[v].size())
    if (!flag[g[v][i].dest]) cnt++;
  if (cnt == 2 || cnt == 0) {
    int res = 0;
    REP(i,g[v].size())
      res += solve(g, g[v][i].dest);
    flag[v] = false;
    return solve_memo[v] = res;
  }
  if (cnt == 1) {
    flag[v] = false;
    return solve_memo[v] = dfs(g, v) - 1;
  }
  int res = 0;
  vector<int> w;
  REP(i,g[v].size()) {
    res += dfs(g, g[v][i].dest);
    w.push_back(solve(g,g[v][i].dest)-dfs(g,g[v][i].dest));
  }
  sort(begin(w),end(w));
  flag[v] = false;
  return solve_memo[v] = res + w[0] + w[1];
}

int main() {
  int t; cin >> t;
  REP(cas,t) {
    int n; cin >> n;
    Graph g(n);
    REP(i,n-1) {
      int a, b;
      cin >> a >> b;
      g[a-1].push_back((Edge){a-1, b-1});
      g[b-1].push_back((Edge){b-1, a-1});
    }
    int res = 999999999;
    REP(i,n) {
      REP(i,1024){
        flag[i] = false;
        solve_memo[i] = -1;
        dfs_memo[i] = -1;
      }
      //cout << solve(g, i) << endl;
      res = min(res, solve(g, i));
    }
    printf("Case #%d: %d\n", cas+1, res);
  }
  return 0;
}
