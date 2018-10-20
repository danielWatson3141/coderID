#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static const int INF = 10000000;

int solve(vector<string>& initial, const vector<string>& goal)
{
  const int N = initial.size(), L = initial[0].size();
  int ans = INF;

  for (int i = 0; i < N; i++) {
    vector<int> pos;
    for (int j = 0; j < L; j++) {
      if (initial[0][j] != goal[i][j]) {
        pos.push_back(j);
        for (int k = 0; k < N; k++) {
          if (initial[k][j] == '0') {
            initial[k][j] = '1';
          } else {
            initial[k][j] = '0';
          }
        }
      }
    }
    vector<string> v(initial);
    sort(v.begin(), v.end());
    if (v == goal) {
      ans = min(ans, (int)(pos.size()));
    }
    for (vector<int>::const_iterator it = pos.begin(); it != pos.end(); ++it) {
      const int j = *it;
      for (int k = 0; k < N; k++) {
        if (initial[k][j] == '0') {
          initial[k][j] = '1';
        } else {
          initial[k][j] = '0';
        }
      }
    }
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;

  for (int Ti = 1; Ti <= T; Ti++) {
    int N, L;
    cin >> N >> L;
    vector<string> initial(N), goal(N);
    for (int i = 0; i < N; i++) {
      cin >> initial[i];
    }
    sort(initial.begin(), initial.end());
    for (int i = 0; i < N; i++) {
      cin >> goal[i];
    }
    sort(goal.begin(), goal.end());

    cout << "Case #" << Ti << ": ";
    const int ans = solve(initial, goal);
    if (ans == INF) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << solve(initial, goal) << endl;
    }
  }
  return 0;
}
