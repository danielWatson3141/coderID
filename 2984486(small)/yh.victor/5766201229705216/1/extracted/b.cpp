#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>link[1010];
int dp[1010][1010],n;
int dfs(int who,int from)
{
    if(dp[who][from]!=-1)
    {
        return dp[who][from];
    }
    int ret = 1;
    for(int i = 0; i < link[who].size(); i ++)
    for(int j = i+1; j < link[who].size(); j ++)
    {
        int to1 = link[who][i], to2 = link[who][j];
        if(to1 == from || to2 == from)continue;
        ret = max(ret, 1 + dfs(to1,who)+dfs(to2,who));
    }
    return dp[who][from]=ret;
}
int main()
{
    int ti;scanf("%d",&ti);
    for(int ca=1; ca<=ti; ca++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=1; i<=n; i ++)
        {
            link[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            link[a].push_back(b);
            link[b].push_back(a);
        }
        int ret = 0;
        for(int i=1; i<=n; i ++)
        {
            ret = max(ret,dfs(i,0));
        }
        printf("Case #%d: %d\n",ca,n-ret);
    }
}
