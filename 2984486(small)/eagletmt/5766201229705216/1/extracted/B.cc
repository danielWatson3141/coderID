#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;
static const int INF = 10000000;

vector<int> total_count;

void dfs1(const vector<vector<int> >& g, int root, vector<int>& visited)
{
  total_count[root] = 1;
  for (vector<int>::const_iterator it = g[root].begin(); it != g[root].end(); ++it) {
    if (!visited[*it]) {
      visited[*it] = true;
      dfs1(g, *it, visited);
      total_count[root] += total_count[*it];
    }
  }
  //cerr << "total[" << root+1 << "] = " << total_count[root] << endl;
}

int ret;

int solve(const vector<vector<int> >& g, int root, vector<int>& visited)
{
  vector<int> children;
  for (vector<int>::const_iterator it = g[root].begin(); it != g[root].end(); ++it) {
    if (!visited[*it]) {
      visited[*it] = true;
      children.push_back(*it);
      //visited[*it] = true;
      //r += solve(g, *it, visited);
    }
  }

  vector<pair<int,int> > v;
  for (vector<int>::const_iterator it = children.begin(); it != children.end(); ++it) {
    v.push_back(make_pair(total_count[*it], *it));
  }
  sort(v.rbegin(), v.rend());

  if (v.size() == 1) {
    ret += v[0].first;
    v.pop_back();
  } else if (children.size() > 2) {
    while (v.size() > 2) {
      ret += v.back().first;
      v.pop_back();
    }
  }

  const int N = v.size();
  for (int i = 0; i < N; i++) {
    solve(g, v[i].second, visited);
  }
  return 0;
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

    total_count.resize(N);
    int ans = INF;
    vector<int> visited(N);
    for (int i = 0; i < N; i++) {
      fill(visited.begin(), visited.end(), 0);
      visited[i] = true;
      dfs1(g, i, visited);

      fill(visited.begin(), visited.end(), 0);
      visited[i] = true;
      ret = 0;
      solve(g, i, visited);

      ans = min(ans, ret);
    }
    cout << "Case #" << Ti << ": " << ans << endl;
  }
  return 0;
}
