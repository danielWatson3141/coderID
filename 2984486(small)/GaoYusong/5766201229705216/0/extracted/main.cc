#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[1100];
int N;

inline
bool cmp(pair<int, int> a, pair<int, int> b)
{
  return (a.first - a.second) < (b.first - b.second);
}

pair<int, int> dfs(int s, int fa)
{
  vector<pair<int, int> > child;
  int nodes = 1;
  for (int i = 0; i < G[s].size(); i++) {
    int t = G[s][i];
    if (t != fa) {
      pair<int, int> ret = dfs(t, s);
      child.push_back(ret);
      nodes += ret.second;
    }
  }
  if (0 == child.size()) {
    return make_pair(0, nodes);
  } else if (1 == child.size()) {
    return make_pair(child[0].second, nodes);
  } else {

    sort(child.begin(), child.end(), cmp);
    
    return make_pair(child[0].first - child[0].second + child[1].first - child[1].second + nodes - 1, nodes);
  }
}

int main()
{
  int T;

  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-small-attempt1.out", "w", stdout);

  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      G[i].clear();
    }

    for (int i = 0; i < N - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }

    int ans = N;
    for (int i = 1; i <= N; i++) {
      pair<int, int> ret = dfs(i, 0);
      //printf("i %d ret %d %d\n", i, ret.first, ret.second);
      ans = min(ans, ret.first);
    }

    printf("Case #%d: %d\n", cn, ans);
    
  }
  return 0;
}
