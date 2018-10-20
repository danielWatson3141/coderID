#include <stdio.h>
#include <string.h>
#include <math.h>

double prob[1005][1005];
double prob2[1005][1005];

void pre()
{
    int N = 1000;
    memset(prob, 0, sizeof(prob));
    for (int i = 1; i <= N; i++)
    {
        prob[i][i] = 1;
    }
    
    for(int i = 1; i <= N; i++)
    {
        memset(prob2, 0, sizeof(prob2));
        for (int p = 1; p <= N; p++)  // num p
        {
            for (int q = 1; q <= N; q++) // q-th place
            {
                if (i == q)
                {
                    prob2[p][q] = 1.0 / N;
                }
                else
                {
                    prob2[p][q] = 1.0 / N * prob[p][i] + (1.0 - 1.0 / N) * prob[p][q];
                }
            }
        }
        for (int p = 1; p <= N; p++)
        {
            for (int q = 1; q <= N; q++)
            {
                prob[p][q] = prob2[p][q];
            }
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    
    pre();
    
    int cases, NN;
    scanf("%d", &cases);
    
    for(int index = 1; index <= cases; index++)
    {
        scanf("%d", &NN);
        double uniform = log(1.0 / NN) * NN;
        double test = 0;
        for (int j = 1; j <= NN; j++)
        {
            int num;
            scanf("%d", &num);
            num++;
            
            test += log(prob[num][j]);
        }
        
        if (test < uniform) printf("Case #%d: GOOD\n", index);
        else printf("Case #%d: BAD\n", index);
    }
}
