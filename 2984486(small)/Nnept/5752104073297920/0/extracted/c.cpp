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

const int INF = 0x3f3f3f3f;
const int maxn = 1100;

int a[maxn];

int main()
{
    freopen("C-small-attempt5.in", "r", stdin);
    freopen("C-small-attempt5.out", "w", stdout);
    int T, cas = 1, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        int tot = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j < n; j ++)
            {
                if(a[j] > a[i]) tot ++;
            }
        }
        printf("Case #%d: ", cas ++);
        if(tot <= n*(n-1) / 2 / 2) puts("GOOD");
        else puts("BAD");
    }
}
