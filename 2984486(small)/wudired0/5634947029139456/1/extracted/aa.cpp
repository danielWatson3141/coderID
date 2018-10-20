#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int cs, i,j ,k ,n,m;
string base[503], target[503], ori[503];
int main()
{
    char str[503];
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &cs);
    for (int tt = 1; tt <= cs; ++tt)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            ori[i] = str;
        }
        for (int i = 0; i <n; ++i)
        {
            scanf("%s", str);
            target[i] = str;
        }
        sort(target, target + n);
        int best = 100000;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                base[j] = ori[j];
            for (int j = 0; j < m; ++j)
            {
                if (base[i][j] != target[0][j])
                {
                    cnt++;
                    for (int k = 0; k < n; ++k)
                    {
                         if (base[k][j] == '0')
                            base[k][j] = '1';
                         else
                             base[k][j] = '0';
                    }
                }
            }
            sort(base, base + n);
            bool flag = true;
            for (int j = 0; j < n; ++j)
                if (base[j] != target[j])
                {
                    flag = false;
                    break;
                }
            if (flag)
            best = min(best, cnt);
        }
        if (best != 100000)
           printf("Case #%d: %d\n", tt, best);
        else
            printf("Case #%d: NOT POSSIBLE\n", tt);
    }
}
     
