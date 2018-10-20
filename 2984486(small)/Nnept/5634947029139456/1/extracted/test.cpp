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

string s1[200], s2[200];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, cas = 1, n, l;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; i ++)
            cin >> s1[i];
        for(int i = 0; i < n; i ++)
            cin >> s2[i];
        int ans = 0, flag = 1;
        for(int i = 0; i < l; i ++)
        {
            int t1 = 0, t2 = 0;
            for(int j = 0; j < n; j ++)
            {
                if(s2[j][i] == '1') t2 ++;
            }
            for(int j = 0; j < n; j ++)
            {
                if(s1[j][i] == '1') t1 ++;
            }
            if(t1 == t2) continue;
            if(t1 + t2 == n)
            {
                ans ++;
            }
            else flag = 0;
        }
        printf("Case #%d: ", cas ++);
        if(!flag) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
}
