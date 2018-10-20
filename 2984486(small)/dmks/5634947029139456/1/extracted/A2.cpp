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

int N, L;
vector<i64> I, O;
int ret = inf;
i64 one = 1;

void read(vector<i64>& v) {
  string str;
  REP(i, N) {
    cin >> str;
    i64 cur = 0;
    REP(j, L) {
      cur = (cur << 1) + (str[j] - '0');
    }
    v.push_back(cur);
  }
}

bool check(int pos, int flip) {
  vector<i64> nI, nO;
  i64 full = (one << pos) - 1;
  REP(i, I.size()) {
    nI.push_back((I[i] & full) ^ flip);
    nO.push_back(O[i] & full);
  }
  sort(nI.begin(), nI.end());
  sort(nO.begin(), nO.end());
  return nI == nO;
}

void doit(int pos, int flip, int count) {
  // cout << "pos: " << pos << ", " << flip << " " << count << endl;
  if (pos == L) {
    if (ret > count) ret = count;
    return;
  }
  if (check(pos + 1, flip)) {
    doit(pos + 1, flip, count);
  }
  if (check(pos + 1, flip | (one << pos))) {
    doit(pos + 1, flip | (one<<pos), count + 1);
  }
}

int go() {
  I.clear(); O.clear();
  read(I); read(O);
  ret = inf;
  doit(0, 0, 0);
  if (ret > L) return -1;
  else return ret;
}

int main() {
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    cin >> N >> L;
    int ret = go();
    cout << "Case #" << t << ": ";
    if (ret < 0) cout << "NOT POSSIBLE";
    else cout << ret;
    cout << endl;
  }
}
