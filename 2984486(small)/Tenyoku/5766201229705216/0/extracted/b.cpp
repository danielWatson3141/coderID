#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> G[1000];
bool used[1000];

int dfs_size(int root, int pre)
{
    int ans = 1;
    for(int i=0; i<G[root].size(); ++i)
        if(G[root][i]!=pre) ans += dfs_size(G[root][i], root);
    return ans;
}

int dfs(int root, int pre)
{
    int mx=0, mx2=0;
    int ans = 0;
    for(int i=0; i<G[root].size(); ++i)
        if(G[root][i]!=pre)
        {
            int tmp = dfs_size(G[root][i], root);
            ans += tmp;
            tmp -= dfs(G[root][i], root);
            if(tmp > mx)
            {
                mx2 = mx;
                mx = tmp;
            }
            else if(tmp > mx2) mx2 = tmp;
        }
    if((pre==-1&&G[root].size()<2) || (pre!=-1&&G[root].size()<3))
        mx = mx2 = 0;
    return ans-mx-mx2;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i) G[i].clear();
        for(int i=0; i<n-1; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans = n;
        for(int i=0; i<n; ++i)
            ans = min(ans, dfs(i, -1));
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
