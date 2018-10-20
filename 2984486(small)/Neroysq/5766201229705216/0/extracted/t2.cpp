#include <cstdio>
#include <cstring>
const int nmax = 1000 + 18, emax = nmax * 2;

int n, deg[nmax];
int fst[nmax], pnt[emax], nxt[emax], tot;
int ans;

void add(int s, int t)
{
  pnt[++tot] = t, nxt[tot] = fst[s], fst[s] = tot;
  ++deg[s];
}

int dfs(int k, int fa)
{
  int key = deg[k] - (fa > 0);
  // printf("%d:%d\n", k, key);
  if (key == 0)
    return 1;
  if (key == 1)
    return 1;
  if (key == 2) {
    int sum = 1;
    for (int i = fst[k]; i; i = nxt[i])
      if (pnt[i] != fa)
	sum += dfs(pnt[i], k);
    // printf("sum(%d):%d\n", k, sum);
    return sum;
  }
  if (key >= 3) {
    int a = 0, b = 0, tmp;
    for (int i = fst[k]; i; i = nxt[i])
      if (pnt[i] != fa) {
	tmp = dfs(pnt[i], k);
	if (tmp >= a)
	  b = a, a = tmp;
	else if (tmp > b)
	  b = tmp;
      }
    // printf("sum(%d):%d\n", k, a + b + 1);
    return a + b + 1;
  }
}

void update(int k)
{
  // printf("%dand%d", ans, k);
  if (ans > k) ans = k;
}

int main()
{
  int t;
  freopen("input2.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  scanf("%d", &t);
  for (int cases = 1; cases <= t; ++cases) {
    memset(deg, 0, sizeof(deg));
    memset(fst, 0, sizeof(fst));
    tot = 0;
    printf("Case #%d: ", cases);
    scanf("%d", &n);
    ans = n;
    for (int i = 1; i < n; ++i) {
      int s, t;
      scanf("%d%d", &s, &t);
      add(s, t), add(t, s);
    }
    for (int i = 1; i <= n; ++i) {
      // printf("i:%d(%d) ", i, deg[i]);
      update(n - dfs(i, 0));
      // printf("ans:%d\n", ans);
    }
    printf("%d", ans);
    if (cases < t) printf("\n");
  }
  return 0;
}
