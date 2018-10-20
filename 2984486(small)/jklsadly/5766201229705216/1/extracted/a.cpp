#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 1010;
int dp[maxn];
int n;
vector<int>arc[maxn];

void dfs(int u, int fa)
{
    int ma0 = 0, ma1 = 0;
    for(int i = 0; i < arc[u].size(); i++)
    {
        int v = arc[u][i];
        if(v == fa) continue;
        dfs(v, u);
        int tmp = dp[v];
        if(ma0 < tmp)
            ma1 = ma0, ma0 = tmp;
        else
        if(ma1 < tmp)
            ma1 = tmp;
    }

    dp[u] = 1;
    if(ma1 > 0)
        dp[u] += ma1 + ma0;
}

int solve(int u)
{
    dfs(u, -1);

    //for(int i = 1; i <= n; i++)
      //  printf("\t%d", dp[i]);puts("");
   // printf("{%d, %d}\n", ans - 1, tmp);
    return dp[u];
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("a.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            arc[i].clear();

        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            arc[u].push_back(v);
            arc[v].push_back(u);
        }

        int ans = n;
        for(int i = 1; i <= n; i++)
            ans = min(ans, n - solve(i));
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
