#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

vector<vector<int>> edge;
vector<int> subNodes;
vector<int> maxRemain;
int N;

void read() {
  cin >> N;

  subNodes.resize(N);
  maxRemain.resize(N);

  edge.clear();
  edge.resize(N);

  int x, y;
  for (int i = 0; i < N-1; ++i) {
    cin >> x >> y;
    x--;
    y--;

    edge[x].push_back(y);
    edge[y].push_back(x);
  }
}

int computeSubNodes_dfs(int r) {
  if (subNodes[r]) return subNodes[r];

  int cnt = 0;
  for (int v : edge[r]) cnt += computeSubNodes_dfs(v);
  subNodes[r] = cnt;
  return cnt;
}

void computeSubNodes(int r) {
  fill(subNodes.begin(), subNodes.end(), 0);
  computeSubNodes_dfs(r);
}

int computeMaxRemain_dfs(int r, int parent) {
  if (maxRemain[r]) return maxRemain[r];

  if (parent == -1 && edge[r].size() < 2) {
    maxRemain[r] = 1;
  } else if (parent != -1 && edge[r].size() < 3) {
    maxRemain[r] = 1;
  } else {
    // >= 2.
    vector<int> remain(edge[r].size());
    for (unsigned i = 0; i < edge[r].size(); ++i) {
      if (edge[r][i] == parent) {
        remain[i] = 0;
      } else {
        remain[i] = computeMaxRemain_dfs(edge[r][i], r);
      }
    }
    sort(remain.begin(), remain.end(), greater<int>());
    maxRemain[r] = remain[0] + remain[1] + 1;
  }

  return maxRemain[r];
}

int computeMaxRemain(int r) {
  fill(maxRemain.begin(), maxRemain.end(), 0);
  return computeMaxRemain_dfs(r, -1);
}

int main() {
  int caseN;
  scanf("%d", &caseN);

  for (int cc = 1; cc <= caseN; ++cc) {
    printf("Case #%d: ", cc);

    read();
    int best = 0;
    for (int i = 0; i < N; ++i) {
      best = max(best, computeMaxRemain(i));
    }
    cout << N - best;

    printf("\n");
  }

  return 0;
}
