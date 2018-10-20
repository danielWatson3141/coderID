#include <stdio.h>
#include <string.h>
#include <algorithm>
const int N = 1111;
const int M = 2222;
struct Edge{
    int u, v;
    Edge(){}
    Edge(int u, int v):u(u),v(v){}
}edge[M];
int n, e;
int first[N], next[M];
void init()
{
    e = 0;
    memset(first, -1, sizeof(first));
}
void add(int u, int v)
{
    edge[e] = Edge(u,v);
    next[e] = first[u];
    first[u] = e++;
}
int sum[N], son[N];
int f[N];
void dfs(int u, int fa)
{
    sum[u] = 1;
    son[u] = 0;
    for(int i=first[u]; -1^i; i=next[i])
    {
        int v = edge[i].v;
        if(v==fa)    continue;
        dfs(v, u);
        sum[u] += sum[v];
        son[u] ++;
    }
}
void dp(int u, int fa)
{
    if(son[u]==0)
    {
        f[u] = 0;
        return;
    }
    f[u] = sum[u]-1;
    for(int i=first[u]; -1^i; i=next[i])
    {
        int vi = edge[i].v;
        if(vi==fa)  continue;
        for(int j=next[i]; -1^j; j=next[j])
        {
            int vj = edge[j].v;
            if(vj==fa || vj==vi)  continue;
            dp(vi, u);
            dp(vj, u);
            f[u] = std::min(f[u], f[vi]+f[vj]+sum[u]-sum[vi]-sum[vj]-1);
        }
    }
}
int main()
{
//    freopen("B-large.in", "r", stdin);
//    freopen("B.out", "w", stdout);

    int t, kase=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init();
        for(int i=1; i<n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        int ans = n-1;
        for(int i=1; i<=n; i++)
        {
            dfs(i, 0);
            dp(i, 0);
            ans = std::min(ans, f[i]);
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}

