#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long getBin() {
  string s;
  cin >> s;
  long long v = 0;
  for (int i = 0; i < s.size(); i++) {
    v *= 2;
    v += s[i] - '0';
  }
  return v;
}

int main() {

  int T, CASE;
  cin >> T;
  for (CASE = 1; CASE <= T; CASE++) {
    int N, L;
    cin >> N >> L;

    vector<long long> outlet(N), need(N);
    for (int i = 0; i < N; i++)
      outlet[i] = getBin();
    for (int i = 0; i < N; i++)
      need[i] = getBin();

    vector<int> ocount(L), ncount(L), possible;
    map<long long, int> match;

    int res = 0;
    bool ok = false;
    int other_switch = N;

    for (int i = 0; i < L; i++) {
      // cout << ocount[i] << ' ' << ncount[i] << endl;
      for (int j = 0; j < N; j++) {
        ocount[i] += (outlet[j] & (1ll << i)) > 0;
        ncount[i] += (need[j] & (1ll << i)) > 0;
        // cout << ((outlet[j] & (1ll << i)) > 0) << ' ' << ((need[j] & (1ll << i)) > 0) << endl;
      }
      // cout << ocount[i] << ' ' << ncount[i] << endl;
      if (ocount[i] != ncount[i]) {
        if (ocount[i] + ncount[i] != N) {
          goto fail;
        } else {
          for (int j = 0; j < N; j++)
            outlet[j] ^= 1ll << i;
          res++;
        }
      } else {
        // possible flip?
        possible.push_back(i);
      }
    }

    for (int i = 0, total = 1 << possible.size(); i < total; i++) {
      vector<long long> ooutlet = outlet;
      int bits = 0;
      for (int j = 0; j < possible.size(); j++) {
        if ((1 << j) & i) {
          bits++;
          for (int k = 0; k < N; k++) {
            outlet[k] ^= 1ll << possible[j];
          }
        }
      }
      sort(outlet.begin(), outlet.end());
      sort(need.begin(), need.end());
      if (outlet == need) {
        ok = true;
        other_switch = min(other_switch, bits);
      }
      outlet = ooutlet;
    }

    if (!ok)
      goto fail;

    res += other_switch;

    printf("Case #%d: %d\n", CASE, res);
    continue;
fail:
    printf("Case #%d: NOT POSSIBLE\n", CASE);
  }

}
