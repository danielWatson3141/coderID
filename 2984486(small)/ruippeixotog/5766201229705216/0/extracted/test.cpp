#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 16
#define INF 1e8

using namespace std;

int n;

vector<int> adjs[MAXN];
bool deleted[MAXN];

void validDfs(int* counts, int parent, int k) {
  int numAdjs = 0;
  for(int i = 0; i < (int) adjs[k].size(); i++) {
    int adj = adjs[k][i];
    if(deleted[adj]) continue;
    numAdjs++;
    if(adj != parent) validDfs(counts, k, adj);
  }
  counts[min(numAdjs, 4)]++;
}

bool valid(int tip, int numDeleted) {
  if(tip == -1) return false;

  int counts[5];
  memset(counts, 0, sizeof(counts));

  validDfs(counts, -1, tip);

  if(counts[4] > 0) return false;
  int total = counts[0] + counts[1] + counts[2] + counts[3];
  if(n != total + numDeleted) return false;
  return counts[0] == 1 || counts[2] == 1;
}

int dfs(int k, int tip, int numDeleted) {
  if(k == n) {
    return valid(tip, numDeleted) ? numDeleted : INF;
  }

  int best = dfs(k + 1, k, numDeleted);
  deleted[k] = true;
  best = min(best, dfs(k + 1, tip, numDeleted + 1));
  deleted[k] = false;

  return best;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n;
    // cerr << " --- #" << tc << " ---" << endl; 
    // cerr << n << endl;

    for(int i = 0; i < n; i++)
      adjs[i].clear();

    for(int i = 0; i < n - 1; i++) {
      int a, b; cin >> a >> b;
      // cerr << a << " " << b << endl;
      adjs[--a].push_back(--b);
      adjs[b].push_back(a);
    }

    int res = dfs(0, -1, 0);
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
