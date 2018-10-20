#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>

#include <memory.h>
using namespace std;

#pragma comment(linker, ”/STACK:108777216“)

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  int res; scanf("%d", &res); return res;
}

class timer {
public:
  timer() : t_(clock()) {}
  void start() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

bool visited[1001];

pair<int, int> dfs(int v, map< int, vector<int> >& edges) {
  visited[v] = true;
  int cnt = 0;
  if (edges[v].empty()) {
    return make_pair(0, 1);
  }
  int total_vertices = 0;
  vector<int> savings;
  for (int i = 0; i < edges[v].size(); ++i) {
    if (visited[edges[v][i]]) {
      continue;
    }
    pair<int, int> p = dfs(edges[v][i], edges);
    total_vertices += p.second;
    savings.push_back(p.first - p.second);
  }
  sort(all(savings));
  int cost = total_vertices;
  if (savings.size() >= 2) {
    cost = min(cost, cost + savings[0] + savings[1]);
  }
  return make_pair(cost, total_vertices + 1);
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T; cin >> T;

  for (int cs = 0; cs < T; ++cs) {
    int n; cin >> n;
    map< int, vector<int> > edges;
    for (int i = 0; i < n - 1; ++i) {
      int a, b; cin >> a >> b;
      edges[a-1].push_back(b-1);
      edges[b-1].push_back(a-1);
    }

    int sol = 1024;
    for (int i = 0; i < n; ++i) {
      memset(visited, false, sizeof(visited));
      sol = min(dfs(i, edges).first, sol);
    }

    printf("Case #%d: %d\n", cs + 1, sol);
  }

  return 0;
}
