#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef int Edge;

struct Graph {
  vector<vector<Edge> > nbr;
  int num_nodes;
  Graph(int n) : nbr(n), num_nodes(n) { }
  
  void add_edge(int u, int v) {
    Edge e1 = v;   nbr[u].push_back(e1);
    Edge e2 = u;   nbr[v].push_back(e2);
  }
};

typedef pair<int,int> pii;
int N;

// f[p][v] = min nodes to delete to make v a root of binary tree with parent p
int f[1000][1000];

// size[p][v] = subtree size rooted at v, parent p
int size[1000][1000];

void comp(int parent, int root, const Graph &G)
{
  if (f[parent][root] >= 0) return;

  int num_child = G.nbr[root].size();
  size[parent][root] = 1;
  if (num_child-1 == 0) {
    f[parent][root] = 0;
    return;
  }

  vector<pii> rec;
  for (int i = 0; i < num_child; i++) {
    int child = G.nbr[root][i];
    if (child == parent) continue;
    comp(root, child, G);
    size[parent][root] += size[root][child];
    rec.push_back(make_pair(size[root][child] - f[root][child], i));
  }

  sort(rec.begin(), rec.end());

  if (num_child-1 == 1) {
    // delete the whole subtree
    int child = G.nbr[root][rec[0].second];
    f[parent][root] = size[root][child];
    return;
  }

  // pick the last two to keep
  int ans = 0;
  for (int i = 0; i < num_child-3; i++) {
    ans += size[root][G.nbr[root][rec[i].second]];
  }
  ans += f[root][G.nbr[root][rec[num_child-3].second]];
  ans += f[root][G.nbr[root][rec[num_child-2].second]];
  f[parent][root] = ans;
}


int solve(int root, const Graph &G)
{
  int num_child = G.nbr[root].size();
  if (num_child == 0) {
    return 0;
  }

  pii rec[1000];
  for (int i = 0; i < num_child; i++) {
    int child = G.nbr[root][i];
    comp(root, child, G);
    rec[i] = make_pair(size[root][child] - f[root][child], i);
  }

  sort(rec, rec+num_child);

  if (num_child == 1) {
    // delete the whole subtree
    return size[root][G.nbr[root][0]];
  }

  // pick the last two to keep
  int ans = 0;
  for (int i = 0; i < num_child-2; i++) {
    ans += size[root][G.nbr[root][rec[i].second]];
  }
  ans += f[root][G.nbr[root][rec[num_child-2].second]];
  ans += f[root][G.nbr[root][rec[num_child-1].second]];
  return ans;
}

void solve()
{
  cin >> N;

  Graph G(N);
  for (int i = 0; i < N-1; i++) {
    int X, Y;
    cin >> X >> Y;
    G.add_edge(X-1, Y-1);
  }

  for (int i = 0; i < N; i++) {
    fill(f[i], f[i]+N, -1);
  }

  int ans = N+1;
  for (int root = 0; root < N; root++) {
    ans = min(ans, solve(root, G));
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
