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

int T, N;
vi adj[1100];

int rek(int n, int p) {
  vi vals;
  FOR(i, 0, sz(adj[n])) {
    int m = adj[n][i];
    if (m == p) continue;
    vals.push_back(rek(m, n));
  }
  if (sz(vals) < 2) return 1;
  sort(all(vals));
  reverse(all(vals));
  return 1 + vals[0] + vals[1];
}

int main() {
  cin >> T;
  FOR(cs, 1, T+1) {
    cin >> N;
    FOR(i, 0, 1100) adj[i].clear();
    FOR(i, 0, N-1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int res = N-1;
    FOR(i, 0, N) res = min(res, N - rek(i, -1));
    cout << "Case #" << cs << ": " << res << endl;
  }
	return 0;
}
