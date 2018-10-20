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

vvi G;
int N;
int s;
int t;
vb done;

int dfs(int a, int by) {
  if (done[a]) {
    return 0;
  }
  done[a] = true;
  if (a == t) {
    return by;
  }
  for (int i = 0; i < N; ++i) {
    if (G[a][i] > 0) {
      int am = dfs(i, min(by, G[a][i]));
      if (am > 0) {
        G[a][i] -= am;
        G[i][a] += am;
        return am;
      }
    }
  }
  return 0;
}

int MaxFlow() {
  int fl = 0;
  int am = 1;
  while (am > 0) {
    done.assign(N, false);
    
    am = dfs(s, 1000000000);
    if (am > 0) {
      fl += am;
    }
  }
  return fl;
}

int MinSwitchesFast(vector<ll> devices, const vector<ll>& outlets, int L) {
  int minSwitched = L + 1;
  for (int i = 0; i < outlets.size(); ++i) {
    int mask = devices[0] ^ outlets[i];
    int bits = 0;
    for (int j = 0; j < L; ++j) {
      if ((mask >> j) & 1) {
        ++bits;
      }
    }
    if (bits >= minSwitched) {
      continue;
    }
    N = devices.size() + outlets.size();
    s = N - 2;
    t = N - 1;
    G.assign(N, vi(N, 0));
    for (int d = 0; d + 1 < devices.size(); ++d) {
      G[s][d] = 1;
      G[d + devices.size() - 1][t] = 1;
      for (int e = 0; e + 1 < outlets.size(); ++e) {
        int k = e;
        if (k >= i) {
          ++k;
        }
        if ((devices[d + 1] ^ mask) == outlets[k]) {
          G[d][e + devices.size() - 1] = 1;
        }
      }
    }
    int flow = MaxFlow();
    if (flow == devices.size() - 1) {
      minSwitched = bits;
    }
  }
  if (minSwitched > L) {
    return -1;
  }
  return minSwitched;
}

int MinSwitchesVeryFast(vector<ll> devices, const vector<ll>& outlets, int L) {
  int minSwitched = L + 1;
  set<ll> other_devices(devices.begin() + 1, devices.end());
  for (int i = 0; i < outlets.size(); ++i) {
    int mask = devices[0] ^ outlets[i];
    set<ll> switched;
    for (int j = 0; j < outlets.size(); ++j) {
      if (j != i) {
        switched.insert(outlets[j] ^ mask);
      }
    }
    if (switched == other_devices) {
      int bits = 0;
      for (int j = 0; j < L; ++j) {
        if ((mask >> j) & 1) {
          ++bits;
        }
      }
      if (minSwitched > bits) {
        minSwitched = bits;
      }
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
    int result = MinSwitchesVeryFast(devices, outlets, L);
    cout << "Case #" << (test_index + 1) << ": ";
    if (result == -1) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }
  return 0;
}
