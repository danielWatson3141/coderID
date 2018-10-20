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
#define PROBLEM_ID "B"

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

int GetBestCount(int v, int p, const vvi& G, map<pii, int>& cache) {
  if (cache.find(MP(v, p)) != cache.end()) {
    return cache[MP(v, p)];
  }
  int& res = cache[MP(v, p)];
  res = 1;
  if (G[v].size() < 3) {
    return res;
  }
  vector<int> best_counts;
  for (int i = 0; i < G[v].size(); ++i) {
    int other = G[v][i];
    if (other == p) {
      continue;
    }
    best_counts.push_back(GetBestCount(other, v, G, cache));
  }
  sort(best_counts.begin(), best_counts.end());
  return res = best_counts[best_counts.size() - 2] + best_counts.back() + 1;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vvi G(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    map<pii, int> cache;
    int result = n - 1;
    for (int root = 0; root < n; ++root) {
      if (G[root].size() < 2) {
        continue;
      }
      vi best_counts;
      for (int i = 0; i < G[root].size(); ++i) {
        int other = G[root][i];
        best_counts.push_back(GetBestCount(other, root, G, cache));
      }
      sort(best_counts.begin(), best_counts.end());
      int best_count = best_counts[best_counts.size() - 2] + best_counts.back() + 1;
      result = min(result, n - best_count);
    }
    cout << "Case #" << (test_index + 1) << ": " << result << endl;
  }
  return 0;
}
