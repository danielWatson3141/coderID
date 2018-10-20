#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 1024
int G[MAX][MAX], foi[MAX], nos[MAX], N;

int custo(int root)
{
  vector<int> filho;
  int home = 0;
  int soma = 0;

  foi[root] = 1;
  for(int i = 0; i < N; i++)
    if (!foi[i] && G[root][i])
    {
      soma += nos[i];
      filho.push_back(i);
    }

  int n = (int)filho.size();
  if (n == 0) return home;
  if (n == 1) return nos[filho[0]];
  if (n == 2) return (custo(filho[0])+custo(filho[1]));

  vector<int> c(n);
  for(int i = 0; i < n; i++)
    c[i] = custo(filho[i]);

  home = soma;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      home = min(home, (soma-nos[filho[i]]-nos[filho[j]])+c[i]+c[j]);

  return home;
}

void calcula(int root)
{
  foi[root] = 1;
  nos[root] = 1;
  for(int i = 0; i < N; i++)
    if (!foi[i] && G[root][i])
    {
      calcula(i);
      nos[root] += nos[i];
    }
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
    for(int i = 0; i < N; i++)
    {
      memset(foi, 0, sizeof(foi));
      memset(nos, -1, sizeof(nos));
      calcula(i);
      memset(foi, 0, sizeof(foi));

      r = min(r, custo(i));
    }

    printf("Case #%d: %d\n", caso, r);
  }
}
