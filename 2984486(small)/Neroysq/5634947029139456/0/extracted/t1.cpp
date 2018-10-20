#include <cstdio>
#include <cstring>
const int nmax = 10 + 18;

int n, l, ans;
char outlet[nmax][nmax], device[nmax][nmax];
bool ed[nmax];
char str[nmax];

void search(int k, int m)
{
  if (m >= ans) return;
  if (k > l) {
    // printf("m:%d\n", m);
    bool find = 1;
    for (int i = 1; i <= n; ++i) {
      bool suc = 0;
      for (int j = 1; j <= n; ++j) {
	bool suc2 = 1;
	for (int k = 1; k <= l; ++k)
	  if (!((!ed[k] && device[i][k] == outlet[j][k]) || (ed[k] && device[i][k] != outlet[j][k]))) {
	    suc2 = 0;
	    break;
	  }
	// printf("s1:%s s2:%s\n", outlet[j] + 1, device[i] + 1);
	if (suc2) {
	  suc = 1;
	  break;
	}
      }
      if (!suc) {
	find = 0;
	break;
      }
    }
    if (find) {
      if (ans > m)
	ans = m;
    }
    // printf("%d\n", find);
    return;
  }
  ed[k] = 0;
  search(k + 1, m);
  ed[k] = 1;
  search(k + 1, m + 1);
}

int main()
{
  int t;
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
  scanf("%d", &t);
  for (int cases = 1; cases <= t; ++cases) {
    printf("Case #%d: ", cases);
    scanf("%d%d", &n, &l);
    ans = l + 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", str + 1);
      for (int j = 1; j <= l; ++j)
	outlet[i][j] = str[j];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%s", str + 1);
      for (int j = 1; j <= l; ++j)
	device[i][j] = str[j];
    }
    search(1, 0);
    if (ans > l)
      printf("NOT POSSIBLE");
    else
      printf("%d", ans);
    if (t > cases) printf("\n");
  }
  return 0;
}
