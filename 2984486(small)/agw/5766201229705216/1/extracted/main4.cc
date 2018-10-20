#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


typedef std::pair<int, int> pii;


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int N, adj[1111][1111], visit[1111];

int cmemo[1111][1111], dmemo[1111][1111];


int count(int i, int j) {
  if (cmemo[i][j] >= 0)
    return cmemo[i][j];


  int c = 1;

  for (int k = 1; k <= N; k ++)
    if (adj[j][k])
      if (! visit[k]) {
        visit[k] = true;

        c += count(j, k);
        
        visit[k] = false;
      }

  return cmemo[i][j] = c;
}


int dfs(int i, int j) {
  if (dmemo[i][j] >= 0)
    return dmemo[i][j];


  std::vector<pii> a;

  for (int k = 1; k <= N; k ++)
    if (adj[j][k])
      if (! visit[k]) {
        visit[k] = true;

        a.emplace_back(k, count(j, k));

        visit[k] = false;
      }


  std::sort(ALL(a), [](const pii& a, const pii& b) {
      if (a.second > b.second)
        return true;

      return false;
    });

  int size = a.size();

  if (size == 0) {
    return dmemo[i][j] = 0;
  }
  else if (size == 1) {
    return dmemo[i][j] = a[0].second;
  }
  else {
    int c = 0;

    if (size != 2)
      for (int i = 2; i < size; i ++)
        c += a[i].second;

    for (int i = 0; i < 2; i ++) {
      int k = a[i].first;

      visit[k] = true;

      c += dfs(j, k);

      visit[k] = false;
    }
  
    return dmemo[i][j] = c;
  }
}

int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, x, y;
  
  std::cin >> T;
  
  for (int t = 1; t <= T; t ++) {
    memset(adj, 0, sizeof(adj));

    std::cin >> N;

    for (int i = 0; i < N - 1; i ++) {
      std::cin >> x >> y;

      adj[x][y] = adj[y][x] = true;
    }


    memset(cmemo, -1, sizeof(cmemo));
    memset(dmemo, -1, sizeof(dmemo));


    int cm = INF;

    for (int i = 1; i <= N; i ++) {
      memset(visit, 0, sizeof(visit));

      visit[i] = true;

      int c = dfs(0, i);

#if 0
      std::cerr << "t=" << t << " i=" << i << " c=" << c << std::endl;
#endif

      cm = std::min(c, cm);

      visit[i] = false;
    }

#if 1
    std::cerr << "t=" << t << " cm=" << cm << std::endl;
#endif

    std::cout << "Case #" << t << ": " << cm << std::endl;
  }

  return 0;
}
