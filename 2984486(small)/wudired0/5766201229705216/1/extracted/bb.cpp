#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int cs;
vector<int> vec[1005];
int i,j,k,n,m;
bool used[1005];
int ss[1005], ff[1005];
void dfs(int root)
{
    vector<int>dp;
    used[root] = true;
    int cnt = 0;
    ff[root] = 0;
    for (int i = 0; i < vec[root].size(); ++i)
    {
        int son = vec[root][i];
        if (used[son])
           continue;
        else
        {
            dfs(son);
            ff[root] += ff[son] + 1;
            dp.push_back(ss[son]);
        }
    }
    sort(dp.begin(), dp.end());
    int ret = 0;
    for (int i = 0; i < dp.size(); ++i)
        ret += dp[i];
    
    if (dp.size() <= 1)
       ss[root] = 0;
    else if (dp.size() >= 2 )
    {
        ss[root] = 2 + dp[dp.size() - 2] + dp[dp.size() - 1];
    }
    return;
}
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &cs);
    for (int tt = 1; tt <= cs; ++tt)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            vec[i].clear();
        for (int i = 1; i < n;  ++i)
        {
            scanf("%d%d", &j, &k);
            --j;
            --k;
            vec[j].push_back(k);
            vec[k].push_back(j);
        }
        int best = 10000;
        for (int i = 0; i < n; ++i)
        {
            memset(used, false, sizeof(used));
            dfs(i);
            best = min(best, n - ss[i] - 1);
        }
        printf("Case #%d: %d\n", tt, best);
    }
}
