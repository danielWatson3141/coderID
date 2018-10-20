#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <utility>
#include <algorithm>

using std::cin;
using std::vector;

int n;
vector<vector<int> > e;
using std::pair;
using std::cout;
using std::cin;

pair<int, int> solve(int x, int p) {
  vector<int> discounts;
  int children = 0;
  for(int c : e[x])
    if(c != p) {
      pair<int, int> cur = solve(c, x);
      children += cur.second;
      discounts.push_back(cur.second - cur.first);
    }
  std::sort(discounts.begin(), discounts.end(), std::greater<int>());
  int best = children;
  if(discounts.size() >= 2)
    best = children - discounts[0] - discounts[1];
  //std::cerr << "solve(" << x << ", " << p << "): " << best << ' ' << children + 1 << '\n';
  return std::make_pair(best, children + 1);
}

int main() {
  int T;
  cin >> T;
  for(int tcase=1;tcase<=T;tcase++) {
    cin >> n;
    e.resize(0);
    e.resize(n);
    for(int i=0;i<n-1;i++) {
      int x, y;
      cin >> x >> y;
      e[x-1].push_back(y-1);
      e[y-1].push_back(x-1);
    }
    int best = n;
    for(int i=0;i<n;i++)
      best = std::min(best, solve(i, -1).first);
    cout << "Case #" << tcase << ": " << best << '\n';
  }
}
