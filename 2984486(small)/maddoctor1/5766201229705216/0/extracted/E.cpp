#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 11111111
#define eps 1e-8
using namespace std;
vector<int>g[1111];
int n;
int dp[1111];
int t[1111], ss[1111];
void dfs(int u, int fa)
{
    ss[u] = 1;
    int sz = g[u].size();
    int son = 0;
    for(int i = 0; i < sz; i++)
    {
        if(g[u][i] != fa)
        {
            son++;
            dfs(g[u][i], u);
            ss[u] += ss[g[u][i]];
        }
    }
    if(son == 0) dp[u] = 0;
    else if(son == 1) dp[u] = ss[u] - 1;
    else
    {
        int k = 0;
        for(int i = 0; i < sz; i++)
        {
            if(g[u][i] == fa) continue;
            t[k] = ss[g[u][i]] - dp[g[u][i]];
            k++;
        }
        sort(t, t + k);
        dp[u] = ss[u] - 1 - t[k - 1] - t[k - 2];
    }
}
int main()
{
    freopen("C:/B-small-attempt0.in", "r", stdin);
    freopen("C:/B-small-attempt0.out", "w", stdout);
    int cas = 0;
    int T, u, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = INF;
        for(int i = 1; i <= n; i++)
        {
            dfs(i, 0);
            ans = min(ans, dp[i]);
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
