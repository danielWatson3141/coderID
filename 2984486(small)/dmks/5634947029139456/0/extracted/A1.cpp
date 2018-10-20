#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i, n) for(int i = 0; i<(n); i++)
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define inf 2000000001
typedef vector<int> VI;
typedef vector<string> VS;

typedef long long i64;
typedef unsigned long long u64;

int go(int N, int L) {
  string str;
  vector<string> I, O;
  REP(i, N) {
    cin>>str;
    I.push_back(str);
  }
  REP(i, N) {
    cin>>str;
    O.push_back(str);
  }

  sort(O.begin(), O.end());
  int ret = inf;
  REP(k, 1<<L) {
    bitset<40> bs(k);
    VS u = I;
    REP(i, L) {
      if (bs[i]) {
        REP(j, N) {
          u[j][i] = '0' + (1 - (u[j][i] - '0'));
        }
      }
    }
    sort(u.begin(), u.end());
    if (u == O) {
      if (ret > bs.count()) ret = bs.count();
    }
  }
  if (ret >= L) return -1;
  return ret;
}

int main() {
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    int N, L;
    cin >> N >> L;
    int ret = go(N, L);
    cout << "Case #" << t << ": ";
    if (ret < 0) cout << "NOT POSSIBLE";
    else cout << ret;
    cout << endl;
  }
}
