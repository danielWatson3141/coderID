#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(a) (a).begin(), (a).end()

int test_case;

const int MAX_N = 1010;
const int ROOT = MAX_N - 1;

struct Edge {
  int to;
  int rev;
};

int N;
vector<Edge> G[MAX_N];
int dp[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];

void AddEdge(int from, int to) {
  G[from].push_back(Edge{to, (int)G[to].size()});
  G[to].push_back(Edge{from, (int)G[from].size() - 1});
}

void Input() {
  for (int i = 0; i < MAX_N; i++) {
    G[i].clear();
  }

  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    AddEdge(from - 1, to - 1);
  }
}

int DeleteCost(int parent, int v) {
  if (dp2[parent][v] != -1) {
    return dp2[parent][v];
  }

  int &res = dp2[parent][v];
  res = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i].to == parent) continue;

    res += DeleteCost(v, G[v][i].to);
  }
  return res;
}

int MakeBinaryTree(int parent, int v) {
  if (dp[parent][v] != -1) {
    return dp[parent][v];
  }

  int edgeCount = G[v].size();
  int& res = dp[parent][v];

  if (edgeCount == 0) {
    exit(1);
  } else if (edgeCount == 1) {
    if (parent == ROOT) {
      // root: remove others
      res = DeleteCost(v, G[v][0].to);
    } else {
      // leaf node: already binary tree
      res = 0;
    }
  } else if (edgeCount == 2) {
    if (parent == ROOT) {
      // cost = make child binary tree
      res = 0;
      for (int i = 0; i < G[v].size(); i++) {
        res += MakeBinaryTree(v, G[v][i].to);
      }
    } else {
      // make leaf node
      int del = (G[v][0].to == parent) ? G[v][1].to : G[v][0].to;
      res = DeleteCost(v, del);
    }
  } else {
    res = MAX_N;
    for (int a = 0; a < G[v].size(); a++) {
      if (G[v][a].to == parent) continue;
      for (int b = a + 1; b < G[v].size(); b++) {
        if (G[v][b].to == parent) continue;
        int cost = 0;
        cost += MakeBinaryTree(v, G[v][a].to);
        cost += MakeBinaryTree(v, G[v][b].to);
        for (int del = 0; del < G[v].size(); del++) {
          if (del == a || del == b) continue;
          if (G[v][del].to == parent) continue;

          cost += DeleteCost(v, G[v][del].to);
        }
        res = min(res, cost);
      }
    }
  }
  //  cerr << test_case << " root " << v << " parent " << parent << " cost " << res << endl;
  return res;
}

void Solve() {
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  int res = MAX_N;
  for (int i = 0; i < N; i++) {
    int t = MakeBinaryTree(ROOT, i);
    //    cerr << test_case << " " << i << " " << t << endl;
    res = min(res, t);
  }
  printf("%d", res);
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
