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


        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            {
                int flip[MAXL];
                memset(flip, 0, sizeof(flip));
                int res = 0;
                bool pass = true;

                for(int k = 0; k < L; k++)
                {
                    if(str[0][i][k] != str[1][j][k])
                    {
                        ++res;
                        flip[k] = 1;
                    }
                } 
                
                bool used[MAXN];
                memset(used, 0, sizeof(used));

                for(int k = 0; k < N; k++)
                {
                    int cho = -1;
                    for(int m = 0; m < N; m++)
                        if(used[m] == false)
                        {
                            bool mat = true;
                            for(int l = 0; l < L; l++)
                            {
                                int r[2];
                                r[0] = str[0][m][l]-'0';
                                r[1] = ( (str[1][k][l]-'0') );
                                r[1] ^= flip[l];
                                if( r[0] != r[1])
                                {
                                    mat = false;
                                    break;
                                }
                            }        
                            if(mat)
                            {
                                mat = true;
                                cho = m;
                                used[ m ] = true;
                                break;
                            } 
                        }

                    if(cho == -1)
                    {
                        pass = false;
                        break;
                    }
                }
                if(pass) theMin = min(theMin, res);
            }

        if(theMin != 10000) printf("Case #%d: %d\n", tc, theMin);
        else printf("Case #%d: NOT POSSIBLE\n", tc);
    }

    return 0;
}
