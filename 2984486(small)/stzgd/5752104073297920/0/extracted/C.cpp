#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using std::map;
using std::pair;
using std::string;
using std::vector;

int array[1011];
map<string, int> cnt;
vector<pair<int, int>> var;

void Work(int no) {
  cnt.clear();
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", array + i);
    cnt += array[i] > i;
    cnt -= array[i] < i;
  }
  if (cnt > 29)
    printf("Case #%d: BAD\n", no);
  else
    printf("Case #%d: GOOD\n", no);
  var.push_back({cnt, no});
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int i = 1; i <= cases; ++i) {
    Work(i);
  }
  /*
  std::sort(var.begin(), var.end());
  for (int i = 0; i < var.size(); ++i) {
    printf("%d %d\n", var[i].first, var[i].second);
  }
  */
  return 0;
}
