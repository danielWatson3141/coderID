#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int n, l;
vector<string> initial, goal;
unordered_set<string> mod;

char change(char c) {
  if (c == '0') return '1';
  return '0';
}

string modify(string s, int mask) {
  string ret = s;
  for (int i = 0; i < l; i++) if ((1<<i) & mask) ret[i] = change(ret[i]);
  return ret;
}

int ones(int mask) {
  int ret = 0;
  for (int i = 0; i < l; i++) if ((1<<i) & mask) ret++;
  return ret;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n >> l;
    initial.clear(); goal.clear();
    for (int i = 0; i < n; i++) { string s; cin >> s; initial.push_back(s); }
    for (int i = 0; i < n; i++) { string s; cin >> s; goal.push_back(s); }

    int best = -1;
    for (int mask = 0; mask < (1<<l); mask++) {
      mod.clear();
      for (int i = 0; i < n; i++) mod.insert(modify(initial[i], mask));
      bool all = true;
      for (int i = 0; i < n; i++) if (mod.count(goal[i]) == 0) all = false;
      if (all) { if (best == -1) best = ones(mask); else best = min(best, ones(mask)); }
    }

    if (best > -1) cout << "Case #" << t << ": " << best << "\n";
    else cout << "Case #" << t << ": NOT POSSIBLE\n";
  }
}
