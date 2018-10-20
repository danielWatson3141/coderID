#include <cstdio>
using namespace std;

const int MAXN = 1010;
double e[2][MAXN];
int a[MAXN];

inline double mysqr(double k) {return k * k;}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    int n;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++i)
      scanf("%d", &a[i]);

    int sum = 0;
    for (int i = 0 ; i < n ; ++i) {
      e[0][i] = i;
      sum += i;
    }
    double avg = (double)sum / n;
    int from = 0, to = 1;
    for (int i = 0 ; i < n ; ++i) {
      for (int j = 0 ; j < n ; ++j) {
        if (j != i) e[to][j] = e[from][j] * (n-1) / n + e[from][i] / n;
        else e[to][j] = avg;
      }
      from = 1 - from;
      to = 1 - to;
    }

    double d1 = .0, d2 = .0;
    for (int i = 0 ; i < n ; ++i) {
      d1 += mysqr(avg - a[i]);
      d2 += mysqr(e[from][i] - a[i]);
    }

    printf("Case #%d: ", ca);
    if (d1 < d2) printf("GOOD\n");
    else printf("BAD\n");
  }
  return 0;
}

