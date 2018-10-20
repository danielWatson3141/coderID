#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int l;

int apps[150][40];
int circuit[150][40];
int sig[40];

int genSig(int cid) {
  int count = 0;
  for (int i = 0; i < l; i++) {
    sig[i] = apps[0][i] ^ circuit[cid][i];
    if (sig[i] == 1) count++;
  }
  return count;
}

int match(int aid) {
  for (int cid = 0; cid < n; cid++) {
    int matched = 1;
    for (int i = 0; i < l; i++) {
      matched = matched && ((sig[i] ^ circuit[cid][i]) == apps[aid][i]);
      if (!matched) break;
    }
    if (matched) return 1;
  }
  return 0;
}

void init() {
  scanf("%d%d", &n, &l);
  int i;
  for (i = 0; i < n; i++) {
    char tmp[100];
    scanf("%s", tmp);
    for (int j = 0; j < l; j++) {
      if (tmp[j] == '0') {
        circuit[i][j] = 0;
      } else {
        circuit[i][j] = 1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    char tmp[100];
    scanf("%s", tmp);
    for (int j = 0; j < l; j++) {
      if (tmp[j] == '0') {
        apps[i][j] = 0;
      } else {
        apps[i][j] = 1;
      }
    }
  }
}

int main () {
  int t;
  scanf("%d", &t);
  for (int i = 1; i < t + 1; i++) {
    init();
    int bestC = 999;
    for (int m = 0; m < n; m++) {
      int th = genSig(m);
      int ma = 1;
      for (int j = 1; j < n; j++) {
        ma = ma && match(j);
        if (!ma) break;
      }
      if (ma) {
        bestC = min(bestC, th);
      }
    }
    if (bestC == 999) {
      printf("Case #%d: NOT POSSIBLE\n", i);
    } else {
      printf("Case #%d: %d\n", i, bestC);
    }
  }
}
