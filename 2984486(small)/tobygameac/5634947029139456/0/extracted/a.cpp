#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int ans;
vector<string> source;
vector<string> target;

void solve(int now, int use) {
  if (use >= ans) {
    return;
  }
  if (now == L) {
    sort(source.begin(), source.end());
    for (int i = 0; i < N; i++) {
      if (source[i] != target[i]) {
        return;
      }
    }
    ans = min(ans, use);
    return;
  }
  solve(now + 1, use);
  for (int i = 0; i < N; i++) {
    source[i][now] = (source[i][now] == '1') ? '0' : '1';
  }
  solve(now + 1, use + 1);
  for (int i = 0; i < N; i++) {
    source[i][now] = (source[i][now] == '1') ? '0' : '1';
  }
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    source.clear();
    target.clear();
    printf("Case #%d: ", C++);
    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; i++) {
      char s[99];
      scanf("%s", s);
      source.push_back(s);
    }
    for (int i = 0; i < N; i++) {
      char s[99];
      scanf("%s", s);
      target.push_back(s);
    }
    sort(target.begin(), target.end());
    ans = 2e9;
    solve(0, 0);
    if (ans == 2e9) {
      puts("NOT POSSIBLE");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
