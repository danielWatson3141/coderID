#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define INF (-1)
#define MAXN 1001

int cnt[MAXN];
int dp[MAXN][MAXN];
int n;
vector<int> tree[MAXN];

int count_nodes(int pt, int father)
{
    int sz = tree[pt].size(), res = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (tree[pt][i] == father) continue;
        res += count_nodes(tree[pt][i], pt);
    }
    cnt[pt] = res + 1;
    return cnt[pt];
}
int dfs(int pt, int father)
{
    if (dp[pt][father] != INF) return dp[pt][father];
    int res = 0, sz = tree[pt].size();

    if (sz == 1 && father != 0)
    {
        res = 0;
    }
    else if ((sz == 2 && father != 0) || (sz == 1 && father == 0))
    {
        for (int i = 0; i < sz; ++i)
        {
            if (tree[pt][i] == father) continue;
            res += cnt[tree[pt][i]];
        }
    }
    else if ((sz == 3 && father != 0) || (sz == 2 && father == 0))
    {
        for (int i = 0; i < sz; ++i)
        {
            if (tree[pt][i] == father) continue;
            res += dfs(tree[pt][i], pt);
        }
    }
    else
    {
        int sum = 0, u, v;
        for (int i = 0; i < sz; ++i)
            if (tree[pt][i] != father)
                sum += cnt[tree[pt][i]];
        res = n;
        for (int i = 0; i < sz; ++i)
        {
            u = tree[pt][i];
            if (u == father) continue;
            for (int j = i + 1; j < sz; ++j)
            {
                v = tree[pt][j];
                if (v == father) continue;
                int tmp = dfs(u, pt) + dfs(v, pt) + sum - cnt[u] - cnt[v];
                //printf("pt = %d, u = %d, v = %d, tmp = %d\n", pt, u, v, tmp);
                res = min(res, tmp);
            }
        }
    }
    dp[pt][father] = res;
    //printf("pt = %d, res = %d\n", pt, res);
    return res;
}
void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        tree[i].clear();
        for (int j = 0; j < MAXN; ++j)
            dp[i][j] = INF;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}
int main()
{
    //freopen("b.txt", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    int T; scanf("%d", &T);
    int cas = 1;
    while (T--)
    {
        init();
        int ans = n;
        for (int root = 1; root <= n; ++root)
        {
            //printf("Root = %d\t", root);
            count_nodes(root, 0);
            ans = min(ans, dfs(root, 0));
            //printf("ans = %d\n", dp[root][0]);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
