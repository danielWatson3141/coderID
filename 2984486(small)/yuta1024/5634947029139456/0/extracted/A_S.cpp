#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

const int INF = 1 << 30;

long long conv(string s) {
  long long cof = 1LL;
  long long ret = 0LL;
  for (int i = (int)s.size()-1; i >= 0; --i) {
    if (s[i] == '1') {
      ret += cof;
    }
    cof *= 2LL;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;

  for (int testcase = 1; testcase <= T; ++testcase) {
    int N, L;
    cin >> N >> L;

    vector<long long> outlets;
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      outlets.push_back(conv(s));
    }

    vector<long long> devices;
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      devices.push_back(conv(s));
    }

    int ans = INF;
    for (int S = 0; S < (1 << L); ++S) {
      for (int i = 0; i < N; ++i) {
        outlets[i] ^= S;
      }

      deque<bool> used(N, false);
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (used[j])
            continue;
          if (devices[i] == outlets[j]) {
            used[j] = true;
            break;
          }
        }
      }

      for (int i = 0; i < N; ++i) {
        outlets[i] ^= S;
      }

      if (count(used.begin(), used.end(), true) == N)
        ans = min(ans, __builtin_popcountll(S));
    }

    cout << "Case #" << testcase << ": ";
    if (ans == INF) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
