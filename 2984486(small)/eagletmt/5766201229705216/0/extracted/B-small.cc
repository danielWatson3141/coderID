#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static const int INF = 10000000;

int binary_p(const vector<vector<int> >& g, int root, const vector<int>& deleted, vector<int>& visited)
{
  int c = 0;
  for (vector<int>::const_iterator it = g[root].begin(); it != g[root].end(); ++it) {
    if (!deleted[*it] && !visited[*it]) {
      ++c;
      visited[*it] = true;
      if (!binary_p(g, *it, deleted, visited)) {
        return false;
      }
    }
  }
  return c == 0 || c == 2;
}

int main()
{
  int T;
  cin >> T;

  for (int Ti = 1; Ti <= T; Ti++) {
    int N;
    cin >> N;
    vector<vector<int> > g(N);
    for (int i = 0; i < N-1; i++) {
      int u, v;
      cin >> u >> v;
      --u;  --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int ans = INF;
    for (unsigned s = 0; s < (1U<<N); s++) {
      vector<int> deleted(N, false);
      int c = 0;
      for (int i = 0; i < N; i++) {
        if (s & (1U<<i)) {
          deleted[i] = true;
          ++c;
        }
      }
      for (int i = 0; i < N; i++) {
        if (deleted[i]) {
          continue;
        }
        vector<int> visited(N, false);
        visited[i] = true;
        if (binary_p(g, i, deleted, visited)) {
          bool ok = true;
          for (int j = 0; j < N; j++) {
            if (!deleted[j] && !visited[j]) {
              ok = false;
            }
          }
          if (ok) {
            ans = min(ans, c);
            break;
          }
        }
      }
    }
    cout << "Case #" << Ti << ": " << ans << endl;
  }
  return 0;
}
