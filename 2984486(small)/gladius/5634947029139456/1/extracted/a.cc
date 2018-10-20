#include <cstdio>
#include <stdint.h>
#include <string>
#include <cstring>
#include <algorithm>

int N, L;
int64_t power[200], device[200];
bool used[200];

void read(int64_t* dest) {
  for (int i = 0; i < N; ++i) {
    char ary[250];
    scanf("%s", ary);
    std::string s(ary);
    dest[i] = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '1') {
        dest[i] |= 1ULL << j;
      }
    }
  }
}

std::string build(int64_t f) {
  std::string r;
  for (int i = 0; i < L; ++i)
    r += ((f >> i) & 1) ? "1" : "0";
  return r;
}

int doit(int at, int64_t flipped) {
  if (at == N) {
    /*
    for (int i = 0; i < N; ++i)
      printf("%s ", build(device[i]).c_str());
    printf("\n"); 
    for (int i = 0; i < N; ++i)
      printf("%s ", build(power[i] ^ flipped).c_str());
    printf("\n");
    */
    return __builtin_popcountll(flipped);
  }
  int best = 500;
  for (int i = 0; i < N; ++i) {
    if (used[i]) continue;
    int64_t toggle = device[at] ^ (power[i] ^ flipped);
    if (toggle & flipped) continue;

    used[i] = true;
    best = std::min(best, doit(at + 1, flipped | toggle));
    used[i] = false;
  }
  return best;
}

void prob(int probNum) {
  scanf("%d %d", &N, &L);
  read(power);
  read(device);
  memset(used, 0, sizeof(used));
  std::sort(&device[0], &device[N]);
  
  int result = doit(0, 0);
  printf("Case #%d: ", probNum);
  if (result == 500)
    printf("NOT POSSIBLE\n");
  else
    printf("%d\n", result);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    prob(i+1);
  }
  return 0;
}
