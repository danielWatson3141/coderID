#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int n;
vector<vector<int> > edges;
vector<vector<int> > tree;

int best[2000];

void treedp(int curr) {
  if (tree[curr].size() < 2) {
    best[curr] = 1;
    return;
  }

  vector<int> choices;
  for (int i = 0; i < tree[curr].size(); ++i) {
    int child = tree[curr][i];
    treedp(child);
    choices.push_back(best[child]);
  }
  sort(choices.begin(), choices.end());
  
  best[curr] = 1 + choices[choices.size()-1] +
                   choices[choices.size()-2];
}

int tryroot(int root) {
  tree.clear(); tree.resize(n);
  stack<int> s;
  bool explored[2000];
  memset(explored, 0, sizeof(explored));

  s.push(root);
  explored[root] = true;
  while (!s.empty()) {
    int curr = s.top(); s.pop();
    for (int i = 0; i < edges[curr].size(); ++i) {
      int next = edges[curr][i];
      if (!explored[next]) {
        explored[next] = true;
        s.push(next);
        tree[curr].push_back(next);
      }
    }
  }
  
  treedp(root);

  return n-best[root];
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cin >> n;

    edges.clear(); edges.resize(n);
    for (int i = 0; i < n-1; ++i) {
      int a, b; cin >> a >> b; a--; b--;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    int best = n-1;
    for (int i = 0; i < n; ++i) {
      best = min(best, tryroot(i));
    }

    cout << "Case #" << test << ": ";
    cout << best << endl;
  }
  return 0;
}