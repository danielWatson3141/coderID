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
  int perm[160];
  char str[1024];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(arr, 0, sizeof(arr));
    memset(dev, 0, sizeof(dev));
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
    for (int i = 0; i < n; ++i) {
      perm[i] = i;
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
      print_bin(arr[i], l);
    }
    puts("");
    for (int i = 0; i < n; ++i) {
      print_bin(dev[i], l);
    }
    puts("");
    puts("");
#endif
    int best_switches = 1 << 30;
    do {
      int n_switches = 0;
      for (int i = 0; i < n; ++i) {
        int ix = perm[i];
        arr2[i] = (arr[ix] ^ dev[i]);
      }
#ifdef DEBUG
      for (int i = 0; i < n; ++i) {
        print_bin(arr2[i], l);
      }
      puts("");
#endif
      bool ok = true;
      for (int i = 0; i < l; ++i) {
        bool good = true;
        bool par = (arr2[0] >> i) & 1;
        //bool par = arr2[0] & (1ULL << i);
        for (int j = 1; j < n; ++j) {
          //if (!(arr2[j] & par)) {
          if (((arr2[j] >> i) & 1) ^ par) {
            good = false;
            break;
          }
        }
        if (!good) {
          ok = false;
          break;
        } else {
          n_switches += (par>0);
        }
      }
      if (ok) {
        best_switches = min(best_switches, n_switches);
      }
    } while (next_permutation(perm, perm+n));
    printf("Case #%d: ", ctr+1);
    if (best_switches == 1 << 30) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", best_switches);
    }
  }
  return 0;
}
