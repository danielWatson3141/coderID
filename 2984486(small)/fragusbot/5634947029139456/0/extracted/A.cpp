#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

int n;
int L;
bool used[155];
string have[155];
string need[155];

int main() {
  freopen("in", "r", stdin); freopen("out", "w", stdout); freopen("log", "w", stderr);
  int tt; scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    scanf("%d %d", &n, &L);
    for (int i = 0; i < n; ++i) cin >> have[i];
    for (int i = 0; i < n; ++i) cin >> need[i];
    int ans = 0;
    bool good = true;
    for (int bit = 0; bit < L; ++bit) {
      int have_z = 0, need_z = 0;
      for (int i = 0; i < n; ++i) {
        if (have[i][bit] == '0') ++have_z;
        if (need[i][bit] == '0') ++need_z;
      }
      if (need_z == have_z) {
        
      } else if (need_z == n - have_z) {
        for (int i = 0; i < n; ++i) have[i][bit] = have[i][bit] == '0' ? '1' : '0';
        ++ans;
      } else good = false;
    }
    printf("Case #%d: ", cc);
    if (!good) puts("NOT POSSIBLE"); else {
      for (int i = 0; i < n; ++i) used[i] = false;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (!used[j]) {
            if (need[i] == have[j]) {
              used[j] = true; break;
            }
          }
        }
      }
      for (int i = 0; i < n; ++i)
        if (!used[i]) good = false;
      if (!good) puts("NOT POSSIBLE"); else printf("%d\n", ans);
    }
  }
  return 0;
}