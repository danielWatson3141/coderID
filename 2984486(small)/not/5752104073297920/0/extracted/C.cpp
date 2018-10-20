#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  vector<vector<int> > res;
  int n = 100;
  rep (i, 10000) {
    vector<int> v;
    rep (j, n) v.push_back(j);
    rep (j, n) swap(v[j], v[rand() % n]);
    res.push_back(v);
  }
  sort(res.begin(), res.end());
  rep (i, res.size()) {
    rep (j, n) cout << res[i][j] << " ";
    cout << endl;
  }
}
