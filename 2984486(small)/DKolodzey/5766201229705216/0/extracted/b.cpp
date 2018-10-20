#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::endl;

struct DfsReturn {
  DfsReturn(): weight(0), left(0) {}
  DfsReturn(int newweight, int newleft): weight(newweight), left(newleft) {}

  int weight;
  int left;
  int getNumberOfDeletions() {
    return (weight - left);
  }
};

const int MAX_N = 1050;
vector<int> g[MAX_N];

DfsReturn dfs(int v, int prev) {
  int nChildren = 0;
  int weight = 1;
  int maxleft[3] = {0, 0, 0};
  for (int i = 0; i < g[v].size(); ++i) {
    if (g[v][i] != prev)
    {
      ++nChildren;
      DfsReturn tmp = dfs(g[v][i], v);
      weight += tmp.weight;
      maxleft[2] = tmp.left;
      sort(maxleft, maxleft + 3, std::greater<int>());
      assert(maxleft[0] >= maxleft[1]);
    }
  }
  
  //cout << "Ending " << v << endl;
  //cout << "nChildren " << nChildren << endl;
  //cout << "weight " << weight << endl;
  //cout << "left " << maxleft[0] + maxleft[1] + 1 << endl;
  //cout << "maxleft of children " << maxleft[0] << " " << maxleft[1] << endl;

  if (nChildren < 2)
    return DfsReturn(weight, 1);

  return DfsReturn(weight, maxleft[0] + maxleft[1] + 1);
}

int main() {
  int T;
  cin >> T;
  
  for(int testcase = 1; testcase <= T; ++testcase) {
    int N;
    cin >> N;
    for (int i = 0; i <= N; ++i)
      g[i].clear();

    for (int i = 0; i < (N - 1); ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int ans = N - 1;

    for (int i = 1; i <= N; ++i) {
      //cout << "Tree " << i << endl;
      ans = min(dfs(i, 0).getNumberOfDeletions(), ans);
      //cout << endl;
    }

    cout << "case #" << testcase << ": " << ans << endl;
  }
  return 0;
}