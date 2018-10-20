#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

void print_bin(ullong x, int l) {
  for (int i = 0; i < l; ++i) {
    printf("%llu", ((x >> i) & 1));
  }
  printf(" ");
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  ullong arr[160];
  ullong arr2[160];
  ullong dev[160];
  bool taken[160];
  char str[1024];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(arr, 0, sizeof(arr));
    memset(dev, 0, sizeof(dev));
    memset(taken, 0, sizeof(taken));
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      for (int j = 0; j < l; ++j) {
        arr[i] |= ((ullong)(str[j] == '1') << j);
      }
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      for (int j = 0; j < l; ++j) {
        dev[i] |= ((ullong)(str[j] == '1') << j);
      }
    }

    // match arr[0] to some dev[i]
    int best_switches = 1 << 30;
    for (int i = 0; i < n; ++i) {
      ullong delta = arr[0] ^ dev[i];
      int n_switches = __builtin_popcountll(delta);

      // now try to match every other arr[j]
      int n_match = 0;
      for (int j = 0; j < n; ++j) {
        if (j==i) continue;
        arr2[n_match++] = dev[j] ^ delta;
      }
      sort(arr+1,arr+n);
      sort(arr2, arr2+(n-1));

      bool ok = true;
      for (int i = 0; i < n-1; ++i) {
        if (arr[i+1] != arr2[i]) {
          ok = false;
          break;
        }
      }
      if (ok) best_switches = min(n_switches, best_switches);
    }
    printf("Case #%d: ", ctr+1);
    if (best_switches == 1 << 30) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", best_switches);
    }
  }
  return 0;
}
