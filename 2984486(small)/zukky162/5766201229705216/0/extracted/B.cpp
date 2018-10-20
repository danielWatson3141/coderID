#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > Graph;

const int MAXN = 1001;
const int INF = 1<<28;
int N;
Graph G;

pair<int,int> rec(int v, int prev) {
  int child = 0;
  vector<pair<int,int> > t;
  for(int i = 0; i < (int)G[v].size(); ++i) {
    int nv = G[v][i];
    if(nv == prev) continue;
    pair<int,int> p = rec(nv, v);
    t.push_back(p);
    child += p.second;
  }

  int mincost = child;
  for(int i = 0; i < (int)t.size(); ++i) {
    for(int j = i+1; j < (int)t.size(); ++j) {
      mincost = min(mincost, t[i].first + t[j].first + child - (t[i].second + t[j].second));
    }
  }
  return make_pair(mincost, child+1);
}

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    cin >> N;
    G = Graph(N);
    for(int i = 0; i < N-1; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      G[X].push_back(Y);
      G[Y].push_back(X);
    }
    int ans = INF;
    for(int i = 0; i < N; ++i) {
      ans = min(ans, rec(i, -1).first);
    }
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
  return 0;
}
