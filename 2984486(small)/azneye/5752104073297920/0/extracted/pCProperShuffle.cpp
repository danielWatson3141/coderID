/*
 * 
 * File:   pCProperShuffle.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 25, 2014, 9:36:20 PM
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

namespace pCProperShuffle {

void solve(int test_num) {
  srand(time(NULL));
  //static int cnt[1111][1111]; //x appearing at position y
  //avg dev: good: 12900 , bad: 12538.5
  static int p[1111];
  ///const int N = 1000;
//  //memset(cnt, 0, sizeof(cnt));
//  double avg = 0;
//  for (int its = 0; its < 10000; its++) {
//    for (int i = 0; i < N; i++)
//      p[i] = i;
//    for (int i = 0; i < N; i++)
//      swap(p[i], p[rand() % (N - i) + i]);
//    //plnarr(p, p + N);
//    int dev = 0;
//    for (int i = 0; i < N; i++)
//      dev += (p[i] - i) * (p[i] - i);
//    avg += sqrt(dev);
//  }
//  pln(avg / 10000);
  //plnarr(cnt,N,N);
  int T, N;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      scanf("%d", p + i);
    double dev = 0;
    for (int i = 0; i < N; i++)
      dev += (p[i] - i) * (p[i] - i);
    dev = sqrt(dev);
    printf("Case #%d: ", t);
    if (dev > 12750)
      puts("GOOD");
    else
      puts("BAD");
  }
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("temp.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  solve(1);
}
}

int main() {
  pCProperShuffle::solve();
  return 0;
}
