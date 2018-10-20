#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int>v[1001];
int dp[1005], keep[1005], root;
void dfs(int now, int fa)
{
    int  maxkeep1 = 0, maxkeep2 = 0, i, s;
    dp[now] = 1;
    for (i = 0,  s = (int)v[now].size(); i < s; i ++)
        if (v[now][i] != fa)
        {
            dfs(v[now][i], now);
            dp[now] += dp[v[now][i]];
            if (maxkeep1 < keep[v[now][i]])
                maxkeep2 = maxkeep1, maxkeep1 = keep[v[now][i]];
            else if (maxkeep2 < keep[v[now][i]])
                maxkeep2 = keep[v[now][i]];
        }
    if (root != now)
    {
        if (s > 2)
            keep[now] = maxkeep1 + maxkeep2 + 1;
        else
            keep[now] = 1;
    }
    else
    {
        if (s >= 2)
            keep[now] = maxkeep1 + maxkeep2 + 1;
        else
            keep[now] = 1;
    }
}
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int cases, cas;
    for (scanf("%d", &cases),cas = 1; cas <= cases; cas ++)
    {
        int n, x, y;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            v[i].clear();
        for (int i = 1; i < n; i ++)
        {
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int  maxkeep = 0;
        for (int i = 1; i <= n; i ++)
        {
            dfs(root = i, i);
            if (keep[root] > maxkeep)
                maxkeep = keep[root];
        }
        printf("Case #%d: %d\n", cas, n - maxkeep);
    }
}

