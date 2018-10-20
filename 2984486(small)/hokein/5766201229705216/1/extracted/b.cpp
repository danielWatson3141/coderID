#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 5005;
bool maze[N][N];
int n;

int nodes_count(int root, int parent) {
  vector<int> cnts;
  int max1 = -1;
  int max2 = -1;
  for (int i = 0; i < n; ++i) {
    if (i != parent && maze[root][i]) {
      cnts.push_back(nodes_count(i, root));
    }
  }
  if (cnts.size() >= 2) {
    sort(cnts.begin(), cnts.end());
    return 1+cnts[cnts.size()-1]+cnts[cnts.size()-2];
  } else {
    return 1;
  }
}

int main() {
  freopen("B-small.in", "r", stdin);
  freopen("B-small.out", "w", stdout);

  int T;
  int cases = 1;
  cin >> T;

  while (T--) {
    cin >> n;
    memset(maze, 0, sizeof(maze));
    int a, b;
    for (int i = 0; i < n-1; ++i) {
      cin >> a >> b;
      --a; --b;
      maze[a][b] = maze[b][a] = 1;
    }
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
      maxx = max(maxx, nodes_count(i, -1)) ;
    }
    cout << "Case #" << cases++ << ": " << n-maxx << endl;
  }
  return 0;
} 
