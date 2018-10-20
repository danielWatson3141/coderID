/*****************************************
NAME    : wei.huang
PROJECT : Charging Chaos
LANG    : C++
2014    , renren-inc
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

# define Foreach(it, v)     for(__typeof((v).begin()) it = (v).begin(); (v).end() != it; ++it)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template<class T> inline void checkmax(T &a, T b) {
  if (a < b) a = b;
}

const int oo = 1 << 30          ;
const double eps = 1e-7       ;
const int N = 1               ;
const int M = 1               ;
const ll P = 10000000097ll    ;

void read() {

}

void print() {

}

ll convert2ll(string s) {
  ll ret = 0;
  Foreach (it, s) {
    ll bit = (*it == '1');
    ret = (ret << 1) | bit;
  }
  return ret;
}

set<ll> readOne(int n) {
  set<ll> ret;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ll x = convert2ll(s);
    ret.insert(x);
  }
  return ret;
}

int countBit(ll x) {
  int ans = 0;
  for (int i = 0; i < 64; i++) {
    ans += bool(x & (1ll << i));
  }
  return ans;
}

void doit() {
  int n, len;
  cin >> n >> len;
  set<ll> a = readOne(n);
  set<ll> b = readOne(n);
  ll ansBit = -1;
  Foreach (ia, a) {
    Foreach (ib, b) {
      ll c = (*ia) ^ (*ib);
      // cout << "c:" << c << " a:" << *ia << " b:" << *ib << endl;
      bool Ok = true;
      Foreach (it, a) {
        int to = c ^ (*it);
        if (b.count(to) == 0) {
          Ok = false;
        }
      }
      if (Ok) {
        ansBit = c;
      }
    }
  }
  if (-1 == ansBit) {
    puts("NOT POSSIBLE");
  } else {
    printf("%d\n", countBit(ansBit));
  }
}

int main(int argc, char const *argv[]) {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    read();
    doit();
    print();
  }

  return 0;
}

/**



**/


