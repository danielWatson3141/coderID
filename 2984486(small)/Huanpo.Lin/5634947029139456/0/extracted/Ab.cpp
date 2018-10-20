#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200, MAXL = 50;
char str[2][MAXN][MAXL];

int main()
{
    int TC, N, L;

    scanf("%d", &TC);

    for(int tc = 1; tc <= TC; tc++)
    {
        int theMin = 10000;
        scanf("%d %d", &N, &L);
        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < N; j++)
            {
                scanf("%s", str[i][j]);
            }

            
        int upper = (1<<L);
        for(int s = 0; s < upper; s++)    
        {
            bool used[MAXN];
            memset(used, 0, sizeof(used));
            bool pass = true;
            for(int i = 0; i < N; i++)
            {
                int cho = -1;
                for(int j = 0; j < N; j++)
                {
                    if(used[j]) continue;
                    bool mat = true;
                    for(int k = 0; k < L; k++)
                    {
                        int r[2];
                        r[0] = str[1][i][k]-'0';
                        if(s & (1<<k))
                            r[0] ^= 1;
                        r[1] = str[0][j][k]-'0';
                        if(r[0] != r[1])
                        {
                            mat = false;
                            break;
                        }
                    }
                    if(mat)
                    {
                        cho = j;
                        used[cho] = true;
                        break;
                    }
                }

                if(cho == -1)
                {
                    pass = false;
                    break;
                } 
            }
            
            if(pass)
            {
                int res = 0;
                for(int i = 0; i < L; i++)
                    if(s & (1<<i))
                        ++res;
                theMin = min(theMin, res);
            }
        }

        if(theMin == 10000) printf("Case #%d: NOT POSSIBLE\n", tc);
        else printf("Case #%d: %d\n", tc, theMin);
    }

    return 0;
}
