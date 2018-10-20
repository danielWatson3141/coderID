#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long unsigned llu;

llu D[256], O[256], fO[256];
char s[64];

int popcount(llu x)
{
  int c = 0;
  for (; x > 0; x &= x-1) c++;
  return c;
}

int main()
{
  int n, l;
  int T, t = 1;
  int i, j, best;
  bool ok;
  llu f;

  for (scanf(" %d", &T); T; --T) {
    scanf(" %d%d", &n, &l);

    for (i = 0; i < n; ++i) {
      scanf(" %s", s);
      O[i] = 0;
      for (j = 0; j < l; ++j) {
        O[i] <<= 1;
        O[i] += s[j] - '0';
      }
    }

    for (i = 0; i < n; ++i) {
      scanf(" %s", s);
      D[i] = 0;
      for (j = 0; j < l; ++j) {
        D[i] <<= 1;
        D[i] += s[j] - '0';
      }
    }

    best = 100;
    sort(D, D + n);
    for (f = 0; f < (1u << l); ++f) {
      for (i = 0; i < n; ++i)
        fO[i] = O[i] ^ f;
      sort(fO, fO + n);
      ok = true;
      for (i = 0; i < n && ok; ++i)
        ok = ok && (fO[i] == D[i]);
      if (ok && popcount(f) < best)
        best = popcount(f);
    }

    printf("Case #%d: ", t++);
    if (best == 100)
      printf("NOT POSSIBLE\n");
    else
      printf("%d\n", best);
  }

  return 0;
}
