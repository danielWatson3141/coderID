#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int s1[20], s2[20],s3[20];

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T, n, L;
    scanf("%d", &T);
    for(int cas = 1 ; cas <= T ; cas++)
    {
        scanf("%d%d", &n, &L);
        getchar();
        for(int i = 0 ; i < n ; i++)
        {
            s1[i] = 0;
            char ch;
            scanf("%c", &ch);
            while(ch != ' ' && ch != '\n')
            {
                s1[i] <<= 1;
                s1[i] += ch - '0';
                scanf("%c", &ch);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            s2[i] = 0;
            char ch;
            scanf("%c", &ch);
            while(ch != ' ' && ch != '\n')
            {
                s2[i] <<= 1;
                s2[i] += ch - '0';
                scanf("%c", &ch);
            }
        }

        sort(s2, s2 + n);

        int tot = (1<<L);
        int ans = 1000;
        for(int i = 0 ; i < tot ; i++)
        {
            int now = 0;

            for(int k = 0 ; k < n ; k++)
                s3[k] = s1[k];

            for(int j = 0 ; j < L ; j++)
            if((i>>j)&1)
            {
                for(int k = 0 ; k < n ; k++)
                    s3[k] ^= (1<<j);
                now++;
            }

            sort(s3, s3 + n);

            for(int k = 0 ; k < n ; k++)
            if(s2[k] == s3[k])
            {
                if(k == n - 1)ans = min(ans, now);
            }
            else break;
        }
        printf("Case #%d: ", cas);
        if(ans == 1000)puts("NOT POSSIBLE");
        else           printf("%d\n", ans);
    }


    return 0;
}
