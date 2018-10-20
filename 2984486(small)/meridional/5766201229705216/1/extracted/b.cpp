#include <vector>
#include <queue>
using namespace std;

vector<int> g[1001];
int n;
void init() {
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
}

// dfs return the number of nodes remained
int dfs(int p, int i) {
  if (g[i].size() == 1) {
    // leaf
    return 1;
  }
  vector<int>::iterator iter = g[i].begin();
  priority_queue<int> q;
  for (; iter != g[i].end(); iter++) {
    if (*iter == p) continue;
    q.push(dfs(i, *iter));
  }
  if (q.size() < 2) {
    return 1;
  }
  int r = q.top();
  q.pop();
  r += q.top();
  return r + 1;
};

int main () {
  int t;
  scanf("%d", &t);
  int r;
  for (int i = 1; i <= t; i++) {
    init();
    r = 0;
    for (int j = 1; j <= n; j++) {
      r = max(r, dfs(0, j));
    }
    printf("Case #%d: %d\n", i, n - r);
  }
}
