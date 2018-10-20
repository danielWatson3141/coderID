#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstring>
#define ll long long
using namespace std;

int n;
const int maxn = 1010;
const int maxm = 1010;
struct EE
{
    int to,ne;
}e[2 * maxm];
int head[maxn];
int L;
void adde(int u,int v)
{
    e[L].to = v;
    e[L].ne = head[u];
    head[u] = L++;
}
void init()
{
    L = 0;
    memset(head,-1,sizeof(head));
}
int dp[1010];
void dfs(int u,int fa)
{
    int ma0,ma1;
    ma0 = ma1 = -1;
    for (int i = head[u]; i != -1; i = e[i].ne) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v,u);
        if (dp[v] > ma0) {
            ma1 = ma0;
            ma0 = dp[v];
        }
        else
        if (dp[v] > ma1) {
            ma1 = dp[v];
        }
    }
    if (ma1 == -1) dp[u] = 1;
    else dp[u] = 1 + ma0 + ma1;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int cas,T;
    cas = 1;
    cin>>T;
    while (T--) {
        scanf("%d",&n);
        init();
        for (int i = 0; i < n - 1; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            adde(u,v);
            adde(v,u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dfs(i, -1);
            ans = max(ans,dp[i]);
        }
        printf("Case #%d: %d\n",cas++,n - ans);
    }
}
