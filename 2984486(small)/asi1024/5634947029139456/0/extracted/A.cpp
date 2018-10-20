#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long long ll;

ll f(string str) {
  ll res = 0;
  REP(i,str.size()) res = res * 2 + str[i];
  return res;
}

int solve(vector<ll> &v, vector<ll> &w) {
  sort(begin(v),end(v));
  int res = 99;
  do{
    ll mask = v[0] ^ w[0];
    bool flag = true;
    for (int i = 0; i < v.size() && flag; i++)
      flag &= ((v[i] ^ mask) == w[i]);
    if (flag) {
      int cnt = 0;
      REP(i,64) cnt += ((mask & (1LL << i)) > 0);
      res = min(res, cnt);
      //cout <<cnt << endl;
    }
  }while(next_permutation(begin(v),end(v)));
  return res;
}

int main() {
  int t, n, l;
  cin >> t;
  REP(cas,t) {
    cin >> n >> l;
    string str;
    vector<ll> v, w;
    REP(i,n) {
      cin >> str;
      v.push_back(f(str));
    }
    REP(i,n) {
      cin >> str;
      w.push_back(f(str));
    }
    int res = solve(v, w);
    if (res == 99) printf("Case #%d: NOT POSSIBLE\n", cas+1);
    else printf("Case #%d: %d\n", cas+1, res);
  }
  return 0;
}
