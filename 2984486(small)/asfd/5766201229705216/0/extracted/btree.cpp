#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


pair<int, int> dfs(int x, vector<vector<int> > nodes, int parent);

int main(int argc, char* argv[]) {
  int t, n;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    vector<int> children;
    vector<vector<int> > nodes(n + 5, children);
    for (int j = 0; j < n - 1; j++) {
      int x, y;
      scanf("%d %d", &x, &y);
      nodes[x].push_back(y);
      nodes[y].push_back(x);
    }
    int minimum = n;
    for (int j = 1; j <= n; j++) {
      pair<int, int> result = dfs(j, nodes, j);
      if (result.second < minimum) {
	minimum = result.second;
      }
    }
    printf("Case #%d: %d\n", i, minimum);
  }
  return 0;
}

// pair< number of nodes to keep, number of nodes to delete >
pair<int,int> dfs(int x, vector<vector<int> > nodes, int parent) {
  int to_keep = 0, to_delete = 0;
  priority_queue<pair<int, int> , vector<pair<int, int> >, less<pair<int, int> > > pq;
  for (vector<int>::iterator iter = nodes[x].begin();
       iter != nodes[x].end(); iter++) {
    if (*iter != parent) {
      pair<int, int> result = dfs(*iter, nodes, x);
      pq.push(result);
    }
  }
  if (pq.size() >= 2) {
    for(int i = 0; i < 2; i++) {
      pair<int, int> lol = pq.top();
      pq.pop();
      to_keep += lol.first;
      to_delete += lol.second;
    }
  }
  while(!pq.empty()) {
    pair<int, int> lol = pq.top();
    pq.pop();
    to_delete += lol.first + lol.second;
  }
  return pair<int, int>(to_keep + 1, to_delete);
}
