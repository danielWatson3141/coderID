#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>

#include <memory.h>
using namespace std;

#pragma comment(linker, ”/STACK:108777216“)

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  int res; scanf("%d", &res); return res;
}

class timer {
public:
  timer() : t_(clock()) {}
  void start() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

int visited[1024];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T; cin >> T;
  srand(time(0));
  for (int cs = 0; cs < T; ++cs) {
    int n; cin >> n; vector<int> vi(n); for(int i = 0; i < n; ++i) cin >> vi[i];
    memset(visited, 0, sizeof(visited));
    map<int, int> stats;
    int total = 0;
    for (int i = 0; i < 1000000; ++i) {
      vector< pair<int, int> > vv;
      for (int j = 0; j < 4; ++j) {
        int r = rand() % n;
        if (visited[r] == i) {
          break;
        } else {
          visited[r] = i;
          vv.push_back(make_pair(vi[r], j));
        }
      }
      if (vv.size() == 4) {
        sort(all(vv));
        ++total;
        int h = 0;
        for (int j = 0; j < 4; ++j) {
          h = 10 * h + vv[j].second;
        }
        stats[h]++;
      }
    }
    double error = 0.0;
    for (map<int, int>::iterator it = stats.begin(); it != stats.end(); ++it) {
      double e = 1.0 * it->second / total - 1.0 / 24;
      error += e * e;
    }
    //cout << error << endl;

    if (error <= 1E-6)
      printf("Case #%d: %s\n", cs + 1, "GOOD");
    else
      printf("Case #%d: %s\n", cs + 1, "BAD");
  }

  return 0;
}
