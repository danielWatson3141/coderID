#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
vector<int> g[1000];

int dfs(int u, int f) {
  vector<int> sons;
  for (int v:g[u]) if (v!=f) {
    sons.push_back(dfs(v, u));
  }
  if (sons.size() < 2) {
    return 1;
  } else {
    sort(sons.begin(), sons.end());
    reverse(sons.begin(), sons.end());
    return 1 + sons[0] + sons[1];
  }
}

int main() {
  int Z;
  cin >> Z;
  for (int z=1;z<=Z;++z) {
    cin >> n;
    for (int i = 0; i < 1000; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a,b;
      cin>>a>>b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int best = n - 1;
    for (int k = 0; k < n; ++k)
      best = min(best, n - dfs(k, -1));
    cout << "Case #" << z << ": " << best << endl;
  }
  return 0;
}
