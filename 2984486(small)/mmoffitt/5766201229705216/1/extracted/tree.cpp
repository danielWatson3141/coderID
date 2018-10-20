#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int N;
vector<vector<int> > v;
vector<int> x, y;

int expand(int prev, int r) {
  multiset<int> keep;
  for (int i = 0;i < v[r].size();i++) {
    if (v[r][i] != prev) keep.insert(-expand(r, v[r][i]));
  }
  int ret = 1;
  if (keep.size() > 1)  {
    ret += -*keep.begin();
    keep.erase(keep.begin());
    ret += -*keep.begin();
  }
  return ret;
}

int solve() {
  int val = 0;
  for (int r = 0;r < N;r++) {
    int res = expand(-1, r);
    if (val < res) val = res;
  }
  return N - val;
}

int main(int argc, char* argv[]) {
  int T;
  std::cin >> T;
  for (int t = 0;t < T;t++) {
    cin >> N;
    x.clear();
    y.clear();
    v.clear();
    v.resize(N);
    for (int i = 0;i < N - 1;i++) { int _x, _y;
      std::cin >> _x; _x--; x.push_back(_x);
      std::cin >> _y; _y--; y.push_back(_y);
      v[_x].push_back(_y);
      v[_y].push_back(_x);
    }
    int cost = solve();
    std::cout << "Case #" << (t + 1) << ": " << cost << std::endl;
  }
  return 0;
}

