#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define debug(x) cerr << #x << "=" << x << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int maxlen = 45;
const int maxn = 160;
const int inf = 1e9;

int n;
int len;
int64 outlets[maxn];
int64 devices[maxn];
int64 newoutlets[maxn];

void read(int64 *a) {
  for (int i = 0; i < n; ++i) {
    char s[maxlen];
    scanf("%s", s);
    a[i] = 0;
    for (int j = 0; j < len; ++j)
      if (s[j] == '1') a[i] += int64(1) << j;
    for (int j = 0; j < len; ++j)
      assert(((a[i] >> j & 1) + '0') == s[j]);
  }
}

bool possible(int64 mask) {
  for (int i = 0; i < n; ++i) {
    newoutlets[i] = outlets[i] ^ mask;
  }
  sort(newoutlets, newoutlets + n);
  for (int i = 0; i < n; ++i)
    if (newoutlets[i] != devices[i])
      return false;
  return true;
}

void solve(int testcase) {
  debug(testcase);
  printf("Case #%d: ", testcase);
  scanf("%d %d", &n, &len);
  read(outlets);
  read(devices);
  sort(devices, devices + n);
  int res = inf;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int64 mask = 0;
      for (int k = 0; k < len; ++k)
        if ((outlets[i] >> k & 1) != (devices[j] >> k & 1))
          mask += int64(1) << k;
      if (possible(mask)) {
        res = min(res, __builtin_popcountll(mask));
      }
    }
  if (res == inf)
    puts("NOT POSSIBLE");
  else
    printf("%d\n", res);
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
