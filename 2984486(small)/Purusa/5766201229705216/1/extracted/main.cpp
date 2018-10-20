#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[2000];
bool cache[2000];
int dp[2000];
int sz[2000];

void init(int u, int p)
{
    sz[u]=1;
    for(auto v: adj[u])
        if(v!=p)
        {
            init(v, u);
            sz[u]+=sz[v];
        }
}

bool isfull(int u, int p)
{
    if(cache[u])
        return cache[u];
    if(sz[u]==1)
        return cache[u]=true;
    if(adj[u].size()-bool(p)!=2)
        return cache[u]=false;
    cache[u]=true;
    for(auto v: adj[u])
        if(v!=p)
            cache[u]=cache[u] && isfull(v, u);
    return cache[u];
}

int& rec(int u, int p)
{
    int& ret=dp[u];
    if(ret==-1)
    {
        if(isfull(u, p))
            return ret=0;
        ret=sz[u]-1;
        for(auto v: adj[u])
            for(auto w: adj[u])
                if(v!=w && v!=p && w!=p)
                    ret=min(ret, rec(v, u)+rec(w, u)+sz[u]-sz[v]-sz[w]-1);
    }
    return ret;
}

void solve()
{
    scanf("%d", &N);
    for(auto& v: adj)
        v.clear();
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0x3f3f3f3f;
    for(int i=1; i<=N; i++)
    {
        memset(dp, -1, sizeof dp);
        memset(cache, 0, sizeof cache);
        init(i, 0);
        ans=min(ans, rec(i, 0));
    }
    printf(" %d\n", ans);
}

int main()
{
    //freopen("B.in", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
