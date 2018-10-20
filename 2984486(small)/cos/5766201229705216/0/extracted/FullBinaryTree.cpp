#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef int Weight;
struct Edge {
  int src;
  int dest;
  Weight weight;
  Edge(int src, int dest, Weight weight) : src(src), dest(dest), weight(weight) {;}
  bool operator<(const Edge &rhs) const {
    if (weight != rhs.weight) { return weight > rhs.weight; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void PrintMatrix(const Matrix &matrix) {
  for (int y = 0; y < (int)matrix.size(); y++) {
    for (int x = 0; x < (int)matrix[y].size(); x++) {
      printf("%d ", matrix[y][x]);
    }
    puts("");
  }
}

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

int n;
Graph g;

pair<int, int> calc(int node, int parent) {
  vector<pair<int, int> > costs;
  FORIT(it, g[node]) {
    int to = it->dest;
    if (to == parent) { continue; }
    pair<int, int> nret = calc(to, node);
    costs.push_back(make_pair(nret.second - nret.first, nret.second));
  }
  if (costs.size() == 0) { return make_pair(0, 1); }
  if (costs.size() == 1) { return make_pair(costs[0].second, costs[0].second + 1); }
  sort(costs.rbegin(), costs.rend());
  pair<int, int> ret = make_pair(0, 1);
  ret.first += (costs[0].second - costs[0].first) + (costs[1].second - costs[1].first);
  FOR(i, 2, costs.size()) {
    ret.first += costs[i].second;
  }
  REP(i, costs.size()) {
    ret.second += costs[i].second;
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  g = Graph(n);
  REP(i, n - 1) {
    int f, t;
    scanf("%d %d", &f, &t);
    f--; t--;
    g[f].push_back(Edge(f, t, 0));
    g[t].push_back(Edge(t, f, 0));
  }
  int ans = n;
  REP(i, n) {
    ans = min(ans, calc(i, i).first);
  }
  cout << ans << endl;
}
