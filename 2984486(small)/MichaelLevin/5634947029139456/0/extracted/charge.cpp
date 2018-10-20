#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "A"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

ll StringToNum(const string& s) {
  ll result = 0;
  for (int i = 0; i < s.length(); ++i) {
    result = result * 2 + (s[i] - '0');
  }
  return result;
}

int MinSwitchesStupid(vector<ll> devices, const vector<ll>& outlets, int L) {
  sort(devices.begin(), devices.end());
  int minSwitched = L + 1;
  for (int mask = 0; mask < (1 << L); ++mask) {
    vector<ll> switched(outlets.size());
    for (int i = 0; i < outlets.size(); ++i) {
      switched[i] = outlets[i] ^ mask;
    }
    sort(switched.begin(), switched.end());
    int bits = 0;
    if (switched == devices) {
      for (int i = 0; i < L; ++i) {
        if ((mask >> i) & 1) {
          ++bits;
        }
      }
      minSwitched = min(minSwitched, bits);
    }
  }
  if (minSwitched > L) {
    return -1;
  }
  return minSwitched;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int N, L;
    cin >> N >> L;
    vector<ll> devices(N);
    for (int i = 0; i < N; ++i) {
      string buffer;
      cin >> buffer;
      devices[i] = StringToNum(buffer);
    }
    vector<ll> outlets(N);
    for (int i = 0; i < N; ++i) {
      string buffer;
      cin >> buffer;
      outlets[i] = StringToNum(buffer);
    }
    int result = MinSwitchesStupid(devices, outlets, L);
    cout << "Case #" << (test_index + 1) << ": ";
    if (result == -1) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }
  return 0;
}
