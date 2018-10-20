#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

AdjList adj;
int counts[1024];
int dfs2(int v, int p) {
  int cnt = 0;
  FOR_EDGE(adj, v, it) {
    int o = *it;
    if (o == p) continue;
    cnt += dfs2(o, v);
  }
  return (counts[v] = cnt + 1);
}
int dfs(int v, int p) {
  pair<int,int> scores[1024];
  int n_child = 0;
  int n_child2 = 0;
  FOR_EDGE(adj, v, it) {
    int o = *it;
    if (o == p) continue;
    n_child2++;
  }
  if (n_child2 <= 1) {
    // forced to make leaf
#ifdef DEBUG
    printf("MUST LEAF %d: %d\n", v, counts[v] - 1);
#endif
    return counts[v] - 1;
  }
  FOR_EDGE(adj, v, it) {
    int o = *it;
    if (o == p) continue;
    scores[n_child].first = dfs(o, v);
    scores[n_child].second = o;
    n_child++;
#ifdef DEBUG
    printf("SCORE FOR %d: %d: %d\n", v, o, scores[n_child-1].first);
#endif
  }
#ifdef DEBUG
  printf("> PRE-SCORES for %d: ", v);
  for (int i = 0; i < n_child; ++i) {
    printf("%d ", scores[i].first);
  }
  puts("");
#endif
  int sum = 0;
  for (int i = 0; i < n_child; ++i) {
    sum += counts[scores[i].second];
    scores[i].first -= counts[scores[i].second];
  }
  sort(scores, scores+n_child);
#ifdef DEBUG
  printf("> POST-SCORES for %d: ", v);
  for (int i = 0; i < n_child; ++i) {
    printf("%d ", scores[i].first);
  }
  puts("");
#endif
  int internal = sum + scores[0].first + scores[1].first;
  int leaf = counts[v] - 1;
  if (n_child > 0 && internal <= leaf) {
#ifdef DEBUG
    printf("INTERNAL %d: (%d, %d)\n", v, internal, leaf);
#endif
    return internal;
  } else {
#ifdef DEBUG
    printf("LEAF %d: (%d, %d)\n", v, internal, leaf);
#endif
    return leaf;
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);


  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int n;
    scanf("%d", &n);
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n-1; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      --a; --b;
      adj[a].push_back(b);
      adj[b].push_back(a);

    }

    int best = 1 << 30;
    for (int i = 0; i < n; ++i) {
      memset(counts, 0, sizeof(counts));
#ifdef DEBUG
      puts("");
      printf("ROOTING %d\n", i);
#endif
      dfs2(i, -1);
#ifdef DEBUG
      for (int j = 0; j < n; ++j) {
        printf("%d ", counts[j]);
      }
      puts("");
#endif
      int score = dfs(i, -1);
#ifdef DEBUG
      printf("MY SCORE: %d\n", score);
#endif
      best = min(score, best);
    }

    printf("Case #%d: %d\n", ctr+1, best);
  }

  return 0;
}
