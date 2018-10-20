#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

unsigned int count_ones(unsigned int c) {
  unsigned int ans = 0;
  while(c != 0) {
    if(c % 2 == 1) {
      ++ans;
    }
    c >>= 1;
  }
  return ans;
}

void Solver::solve() {
  int N, L;
  cin >> N >> L;
  vector<unsigned int> flow(N, 0), devs(N, 0);
  string s;
  int i, j;

  getchar();
  getline(cin, s);
  string::iterator it = s.begin();
  REP(0, N, i) {
    REP(0, L, j) {
      flow[i] *= 2;
      flow[i] += (*it) - '0';
      ++it;
    }
    if(it == s.end())
      break;
    ++it;
  }

  getline(cin, s);
  it = s.begin();
  REP(0, N, i) {
    REP(0, L, j) {
      devs[i] *= 2;
      devs[i] += (*it) - '0';
      ++it;
    }
    if(it == s.end())
      break;
    ++it;
  }
  sort(all(devs));

  bool flag = false;
  unsigned int bits, el, min_num_bits = L + 1;
  vector<unsigned int> rflow(N);
  el = 1 << L;
  REP(0, el, bits) {
    REP(0, N, i) {
      rflow[i] = (flow[i] ^ bits);
    }
    sort(all(rflow));

    bool ok = true;
    REP(0, N, i) {      
      if(rflow[i] != devs[i]) {
	ok = false;
      }
    }
    if(ok) {
      flag = true;
      min_num_bits = min(min_num_bits, count_ones(bits));
    }
  }

  if(!flag) {
    cout << "NOT POSSIBLE" << endl;
  }
  else {
    cout << min_num_bits << endl;
  }

}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

