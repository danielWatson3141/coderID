#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

char s[15][15], tmp[15];
int cnt[1 << 10], cnt1[1 << 10];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int cases, cas;
    for (scanf("%d", &cases),cas = 1; cas <= cases; cas ++)
    {
        int n, l;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i ++)
            scanf("%s", s[i]);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, j, x; i < n; i ++)
        {
            scanf("%s", tmp);
            for (j = x = 0; j < l; j ++)
                if (tmp[j] == '1')
                    x |= 1 << j;
            cnt[x] ++;
        }
        int ans = 0xff;
        for (int i = 0, j, k, tmp; i < 1 << l; i ++)
        {
            memset(cnt1, 0, sizeof cnt1);
            for (j = 0; j < n; j ++)
            {
                for (k = tmp = 0; k < l; k ++)
                    if (((i & (1 << k)) && (s[j][k] == '0'))
                        ||((i & (1 << k)) == 0 && (s[j][k] == '1')))
                        tmp |= 1 << k;
                cnt1[tmp] ++;
            }
            for (k = tmp = 0; k < l; k ++)
                if (i & (1 << k))
                    tmp ++;
            if (tmp < ans)
            {
                for (j = 0; j < 1 << l; j ++)
                    if (cnt[j] != cnt1[j])
                        break;

                if (j == 1 << l)
                    ans = tmp;
            }
        }
        printf("Case #%d: ", cas);
        if (ans == 0xff)    puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
}
