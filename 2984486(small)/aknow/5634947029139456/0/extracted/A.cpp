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
#include <cctype>
#include <climits>

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

int N, L;
int flow_1_cnt[45];
int device_1_cnt[45];

ll flow[160];
ll device[160];

int flip;
int best_flip;

ll toNumber(string& s) {
  ll tmp = 0;
  for (int i = 0; i < L; ++i) {
    int d = s[i] - '0';
    tmp <<= 1;
    tmp += d;
  }
  return tmp;
}

void readFlow() {
  string s;
  fill_n(flow_1_cnt, L, 0);
  for (int i = 0; i < N; ++i) {
    cin >> s;
    flow[i] = toNumber(s);

    for (int j = 0; j < L; ++j) {
      if ((flow[i] & (1 << j))) flow_1_cnt[j]++;
    }
  }
}

void readDevice() {
  string s;
  fill_n(device_1_cnt, L, 0);
  for (int i = 0; i < N; ++i) {
    cin >> s;
    device[i] = toNumber(s);

    for (int j = 0; j < L; ++j) {
      if ((device[i] & (1 << j))) device_1_cnt[j]++;
    }
  }
}

void flipSwitch(int l) {
  for (int i = 0; i < N; ++i) {
    flow[i] ^= (1 << l);
  }
}

bool initial() {
  flip = 0;
  for (int l = 0; l < L; ++l) {
    if (flow_1_cnt[l] == device_1_cnt[l]) continue;
    if (flow_1_cnt[l] == N - device_1_cnt[l]) {
      flipSwitch(l);
      flip++;
      continue;
    }

    return false;
  }
  return true;
}

ll suffixNumber(ll num, int l) {
  ll mask = (1 << (l+1)) - 1;
  return num & mask;
}

bool fullfill(int l) {
  vector<bool> used(N, false);
  for (int i = 0; i < N; ++i) { // device.
    ll device_suffix = suffixNumber(device[i], l);

    bool ok = false;
    for (int j = 0; j < N; ++j) { // flow.
      if (used[j]) continue;
      if (suffixNumber(flow[j], l) == device_suffix) {
        ok = true;
        used[j] = true;
        break;
      }
    }

    if (!ok) return false;
  }

  return true;
}

void test_dfs(int l) {
  if (l == L) {
    best_flip = min(flip, best_flip);
    return;
  }

  if (fullfill(l)) {
    test_dfs(l + 1);
  }

  // can flip.
  if (flow_1_cnt[l] == N - flow_1_cnt[l]) {
    flipSwitch(l);
    flip++;
    if (fullfill(l)) {
      test_dfs(l + 1);
    }
    flipSwitch(l);
    flip--;
  }
}

void test() {
  best_flip = INT_MAX;
  test_dfs(0);
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        cin >> N >> L;
        readFlow();
        readDevice();
        if (!initial()) {
          cout << "NOT POSSIBLE";
        } else {
          test();
          if (best_flip == INT_MAX) cout << "NOT POSSIBLE";
          else cout << best_flip;
        }

        printf("\n");
    }

    return 0;
}
