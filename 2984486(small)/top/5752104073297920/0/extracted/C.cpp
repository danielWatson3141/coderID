#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 1e3+10,rd = 10010;

int n,x[N];
int a[rd][N];

inline bool solve () {
  scanf ("%d", &n);
  for (int i = 0;i < n;i ++) {
    scanf ("%d", &x[i]);
  }

  int cnt = 0;
  for (int i = 0;i < rd;i ++) {
    int cnt2 = 0;
    for (int j = 0;j < n;j ++) {
      if (a[i][j] == x[j]) {
	cnt2 ++;
      }
    }
    if (cnt2 >= 5) {
      cnt ++;
    }
  }
  return (cnt < 40);
}

int main () {
  srand (time (NULL));
  for (int round = 0;round < rd;round ++) {
    for (int i = 0;i < 1000;i ++) {
      a[round][i] = i;
    }
    for (int i = 0;i < 1000;i ++) {
      int p = rand ()%1000;
      swap (a[round][i], a[round][p]);
    }
  }

  int t;
  scanf ("%d", &t);
  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: %s\n", i, solve () ? "GOOD": "BAD");
  }
}
