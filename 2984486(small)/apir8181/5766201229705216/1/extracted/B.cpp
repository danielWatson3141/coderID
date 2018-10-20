#include <stdio.h>
#include <string.h>
#include <vector>

#define MAXN 1001

using std::vector;

vector<int> edges[MAXN];
int n;
int chdNum[MAXN];
bool visited[MAXN];

void init_input() {
  scanf("%d", &n);
  for (int i = 0; i < MAXN; ++ i) edges[i].clear();
  for (int i = 0; i < n - 1; ++ i) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

int cal_chdNum(int root) {
  visited[root] = true;
  int count = 1;
  for (int i = 0, size = edges[root].size(); i < size; ++ i) {
    int idx = edges[root][i];
    if (!visited[idx]) {
      count += cal_chdNum(idx);
    }
  }
  return chdNum[root] = count;
}

int cal_tree(int root) {
  visited[root] = true;

  int chdCount = 0;
  for (int i = 0, size = edges[root].size(); i < size; ++ i) {
    int idx = edges[root][i];
    if (!visited[idx]) {
      ++ chdCount;
    }
  }

  if (chdCount == 0) return 0;
  else if (chdCount == 1) return chdNum[root] - 1;
  else if (chdCount == 2) {
    int ret = 0;
    for (int i = 0, size = edges[root].size(); i < size; ++ i) {
      int idx = edges[root][i];
      if (!visited[idx]) ret += cal_tree(idx);
    }
    return ret;
  } else {
    bool temp[MAXN];
    int min = MAXN;

    for (int i = 0, size = edges[root].size();
         i < size; ++ i) {

      memcpy(temp, visited, MAXN);
      int idx1 = edges[root][i];
      if (visited[idx1]) continue;

      int ret1 = cal_tree(idx1);

      for (int j = i + 1; j < size; ++ j) {
        int idx2 = edges[root][j];
        if (visited[idx2]) continue;

        int ret2 = cal_tree(idx2);
        int val = ret1 + ret2 + \
          chdNum[root] - chdNum[idx1] - chdNum[idx2] - 1;
        min = min < val ? min : val;
      }
      memcpy(visited, temp, MAXN);
      return min;
    }

  }
}

int solve() {
  int min = MAXN;
  for (int i = 1; i <= n; ++ i) {
    memset(visited, 0, sizeof(visited));
    memset(chdNum, 0, sizeof(chdNum));
    cal_chdNum(i);
    memset(visited, 0, sizeof(visited));

    int val = cal_tree(i);
    min = min < val ? min : val;
  }
  return min;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++ i) {
    init_input();
    printf("Case #%d: %d\n", i, solve());
  }
  return 0;
}
