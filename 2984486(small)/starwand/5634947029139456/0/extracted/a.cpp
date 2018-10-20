#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(a) (a).begin(), (a).end()

const int MAX_N = 160;
const int MAX_L = 50;

int N, L;
char IN[MAX_N][MAX_L];
char OUT[MAX_N][MAX_L];

void Input() {
  scanf("%d %d", &N, &L);
  char tmp;
  scanf("%c", &tmp);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < L; j++) {
      scanf("%c", &IN[i][j]);
    }
    scanf("%c", &tmp);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < L; j++) {
      scanf("%c", &OUT[i][j]);
    }
    scanf("%c", &tmp);
  }
}

void Reverse(int k) {
  for (int i = 0; i < N; i++) {
    IN[i][k] = (IN[i][k] == '1') ? '0' : '1';
  }
}

bool go(int subset) {
  for (int i = 0; i < L; i++) {
    if (subset & (1 << i)) Reverse(i);
  }

  bool ok = true;
  for (int i = 0; i < N; i++) {
    bool same_found = false;
    for (int j = 0; j < N; j++) {
      bool same = true;
      for (int k = 0; k < L; k++) {
        if (IN[j][k] != OUT[i][k]) {
          same = false;
          break;
        }
      }
      if (same) {
        same_found = true;
        break;
      }
    }
    if (!same_found) {
      ok = false;
      break;
    }
  }
  
  for (int i = 0; i < L; i++) {
    if (subset & 1 << i) Reverse(i);
  }
  return ok;
}

void Solve() {
  if (go(0)) {
    printf("0");
    return;
  }
  for (int i = 1; i < L; i++) {
    int s = (1 << i) - 1;
    while (!(s & 1 << L)) {
      if (go(s)) {
        printf("%d", i);
        return;
      }

      int lo = s & ~(s - 1);       // lowest one bit
      int lz = (s + lo) & ~s;      // lowest zero bit above lo
      s |= lz;                     // add lz to the set
      s &= ~(lz - 1);              // reset bits below lz
      s |= (lz / lo / 2) - 1;      // put back right number of bits at end
    }
  }
  printf("NOT POSSIBLE");
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
