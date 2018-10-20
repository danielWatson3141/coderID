#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int llint;

llint convert(const string& s, int len) {
  llint ans = 0;
  for (int i = 0; i < len; i++) {
    ans = ans * 2 + (s[i] - '0');
  }
  return ans;
}

struct Smartphone{
  Smartphone(int outlets_, int len_, const vector<llint>& initial_,
             const vector<llint>& goal_)
      : outlets(outlets_), len(len_), initial(initial_), goal(goal_) {

  }

  int search() {
    queue<pair<vector<llint>, int>> next;
    set<vector<llint>> visited;
    next.push(make_pair(initial, 0));
    visited.insert(initial);
    if (initial == goal) return 0;
    while (!next.empty()) {
      auto current = next.front();
      next.pop();
      for (int i = 0; i < len; i++) {
        llint mask = 1 << i;
        auto neigh = current.first;
        for (int j = 0; j < int(neigh.size()); j++) {
          neigh[j] ^= mask;
        }
        sort(neigh.begin(), neigh.end());
        if (neigh == goal) {
          return current.second + 1;
        }
        if (visited.find(neigh) != visited.end()) {
          continue;
        }
        visited.insert(neigh);
        next.push(make_pair(neigh, current.second + 1));
      }
    }
    return -1;
  }

  int outlets, len;
  const vector<llint>& initial;
  const vector<llint>& goal;
};

int main() {
  int tot;
  cin >> tot;
  for (int t = 1; t <= tot; t++) {
    int outlets, len;
    cin >> outlets >> len;
    vector<llint> initial(outlets);
    string temp;
    for (int i = 0; i < outlets; i++) {
      cin >> temp;
      initial[i] = convert(temp, len);
    }
    vector<llint> goal(outlets);
    for (int i = 0; i < outlets; i++) {
      cin >> temp;
      goal[i] = convert(temp, len);
    }
    sort(initial.begin(), initial.end());
    sort(goal.begin(), goal.end());
    Smartphone s(outlets, len, initial, goal);
    int ans = s.search();
    cout << "Case #" << t << ": ";
    if (ans >= 0) {
      cout << ans << "\n";
    } else {
      cout << "NOT POSSIBLE\n";
    }
  }
  return 0;
}
