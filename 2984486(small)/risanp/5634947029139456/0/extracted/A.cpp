#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <unordered_map>

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define oo 1000111000

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

#define MAXS 40
#define MAXN 150

char s[MAXS + 5];
LL outlet[MAXN + 5];
LL device[MAXN + 5];
int N, L;

LL A;

map<LL, bool> MAP;

bool check() {
  for (int i = 0; i < N; i++) {
    if (!MAP[outlet[i] ^ A]) {
      return false;
    }
  }
  return true;
}

int countOne(LL x) {
  int ret = 0;
  while (x) {
    x -= x & -x;
    ret++;
  }
  return ret;
}

int main() {
  int tc = 0, nTC;
  scanf("%d", &nTC);

  while (++tc && nTC--) {
    scanf("%d%d", &N, &L);
    MAP.clear();
    for (int i = 0; i < N; i++) {
      scanf("%s", s);
      outlet[i] = 0;
      for (int j = 0; j < L; j++) {
        outlet[i] <<= 1;
        outlet[i] |= (s[j] - '0');
      }
    }
    for (int i = 0; i < N; i++) {
      scanf("%s", s);
      device[i] = 0;
      for (int j = 0; j < L; j++) {
        device[i] <<= 1;
        device[i] |= (s[j] - '0');
      }
      MAP[device[i]] = true;
    }

    int ret = oo;
    for (int i = 0; i < N; i++) {
      int numOne = 0;
      A = outlet[0] ^ device[i];
      if (check()) {
        ret = min(ret, countOne(A));
      }
    }
    printf("Case #%d: ", tc);
    if (ret == oo) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ret);
    }
  }
  return 0;
}

