#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF = 1 << 29;

pair<int, int> doit(int v, int p, vector<vector<int> >& G) {
  int ans = 0;
  int children = 0;
  int anc = 0;
  vector<int> dif;
  rep(i, G[v].size()) {
    if (G[v][i] == p) continue;
    children++;
    pair<int, int> res = doit(G[v][i], v, G);
    ans += res.first;
    anc += res.second;
    dif.push_back(res.second - res.first);
  }

  sort(dif.begin(), dif.end());

  if (children == 1) {
    ans += dif[0];
  } else {
    rep(i, children - 2) {
      ans += dif[i];
    }
  }
  return make_pair(ans, anc + 1);
}

void solve() {
  int N;
  cin >> N;
  vector<vector<int> > G(N);

  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int ans = INF;
  rep(i, N) {
    ans = min(ans, doit(i, -1, G).first);
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
