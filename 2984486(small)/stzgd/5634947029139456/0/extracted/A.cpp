#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

vector<long long> origin, target, now;
char buffer[55];
int n, len;

int BitCount(long long x) {
  int ret = 0;
  for (int i = 0; i < len; ++i) {
    ret += (x >> i) & 1;
  }
  return ret;
}

void Init() {
  origin.clear();
  target.clear();
  scanf("%d%d", &n, &len);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", buffer);
    int tmp = 0;
    for (int j = 0; j < len; ++j) {
      if (buffer[j] == '1') {
        tmp |= (1ll << j);
      }
    }
    origin.push_back(tmp);
  }
  for (int i = 0; i < n; ++i) {
    scanf(" %s", buffer);
    int tmp = 0;
    for (int j = 0; j < len; ++j) {
      if (buffer[j] == '1') {
        tmp |= (1ll << j);
      }
    }
    target.push_back(tmp);
  }
  std::sort(target.begin(), target.end());
}

void Work() {
  int ans = 1000;
  for (int p = 0; p < n; ++p) {
    now.clear();
    int xor_v = origin[p] ^ target[0];
    for (int i = 0; i < n; ++i) {
      now.push_back(origin[i] ^ xor_v);
    }
    std::sort(now.begin(), now.end());
    if (now == target) {
      ans = std::min(ans, BitCount(xor_v));
    }
  }
  if (ans == 1000)
    puts("NOT POSSIBLE");
  else
    printf("%d\n", ans);
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Init();
    Work();
  }
  return 0;
}
