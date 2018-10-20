#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

const int maxn = 205;
const int maxl = 50;

LL device[maxn], flow[maxn];
int n, m;

LL getnum(char *str) {
  LL res = 0;
  for (int i = 0; i < m; ++ i) res = res * 2 + (str[i] - '0');
  return res;
}

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    char str[maxl];
    scanf("%s", str);
    device[i] = getnum(str);
  }
  for (int i = 0; i < n; ++ i) {
    char str[maxl];
    scanf("%s", str);
    flow[i] = getnum(str);
  }
}

int count(LL mask) {
  int res;
  for (res = 0; mask; mask /= 2) res += (mask & 1);
  return res;
}

void work(int cas) {
  int ans = -1;
  LL tmp[maxn];
  std::sort(device, device + n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      LL mask = flow[i] ^ device[j];
      for (int h = 0; h < n; ++ h) tmp[h] = flow[h] ^ mask;
      std::sort(tmp, tmp + n);
      int flag = 1;
      for (int h = 0; h < n && flag; ++ h) flag &= (tmp[h] == device[h]);
      if (!flag) continue;
      if (ans == -1 || ans > count(mask)) ans = count(mask);
    }
  }
  printf("Case #%d: ", cas);
  if (ans == -1) printf("NOT POSSIBLE\n");
  else printf("%d\n", ans);
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int t = 1; t <= cas; ++ t) {
    init();
    work(t);
  }
  return 0;
}
