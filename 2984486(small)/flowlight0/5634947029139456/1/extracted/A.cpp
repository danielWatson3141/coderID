#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;


void solve(){
  int N, L;
  cin >> N >> L;
  vector<string> outlets(N), devices(N);
  REP(i, N) cin >> outlets[i];
  REP(i, N) cin >> devices[i];

  int res = 1e9;

  REP(i, N){
    int count = 0;
    vector<string> out(outlets);
    vector<string> dev(devices);

    // cout << outlets[i] << " " << devices[0] << endl;
    REP(j, L){
      if (outlets[i][j] != devices[0][j]){
        count++;
        REP(k, N){
          out[k][j] = out[k][j] == '0' ? '1' : '0';
        }
      }
    }
    
    REP(j, N){
      // cerr << "HOGE: " << out[j] << endl;
      bool ok = false;
      REP(k, N){
        // cerr << dev[k] << endl;
        if (out[j] == dev[k]) ok = true;
      }
      if (!ok) count = 1e9;
    }
    res = min(res, count);
    // cout << count << endl;
  }
  
  if (res > L){
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << res << endl;
  }
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    cout << "Case #" << t + 1 << ": ";
    solve();
  }
  return 0;
}
