#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> son[1010];

int dfs(int root, int n, bool visit[])
{
    if (son[root].size() < 2)
        return 1;
    int ans = 1;
    for (int i = 0; i < son[root].size(); ++i)
        for (int j = i+1; j < son[root].size();++j)
        {
            if (visit[son[root][i]]==0&&visit[son[root][j]]==0)
            {
                visit[son[root][i]] = 1;
                visit[son[root][j]] = 1;
                int tmp = 1;
                tmp += dfs(son[root][i], n, visit);
                tmp += dfs(son[root][j], n, visit);
                if (tmp > ans)
                    ans = tmp;
                visit[son[root][i]] = 0;
                visit[son[root][j]] = 0;
            }
        }
    return ans;
}

int solve(int index, int n)
{
    //cout << index << n << endl;
    int ans = 1;
    bool visit[1010];
    memset(visit, 0, sizeof(visit));
    visit[index] = 1;
    ans = max(ans, dfs(index, n,visit));

    return ans;
}

int main()
{
    int ii, T;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.in.txt", "w", stdout);

    cin>>T;
    for (ii = 1; ii <= T; ++ii)
    {
        int n,s,e;
        cin>>n;

        for (int i = 1; i <= n;++i)
            son[i].clear();

        for (int i = 1; i < n; ++i)
        {
            cin>>s>>e;
            son[s].push_back(e);
            son[e].push_back(s);
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            ans = max(ans, solve(i,n));
        }
        printf("Case #%d: %d\n", ii, n - ans);
    }
    return 0;
}
