#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 11111111
#define eps 1e-8
using namespace std;
int n, L;
string sa[155], sb[155], tt[155];
int main()
{
    freopen("C:/A-small-attempt0.in", "r", stdin);
    freopen("C:/A-small-attempt0.out", "w", stdout);
    char tmp[55];
    int T;
    int cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &L);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", tmp);
            sa[i] = tmp;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%s", tmp);
            sb[i] = tmp;
        }
        sort(sb, sb + n);
        int ans = INF;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) tt[j] = sa[j];
            int cnt = 0;
            for(int j = 0; j < L; j++)
            {
                if(sa[0][j] != sb[i][j])
                {
                    cnt++;
                    for(int k = 0; k < n; k++)
                    {
                        if(tt[k][j] == '1') tt[k][j] = '0';
                        else tt[k][j] = '1';
                    }
                }
            }
            sort(tt, tt + n);
            int flag = 1;
            for(int j = 0; j < n; j++)
                if(tt[j] != sb[j]) flag = 0;
            if(flag) ans = min(ans, cnt);
        }
        printf("Case #%d: ", ++cas);
        if(ans == INF) printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
