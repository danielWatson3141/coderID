#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
int n, l;
string st[161], ed[161], now[161];
int d[51];
int main() {
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ca) {
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; ++i)
      cin >> st[i];
    for (int i = 1; i <= n; ++i)
      cin >> ed[i];
    sort(ed + 1, ed + n + 1);
    int res = l + 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < l; ++j) {
        if (st[1][j] != ed[i][j]) d[j] = 1;
        else d[j] = 0;
      }
      for (int j = 1; j <= n; ++j) {
        now[j] = "";
        for (int k = 0; k < l; ++k)
          if (d[k]) now[j] += (1 - (st[j][k] - '0')) + '0';
          else now[j] += st[j][k];
      }
      sort(now + 1, now + n + 1);
      bool flag = true;
      for (int j = 1; j <= n; ++j)
        if (now[j] != ed[j]) {
          flag = false;
          break;
        }
      if (flag) {
        int cnt = 0;
        for (int j = 0; j < l; ++j)
          cnt += d[j];
        if (cnt < res) res = cnt;
      }
    }
    if (res > l) {
      printf("Case #%d: NOT POSSIBLE\n", ca);
    } else {
      printf("Case #%d: %d\n", ca, res);
    }
  }
  return 0;
}
