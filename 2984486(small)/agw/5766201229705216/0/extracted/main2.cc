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


int count(int i) {
  int c = 1;

  for (int k = 1; k <= N; k ++)
    if (adj[i][k])
      if (! visit[k]) {
        visit[k] = true;

        c += count(k);
        
        visit[k] = false;
      }

  return c;
}

int dfs(int i) {
  std::vector<pii> a;

  for (int k = 1; k <= N; k ++)
    if (adj[i][k])
      if (! visit[k]) {
        visit[k] = true;

        a.emplace_back(k, count(k));

        visit[k] = false;
      }

  std::sort(ALL(a), [](const pii& a, const pii& b) {
      if (a.second > b.second)
        return true;

      return false;
    });


  int size = a.size();

  if (size == 0) {
    return 0;
  }
  else if (size == 1) {
    return a[0].second;
  }
  else {
    int c = 0;

    if (size != 2)
      for (int i = 2; i < size; i ++)
        c += a[i].second;

    for (int i = 0; i < 2; i ++) {
      int k = a[i].first;

      visit[k] = true;

      c += dfs(k);

      visit[k] = false;
    }
  
    return c;
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


    int cm = INF;

    for (int i = 1; i <= N; i ++) {
      memset(visit, 0, sizeof(visit));

      visit[i] = true;

      cm = std::min(dfs(i), cm);

      visit[i] = false;
    }

    std::cout << "Case #" << t << ": " << cm << std::endl;
  }

  return 0;
}
