#define PRETEST
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

#define INF 0x4f4f4f4f
#define FILL(a,b) memset(a,b,sizeof(a))
#define SQR(a) ((a) * (a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;

long long a[50];
long long b[50];

int main(int argc, char *argv[]) {
#ifdef PRETEST
  freopen("a.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  char s[50];

  scanf("%d", &T);
  for (int z = 1; z <= T; ++z) {
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      long long x = 0;
      for (int i = 1; i <= l; ++i) {
        x += ((s[i - 1] - '0') << (l - i));
      }
      b[i] = x;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      long long x = 0;
      for (int i = 1; i <= l; ++i) {
        x += ((s[i - 1] - '0') << (l - i));
      }
      a[i] = x;
    }
    bool flag = true;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        vector<long long> aa;
        vector<long long> bb;
        for (int k = 0; k < n; ++k) {
          aa.push_back(a[k]);
          bb.push_back(b[k]);
        }
        long long x = a[i] ^ b[j];
        int sum = 0;
        for (int k = 0; k < l; ++k) {
          if ((1 << k) & x) {
            for (int kk = 0; kk < n; ++kk) {
              bb[kk] ^= (1 << k);
            }
            ++sum;
          }
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        flag = true;
        for (int k = 0; k < n; ++k) {
          if (aa[k] != bb[k]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          ans = min(ans, sum);
        }
      }
    }
    printf("Case #%d: ", z);
    if (ans != INF) {
      printf("%d\n", ans);
    } else {
      printf("NOT POSSIBLE\n");
    }
  }
  return 0;
}
