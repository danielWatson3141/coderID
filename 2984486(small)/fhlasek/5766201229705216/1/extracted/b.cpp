/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111
vector<int> graph[MAXN];
int N;

int dfs(int v, int f) {
  vector<int> childern;
  REP(i, graph[v].size()) if (graph[v][i] != f) childern.push_back(dfs(graph[v][i], v));
  sort(childern.begin(), childern.end());
  if (childern.size() < 2) return 1;
  return 1 + childern[childern.size() - 1] + childern[childern.size() - 2];
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1);
    scanf("%d", &N);
    REP(i, N + 1) graph[i].clear();
    REP(i, N - 1) {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int best = 0;
    REP(i, N) best = max(best, dfs(i, -1));
    printf("%d\n", N - best);
  }

  return 0;
}
