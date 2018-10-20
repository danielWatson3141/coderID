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

const int maxn = 1100;
const int INF = 0x3f3f3f3f;

vector<int> G[maxn];
int dp[maxn];

int dfs(int u, int fa)
{
    int a[2] = {0}; dp[0] = 0;
    for(int i = 0; i < G[u].size(); i ++)
    {
        int v = G[u][i];
        if(v == fa) continue;
        dp[v] = dfs(v, u);
        if(dp[v] > dp[a[0]])
        {
            a[1] = a[0];
            a[0] = v;
        } else if(dp[v] > dp[a[1]])
        {
            a[1] = v;
        }
    }
    if(!a[0]) return 1;
    if(!a[1]) return 1;
    return dp[a[0]] + dp[a[1]] + 1;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, n, cas = 1;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) G[i].clear();

        for(int i = 1; i < n; i ++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = INF;
        for(int i = 1; i <= n; i ++)
        {
            ans = min(ans, n - dfs(i, -1));
        }
        printf("Case #%d: %d\n", cas ++, ans);
    }
}
