#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 1024
int G[MAX][MAX], foi[MAX], N, M;

int pode(int mask, int root)
{
  vector<int> filho;

  foi[root] = 1;

  for(int i = 0; i < N; i++)
    if ((mask&(1<<i)) == 0 && !foi[i] && G[root][i])
      filho.push_back(i);

  if (filho.size() == 0)
    return 1;

  if (filho.size() == 2)
    return (pode(mask, filho[0]) && pode(mask, filho[1]));

  return 0;
}

void dfs(int mask, int root)
{
  M++;
  foi[root] = 1;
  for(int i = 0; i < N; i++)
    if ((mask&(1<<i)) == 0 && !foi[i] && G[root][i])
      dfs(mask, i);
}

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    memset(G, 0, sizeof(G));
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++)
    {
      int u,v;
      scanf("%d %d", &u, &v);
      G[u-1][v-1] = G[v-1][u-1] = 1;
    }

    int r = N;
    for(int i = 0; i < (1<<N); i++)
    {
      int t = 0;
      for(int j = 0; j < N; j++)
        if ((i&(1<<j)) != 0)
          t++;
      memset(foi, 0, sizeof(foi));
      M = 0;
      for(int j = 0; j < N; j++)
        if ((i&(1<<j)) == 0)
        {
          dfs(i, j);
          break;
        }

      if (N == M+t)
        for(int root = 0; root < N; root++)
          if ((i&(1<<root)) == 0)
          {
            memset(foi, 0, sizeof(foi));
            if (pode(i, root))
            {
              r = min(r, t);
              break;
            }
          }
    }
    printf("Case #%d: %d\n", caso, r);
  }
}
