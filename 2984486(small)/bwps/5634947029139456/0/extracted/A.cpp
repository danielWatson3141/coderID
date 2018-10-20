#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, N, L;
string strs[2][200];

string add(string a, string b) {
  string res;
  FOR(i, 0, sz(a)) res.push_back(a[i] == b[i] ? '0' : '1');
  return res;
}

int calc(string diff) {
  int cnt = 0;
  FOR(i, 0, sz(diff)) if (diff[i] == '1') cnt++;
  vs v1, v2;
  FOR(i, 0, N) {
    v1.push_back(add(strs[0][i], diff));
    v2.push_back(strs[1][i]);
  }
  sort(all(v1));
  sort(all(v2));
  return (v1 == v2) ? cnt : oo;
}

int main() {
  cin >> T;
  FOR(cs, 1, T+1) {
    cin >> N >> L;
    FOR(i, 0, N) cin >> strs[0][i];
    FOR(i, 0, N) cin >> strs[1][i];
    int res = oo;
    FOR(i, 0, N) {
      string diff;
      FOR(j, 0, L) diff.push_back((strs[0][0][j] == strs[1][i][j]) ? '0' : '1');
      res = min(res, calc(diff));
    }
    cout << "Case #" << cs << ": ";
    if (res == oo) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }
	return 0;
}
