#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

int n,l;
long long a[222],b[222];

long long get() {
  string s;
  cin >> s;
  long long x = 0;
  assert((int)s.size() == l);
  for(char ch : s) {
    x = (x << 1) | (ch - '0');
  }
  return x;
}

int conta(long long x) {
  int cnt = 0;
  while(x > 0) {
    if(x & 1) cnt++;
    x >>= 1;
  }
  return cnt;
}

void read() {
  cin >> n >> l;
  rep(i,n) a[i] = get();
  rep(i,n) b[i] = get();
}

void process(int testcase) {
  map<long long, int> base;
  rep(i,n) {
    rep(j,n) {
      long long z = a[i] ^ b[j];
      base[z]++;
    }
  }
  int ans = 1e9;
  for(auto key : base) if(key.second == n) {
    ans = min(ans, conta(key.first));
  }

  printf("Case #%d: ",testcase);
  if(ans >= (1e9)) puts("NOT POSSIBLE");
  else printf("%d\n",ans);
}

int main() {
  int T;
  cin >> T;
  for(int testcase=1;testcase<=T;testcase++) {
    read();
    process(testcase);
  }
  return 0;
}

