#include <bits/stdc++.h>
using namespace std;

vector<int> g[1011];
int n, cnt=0, vis[1011], dp[1011][2], chk;

void rootcheck(int u)
{
    vis[u]=1;
    vector<int> tmp;

    for(int i=0; i<g[u].size(); ++i)
    {
        int v=g[u][i];
        if(vis[v])continue;

        rootcheck(v);
        tmp.push_back(dp[v][0]+dp[v][1]+1);
    }

    sort(tmp.begin(), tmp.end());
    if(tmp.size()==2)
    {
        dp[u][0]=tmp[0], dp[u][1]=tmp[1];
    }
    if(tmp.size()==1)
    {
        cnt+= tmp[0];
    }
    if(tmp.size()>2)
    {
        int s=tmp.size()-1;
        dp[u][0]=tmp[s], dp[u][1]=tmp[s-1];
        for(int i=0; i<s-1; ++i)cnt+= tmp[i];
    }
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int t; cin >> t;
    for(int test=1; test<=t; ++test)
    {
        cin >> n;
        int mina=1011;

        for(int i=1; i<n; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=1; i<=n; ++i)
        {
            cnt=0; chk=i;
            memset(dp, 0, sizeof dp); memset(vis, 0, sizeof vis);
            rootcheck(i);
            mina=min(mina, cnt);
        }
        printf("Case #%d: %d\n", test, mina);

        for(int i=0; i<1011; ++i)g[i].clear();
    }
    return 0;
}

