#include <limits.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>
#include <cassert>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <queue>
#include <iterator>
#include <set>
static const int INF = std::numeric_limits<int>::max();

int v[16][16];
int N;

bool check_all_del(int x, int mask, int parent)
{
  for(int i = 0; i < N; ++i) {
    if(i == parent || v[x][i] == 0) {
      continue;
    }

    if((mask & (1 << i)) == 0) {
      return false;
    }

    if(!check_all_del(i, mask, x)) {
      return false;
    }
  }

  return true;
}

bool check(int x, int mask, int parent)
{
  int numchild = 0;
  for(int i = 0; i < N; ++i) {
    if(i == parent || v[x][i] == 0) {
      continue;
    }

    if(mask & (1 << i)) {
      if(!check_all_del(i, mask, x)) {
        return false;
      }

      continue;
    }

    ++numchild;
  }

  if(numchild == 0) {
    return true;
  }

  if(numchild == 2) {
    for(int i = 0; i < N; ++i) {
      if(i == parent || v[x][i] == 0 || (mask & (1 << i))) {
        continue;
      }

      if(!check(i, mask, x)) {
        return false;
      }
    }
    return true;
  }

  return false;
}

int main()
{
  int T;

  std::cin >> T;
  for(int test = 1; test <= T; ++test) {
    std::cin >> N;

    memset(v, 0, sizeof(v));

    for(int i = 0; i < N - 1; ++i) {
      int X, Y;
      std::cin >> X >> Y;
      --X;
      --Y;

      v[X][Y] = v[Y][X] = 1;
    }

    int ans = INF;
    for(int mask = 0; mask < (1 << N); ++mask) {

      int i;
      int numdel = __builtin_popcount(mask);

      for(i = 0; i < N; ++i) {
        if(mask & (1 << i)) {
          continue;
        }
        if(check(i, mask, -1)) {
          break;
        }
      }

      if(i < N) {
        ans = std::min(ans, numdel);
      }
    }

    std::cout << "Case #" << test << ": " << ans << std::endl;
  }
}
