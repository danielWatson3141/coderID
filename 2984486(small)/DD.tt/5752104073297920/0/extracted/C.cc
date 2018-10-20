#include<cstdio>

int T, N, x;

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C.out", "w", stdout);
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int ret = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &x);
      if (x < i) {
        ++ret;
      }
    }
    printf("Case #%d: %s\n", test, ret < 490 ? "BAD" : "GOOD");
  }
  return 0;
}

