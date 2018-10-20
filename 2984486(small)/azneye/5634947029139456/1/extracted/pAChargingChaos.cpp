/*
 * 
 * File:   pAChargingChaos.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 25, 2014, 9:05:35 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

namespace pAChargingChaos {

void solve(int test_num) {
  static int N, L, flip[44];
  string str[155], need[155], a[155], b[155];
  cin >> N >> L;
  for (int i = 0; i < N; i++)
    cin >> str[i];
  for (int i = 0; i < N; i++)
    cin >> need[i];
  int res = 1337;
  for (int fst = 0; fst < N; fst++) {
    for (int i = 0; i < L; i++)
      flip[i] = str[0][i] != need[fst][i];
    int M = 0;
    for (int i = 1; i < N; i++) {
      a[M] = str[i];
      for (int j = 0; j < L; j++) {
        if (flip[j])
          a[M][j] = '1' - a[M][j] + '0';
      }
      M++;
    }
    //plnarr(a,a+M);
    M = 0;
    for (int i = 0; i < N; i++)
      if (i != fst)
        b[M++] = need[i];
    sort(a, a + M);
    sort(b, b + M);
    if (equal(a, a + M, b))
      res = min(res, count(flip, flip + L, 1));
  }
  printf("Case #%d: ", test_num);
  if (res > 1000)
    puts("NOT POSSIBLE");
  else
    printf("%d\n", res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pAChargingChaos::solve();
  return 0;
}
