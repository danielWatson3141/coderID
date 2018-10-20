#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int T, N, L;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    scanf("%d %d", &N, &L);
    vector<string> outlet, device, novo(N);
    char s[256];

    for(int i = 0; i < N; i++)
    {
      scanf("%s", s);
      outlet.push_back(string(s));
    }
    for(int i = 0; i < N; i++)
    {
      scanf("%s", s);
      device.push_back(string(s));
    }

    int r = -1;

    for(int i = 0; i < (1<<L); i++)
    {
      int t = 0;
      novo = outlet;

      for(int j = 0; j < L; j++)
        if ((i&(1<<j)) != 0)
        {
          for(int k = 0; k < N; k++)
            novo[k][j] = (novo[k][j] == '0') ? '1' : '0';
          t++;
        }

      int ok = 1;
      vector<int> f(N, 0);
      for(int j = 0; j < N && ok; j++)
      {
        ok = 0;
        for(int k = 0; k < N && !ok; k++)
          if (!f[k] && device[j] == novo[k])
          {
            ok = 1;
            f[k] = 1;
          }
      }

      if (ok) r = (r < 0) ? t : min(r, t);
    }

    printf("Case #%d: ", caso);
    if (r == -1) printf("NOT POSSIBLE\n");
    else printf("%d\n", r);
  }
}
