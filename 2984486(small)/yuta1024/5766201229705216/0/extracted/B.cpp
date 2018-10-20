#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dfs(int v, int del, deque<bool>& visited, const vector<vector<int> >& e) {
  if (del & (1 << v))
    return 0;

  visited[v] = true;
  int cnt = 0;
  for (unsigned int i = 0; i < e[v].size(); ++i) {
    if (!(del & (1 << e[v][i])) && !visited[e[v][i]])
      ++cnt;
  }

  if (cnt == 0)
    return 1;
  if (cnt != 2)
    return 0;

  int ret = 1;
  for (unsigned int i = 0; i < e[v].size(); ++i) {
    if (!(del & (1 << e[v][i])) && !visited[e[v][i]]) {
      ret += dfs(e[v][i], del, visited, e);
    }
  }

  return ret;
}

int main() {
  int T;
  cin >> T;

  for (int testcase = 1; testcase <= T; ++testcase) {
    int N;
    cin >> N;
    vector<vector<int> > edge(N);
    for (int i = 0; i < N - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      edge[x].push_back(y);
      edge[y].push_back(x);
    }

    int ans = N - 1;
    for (int i = 0; i < N; ++i) {
      for (int S = 0; S < (1 << N); ++S) {
        deque<bool> visited(N, false);
        ans = min(ans, N - dfs(i, S, visited, edge));
      }
    }
    
    cout << "Case #" << testcase << ": " << ans << endl;
  }
  return 0;
}
