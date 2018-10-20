#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

long long convert(string str) {
  long long res = 0;
  rep (i, str.size()) if (str[i] == '1') res |= 1LL << i;
  return res;
}

string solve() {
  int n, l;
  cin >> n >> l;
  vector<string> a(n), b(n);
  vector<long long> aa(n), bb(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  rep (i, n) aa[i] = convert(a[i]);
  sort(aa.begin(), aa.end());
  int res = 100;
  rep (i, n) {
    long long bit = 0;
    rep (j, l) if (a[0][j] != b[i][j]) bit |= 1LL << j;
    rep (j, n) bb[j] = convert(b[j]) ^ bit;
    sort(bb.begin(), bb.end());
    rep (j, n) if (aa[j] != bb[j]) goto fail;
    res = min(res, __builtin_popcountll(bit));
  fail:;
  }
  if (res == 100) return "NOT POSSIBLE";
  stringstream ss;
  string r;
  ss << res;
  ss >> r;
  return r;
}

int main() {
  int t;
  cin >> t;
  rep (i, t) cout << "Case #" << i + 1 << ": " << solve() << endl;
}
