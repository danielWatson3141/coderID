#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n, l;
struct node
{
    char s[45];
    bool operator < (const node &T) const
    {
        for (int i = 0; i < l; i ++)
            if (s[i] < T.s[i])
                return 1;
            else if (s[i] > T.s[i])
                return 0;
        return 1;
    }
}sw[155], target[155], tmp[155];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int cases, cas;
    for (scanf("%d", &cases),cas = 1; cas <= cases; cas ++)
    {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i ++)
            scanf("%s", sw[i].s);
        for (int i = 0; i < n; i ++)
            scanf("%s", target[i].s);
        sort(target, target + n);
        int ans = 0xff;
        for (int i = 0, j, k, cnt; i < n; i ++)
        {
            for (j = 0; j < n; j ++)
                strcpy(tmp[j].s, sw[j].s);
            for (j = cnt = 0; j < l; j ++)
            {
                if (target[0].s[j] != sw[i].s[j])
                {
                    for (k = 0; k < n; k ++)
                        if (tmp[k].s[j] == '0')
                            tmp[k].s[j] = '1';
                        else
                            tmp[k].s[j] = '0';
                    cnt ++;
                }
            }
            if (cnt < ans)
            {
                sort(tmp, tmp + n);
                for (j = 0; j < n; j ++)
                    if (strcmp(tmp[j].s, target[j].s))
                        break;
                if (j == n)
                    ans = cnt;
            }
        }
        printf("Case #%d: ", cas);
        if (ans == 0xff)    puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
}
