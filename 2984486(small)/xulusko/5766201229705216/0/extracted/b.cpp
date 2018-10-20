#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > G;
vector<int> mk;

int search(int v) {
  //if (mk[v])
  mk[v] = 1;
  int a = -1, b = -1;
  for (int i = 0; i < int(G[v].size()); i++) if (mk[G[v][i]] == 0) {
    int t = search(G[v][i]);
    if (a == -1 || a < t) { b = a; a = t; }
    else if (b == -1 || b < t) b = t;
  }
  if (b == -1) return 1;
  else return a+b+1;
}

int main() {
  ios_base::sync_with_stdio(0);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int n; cin >> n;
    G.clear(); G.resize(n+47);
    for (int i = 1; i < n; i++) { int x, y; cin >> x >> y; G[x-1].push_back(y-1); G[y-1].push_back(x-1); }
    int best = n;
    for (int i = 0; i < n; i++) { mk.clear(); mk.resize(n+47, 0); best = min(best, n-search(i)); }
    cout << "Case #" << t << ": " << best << "\n";
  }
}
