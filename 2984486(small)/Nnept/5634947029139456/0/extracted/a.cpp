#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 5;
const int INF = 0x3f3f3f3f;

string s1[12], s2[12], s3[12];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, cas = 1, n, l;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; i ++)
            cin >> s1[i];
        for(int i = 0; i < n; i ++)
            cin >> s3[i];
        int ans = INF;
        sort(s1, s1 + n);
        for(int i = 0; i < (1 << l); i ++)
        {
            int tmp = 0;
            for(int j = 0; j < n; j ++) s2[j] = s3[j];
            for(int j = 0; j < l; j ++) if((1 << j) & i)
            {
                tmp ++;
                for(int k = 0; k < n; k ++)
                {
                    if(s2[k][j] == '1') s2[k][j] = '0';
                    else s2[k][j] = '1';
                }
            }
            sort(s2, s2 + n);
            for(int j = 0; j < n; j ++)
            {
                if(s1[j] != s2[j]) tmp = INF;
            }
            ans = min(ans, tmp);
        }
        printf("Case #%d: ", cas ++);
        if(ans == INF) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
}
