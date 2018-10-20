#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

long long s1[200], s2[200], s3[200];

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
            s1[i] = 0LL;
            char ch;
            scanf("%c", &ch);
            while(ch != ' ' && ch != '\n')
            {
                s1[i] <<= 1;
                s1[i] += (long long)(ch - '0');
                scanf("%c", &ch);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            s2[i] = 0LL;
            char ch;
            scanf("%c", &ch);
            while(ch != ' ' && ch != '\n')
            {
                s2[i] <<= 1;
                s2[i] += (long long)(ch - '0');
                scanf("%c", &ch);
            }
        }

        sort(s2, s2 + n);

        int ans = 1000;
        for(int i = 0 ; i < n ; i++)
        {
            long long res = s2[0] ^ s1[i];
            long long temp = res;
            int now = 0;
            while(temp)
            {
                if(temp&1)now++;
                temp >>= 1;
            }
            for(int j = 0 ; j < n ; j++)
                s3[j] = s1[j] ^ res;

            sort(s3, s3 + n);

            for(int i = 0 ; i < n ; i++)
            if(s2[i] == s3[i])
            {
                if(i == n - 1)ans = min(ans, now);
            }
            else break;
        }

        printf("Case #%d: ", cas);
        if(ans == 1000)puts("NOT POSSIBLE");
        else           printf("%d\n", ans);
    }


    return 0;
}
