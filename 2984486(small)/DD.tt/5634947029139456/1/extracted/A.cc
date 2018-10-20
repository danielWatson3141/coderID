#include<cstdio>
#include<string>
#include<set>
#include<cstring>
using namespace std;

const int INF = 1000000000;

int T, N, L;
char s[155][55], t[155][55];
char ss[155][55];

int calc(int x) {
  memset(ss, 0, sizeof(ss));
  int ret = 0;
  set<string> A, B;
  for (int i = 0; i < L; ++i) {
    if (s[0][i] != t[x][i]) {
      ++ret;
      for (int j = 0; j < N; ++j) {
        ss[j][i] = '1' + '0' - s[j][i];
      }
    } else {
      for (int j = 0; j < N; ++j) {
        ss[j][i] = s[j][i];
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    A.insert(ss[i]);
    B.insert(t[i]);
  }
  return A == B ? ret : INF;
}

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A.out", "w", stdout);
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    scanf("%d%d", &N, &L);
    int ans = INF;
    for (int i = 0; i < N; ++i) {
      scanf("%s", &s[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%s", &t[i]);
    }
    for (int i = 0; i < N; ++i) {
      ans = min(ans, calc(i));
    }
    printf("Case #%d: ", test);
    if (ans == INF) {
      puts("NOT POSSIBLE");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}

