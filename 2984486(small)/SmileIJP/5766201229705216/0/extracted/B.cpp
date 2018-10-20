#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

vector< vector< int > > edges;
vector< bool > was;

int dfs(int v) {
  was[v] = true;
  int mx1 = -1;
  int mx2 = -1;
  for (size_t j = 0; j < edges[v].size(); ++j) {
    int u = edges[v][j];
    if (!was[u]) {
      int val = dfs(u);
      if (mx1 <= val) {
        mx2 = mx1;
        mx1 = val;
      } else if (mx2 <= val) {
        mx2 = val;
      }
    }
  }
  return mx2 == -1 ? 1 : (1 + mx1 + mx2);
}

void solve() {
  int n = next< int >();
  edges = vector< vector< int > >(n, vector< int >());
  was = vector< bool >(n, false);
  for (int i = 0; i < n - 1; ++i) {
    int x = next< int >() - 1;
    int y = next< int >() - 1;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  int mx_size = 0;
  for (int i = 0; i < n; ++i) {
    fill(ALL(was), false);
    mx_size = max(mx_size, dfs(i));
  }
  cout << n - mx_size << endl;
}

int main() {

//  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

