#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<string>& initial, const vector<string>& goal)
{
  const int N = initial.size(), L = initial[0].size();

  int ans = 10000;
  for (unsigned s = 0; s < (1U<<L); s++) {
    vector<string> v(initial);
    int c = 0;
    for (int i = 0; i < L; i++) {
      if (s & (1<<i)) {
        ++c;
        for (int j = 0; j < N; j++) {
          if (v[j][i] == '0') {
            v[j][i] = '1';
          } else {
            v[j][i] = '0';
          }
        }
      }
    }
    sort(v.begin(), v.end());
    if (v == goal) {
      ans = min(ans, c);
    }
  }

  if (ans > L) {
    throw "NOT POSSIBLE";
  } else {
    return ans;
  }
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
    for (int i = 0; i < N; i++) {
      cin >> goal[i];
    }
    sort(goal.begin(), goal.end());

    cout << "Case #" << Ti << ": ";
    try {
      cout << solve(initial, goal) << endl;
    } catch (const char *msg) {
      cout << msg << endl;
    }
  }
  return 0;
}
