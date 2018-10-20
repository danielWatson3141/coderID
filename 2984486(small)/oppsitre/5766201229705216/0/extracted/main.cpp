#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1010
#define INF 0x3f3f3f3f
#define pb push_back
vector<int> G[MAXN];
int son[MAXN],root,stay[MAXN];
bool used[MAXN];
int dp[MAXN][5];
int dfs(int u,int fa){
    int ans = 0;
    used[u] = true;
    for(int i = 0; i <(int)G[u].size(); i++){
        int v = G[u][i];
        if(used[v]) continue;
        ans += dfs(v,u);
        son[u] += son[v] + 1;
    }
    if(u != root){
        if(G[u].size() == 2){
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                if(v == fa) continue;
                ans = son[v] + 1;
            }
        }
        else if(G[u].size() > 3){
            int p = 0;
            memset(dp,INF,sizeof(dp));
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                if( v == fa ) continue;
                int cut = son[v] + 1;
                if(p == 0){
                    dp[p][0] = cut;
                    dp[p][1] = stay[v];
                }
                else{
                    dp[p][0] = dp[p-1][0] + cut;
                    dp[p][1] = min(dp[p-1][0] + stay[v],dp[p-1][1] + cut);
                    dp[p][2] = min(dp[p-1][1] + stay[v],dp[p-1][2] + cut);
                }
                p++;
            }
            ans = min(dp[p-1][0],dp[p-1][2]);
        }
    }
    else if(u == root){
        if(G[u].size() == 1){
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                if(v == fa) continue;
                ans = son[v] + 1;
            }
        }
        else if(G[u].size() > 2){
            int p = 0;
            memset(dp,INF,sizeof(dp));
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                if( v == fa ) continue;
                int cut = son[v] + 1;
                if(p == 0){
                    dp[p][0] = cut;
                    dp[p][1] = stay[v];
                }
                else{
                    dp[p][0] = dp[p-1][0] + cut;
                    dp[p][1] = min(dp[p-1][0] + stay[v],dp[p-1][1] + cut);
                    dp[p][2] = min(dp[p-1][1] + stay[v],dp[p-1][2] + cut);
                }
                p++;
            }
            ans = min(dp[p-1][0],dp[p-1][2]);
        }
    }
    stay[u] = ans;
    return ans;
}
int main()
{
   // freopen("test.txt","r",stdin);
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++){
        int N;scanf("%d",&N);
        for(int i = 0; i <= N; i++) G[i].clear();
        for(int i = 0; i < N - 1 ; i++){
            int s,e;
            scanf("%d%d",&s,&e);
            G[s].pb(e);
            G[e].pb(s);
        }
        int ans = INF;
        for(int i = 1; i <= N; i++){
            memset(son,0,sizeof(son));
            memset(used,false,sizeof(used));
            memset(stay,0,sizeof(stay));
            root = i;
            ans = min(ans,dfs(i,0));
        }
        printf("Case #%d: ",cas);
        printf("%d\n",ans);
    }
    return 0;
}
