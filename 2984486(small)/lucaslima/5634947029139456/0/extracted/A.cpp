#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) fr(i,0,n)
#define cl(a,b) memset((a), (b), sizeof(a))
#define all(c) (c).begin(), (c).end()
#define _ << ", " <<
#define db(x) cerr << #x " == " << x << endl

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 0x3f3f3f3f;

char str[42];

int count_bits(ll mask, int n) {
    int ct = 0;
    rep(i,n) if (mask & (1LL << i)) ++ct;
    return ct;
}

string tostr(ll mask, int sz) {
    string s = "";
    for(int i = sz - 1; i >= 0; --i) {
        s += ( mask & (1LL << i) ? "1" : "0" );
    }
    return s;
}

int main() {
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    for (int testcase = 1; testcase <= t; ++testcase) {
      int n, l;
      scanf("%d %d", &n, &l);
      vector<ll> flows;
      set<ll> required, possib;
      
      rep(i,n) {
        scanf("%s", str);
        ll mask = 0;
        rep(i, l) if (str[i] == '1') mask |= (1LL << i);
        flows.push_back(mask);
      }
      
      rep(i,n) {
        scanf("%s", str);
        ll mask = 0;
        rep(i, l) if (str[i] == '1') mask |= (1LL << i);
        required.insert(mask);
        possib.insert(flows[0] ^ mask);
      }
      
      int rsp = inf;
      for (ll x : possib) {
        bool ok = 1;
        rep(i,n) {
          ll mask = flows[i];
          rep(i,l) if (x & (1LL << i)) {
            if (mask & (1LL << i)) mask = mask & ~(1LL << i);
            else mask = mask | (1LL << i);
          }
          ok &= required.find(mask) != required.end();
        }
        if (ok) {
          rsp = min(rsp, count_bits(x, l));
        }
      }
      if (rsp != inf) printf("Case #%d: %d\n", testcase, rsp);
      else printf("Case #%d: NOT POSSIBLE\n", testcase);
    }
    return 0;
}
