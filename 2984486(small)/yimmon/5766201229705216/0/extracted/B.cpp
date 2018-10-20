/*********************************************************************************
*     File Name           :     B.cpp
*     Created By          :     YIMMON, yimmon.zhuang@gmail.com
*     Creation Date       :     [2014-04-26 11:16]
*     Last Modified       :     [2014-04-26 11:22]
*     Description         :
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define     N 1050
using namespace std;

int T, n, a, b;
vector<int> child[N];

int dfs(int root, int n, bool vst[])
{
    if (child[root].size() < 2)
        return 1;
    int ans = 1, tmp;
    for (int i = 0; i < (int)child[root].size(); i++)
        for (int j = i + 1; j < (int)child[root].size(); j++)
        {
            if (vst[child[root][j]] == 0 && vst[child[root][i]] == 0)
            {
                vst[child[root][i]] = 1, vst[child[root][j]] = 1;
                tmp = 1;
                tmp += dfs(child[root][i], n, vst);
                tmp += dfs(child[root][j], n, vst);
                if (tmp > ans)
                    ans = tmp;
                vst[child[root][i]] = 0, vst[child[root][j]] = 0;
            }
        }
    return ans;
}

int solve(int idx, int n)
{
    bool vst[N];
    int ans = 1;
    memset(vst, 0, sizeof(vst));
    vst[idx] = 1;
    ans = max(ans, dfs(idx, n, vst));
    return ans;
}

int main(int argc, char *argv[])
{
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            child[i].clear();

        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &a, &b);
            child[a].push_back(b);
            child[b].push_back(a);
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, solve(i, n));
        printf("Case #%d: %d\n", cas, n - ans);
    }
    return 0;
}
