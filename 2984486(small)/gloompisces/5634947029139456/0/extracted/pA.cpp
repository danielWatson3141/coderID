#include <stdio.h>
#include <string.h>

char A[155][45];
char B[155][45];
char tmps[45];
bool xxor[155];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int N, L;
    
    int cases;
    scanf("%d", &cases);
    
    for(int index = 1; index <= cases; index++)
    {
        scanf("%d %d", &N, &L);
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", &A[i]);
        }
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", &B[i]);
        }
        
        int ans = 1000000;
        for (int i = 1; i <= N; i++)  // 1 to i
        {
            int tmp = 0;
            for (int j = 0; j < L; j++)
            {
                if (A[1][j] == B[i][j])
                {
                    xxor[j] = 0;
                }
                else
                {
                    xxor[j] = 1;
                    tmp++;
                }
            }
            
            for (int k = 2; k <= N; k++)
            {
                for (int j = 0; j < L; j++)
                {
                    if (xxor[j] == 0)
                    {
                        tmps[j] = A[k][j];
                    }
                    else
                    {
                        tmps[j] = 97 - A[k][j];
                    }
                }
                tmps[L] = '\0';
                
                for (int c = 1; c <= N; c++)
                {
                    if (strcmp(tmps, B[c]) == 0)
                    {
                        goto next;
                    }
                }
                goto end;
                next:;
            }
            
            if (tmp < ans)
            {
                ans = tmp;
            }
            
            end:;
        }
        
        if (ans == 1000000)
        {
            printf("Case #%d: NOT POSSIBLE\n", index);
        }
        else
        {
            printf("Case #%d: %d\n", index, ans);
        }
    }
    
    return 0;
}
