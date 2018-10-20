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
    vector<string> outlet, device;
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
    for(int j = 0; j < N; j++)
    {
      vector<int> f(L, 0);
      int t = 0;
      for(int k = 0; k < L; k++)
        if (device[0][k] != outlet[j][k])
        {
          t++;
          f[k] = 1;
        }

      vector<int> foi(N, 0);
      foi[j] = 1;

      int ok = 1;
      for(int i = 1; i < N && ok; i++)
      {
        ok = 0;
        for(int z = 0; z < N && !ok; z++)
          if (!foi[z])
          {
            ok = 1;
            for(int k = 0; k < L && ok; k++)
              if (f[k] && device[i][k] == outlet[z][k]) ok = 0;
              else if (!f[k] && device[i][k] != outlet[z][k]) ok = 0;

            if (ok) foi[z] = 1;
          }
      }
      if (ok) r = (r < 0) ? t : min(r, t);
    }


    printf("Case #%d: ", caso);
    if (r == -1) printf("NOT POSSIBLE\n");
    else printf("%d\n", r);
  }
}
