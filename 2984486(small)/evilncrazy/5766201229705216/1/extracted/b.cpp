#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, n) for (int i = 0; i < (n); i++)

#define N 1003

int numChildren[N];

std::vector<int> edges[N];

void countChildren(int n, int from)
{
  numChildren[n] = 0;
  REP(i, edges[n].size()) {
    if (edges[n][i] != from) {
      numChildren[n]++;
      countChildren(edges[n][i], n);
    }
  }
}

int prune(int n, int from)
{
  if (numChildren[n] == 1)
    return 1;

  if (numChildren[n] == 0)
    return 1;

  std::priority_queue<int> sizes;
  REP(i, edges[n].size()) {
    if (edges[n][i] != from) {
      sizes.push(prune(edges[n][i], n));
    }
  }

  int size = sizes.top();
  sizes.pop();

  return size + sizes.top() + 1;
}

int isComplete(int root)
{
  countChildren(root, -1);
  return prune(root, -1);
}

void docase(int tcase) {
  int n; scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    numChildren[i] = 0;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int a, b; scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int best = (1 << 30);
  for (int i = 1; i <= n; i++) {
    int size = isComplete(i);
    best = std::min(n - size, best);
  }

  printf("Case #%d: %d\n", tcase, best);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++) docase(i+1);
}
