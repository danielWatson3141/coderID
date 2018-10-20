#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> son[1010];
int vst[1010];
int n;

int dfs(int root, int n)
{
    if (son[root].size() < 2)
        return 1;
    int ans = 1;
    for (int i = 0; i < son[root].size(); ++i)
        for (int j = i+1; j < son[root].size(); ++j)
        {
            if (!vst[son[root][i]] && !vst[son[root][j]])
            {
                vst[son[root][i]] = 1;
                vst[son[root][j]] = 1;
                int tmp = 1;
                tmp += dfs(son[root][i], n);
                tmp += dfs(son[root][j], n);
                if (tmp > ans)
                    ans = tmp;
                vst[son[root][i]] = 0;
                vst[son[root][j]] = 0;
            }
        }
    return ans;
}

int solve(int cnt, int n)
{
    int ans = 1;
    memset(vst, 0, sizeof(vst));
    vst[cnt] = 1;
    ans = max(ans, dfs(cnt, n));
    return ans;
}

void Init()
{
    int v,w;
    scanf("%d", &n);

    for (int i = 1; i <= n;++i)
        son[i].clear();

    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &v, &w);
        son[v].push_back(w);
        son[w].push_back(v);
    }
}

int main()
{
    int t;
    freopen("B-large.in","r",stdin);
    freopen("answer.txt", "w", stdout);

    scanf("%d", &t);
    for (int cns = 1; cns <= t; ++cns)
    {
        Init();
        int ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            ans = max(ans, solve(i,n));
        }
        printf("Case #%d: %d\n", cns, n - ans);
    }
    return 0;
}
