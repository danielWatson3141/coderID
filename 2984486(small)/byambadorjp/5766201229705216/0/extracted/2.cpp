#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n, ans;
vector<int> G[1005];
int need[1005];
int node[1005];

int dfs2(int p, int v){
    int ret = 1;
    int sz = G[v].size();
    if(p != 0 && sz == 1) return node[v] = ret;
    for(int i = 0; i < sz; i++){
        int u = G[v][i];
        if(u == p) continue;
        ret += dfs2(v, u);
    }
    return node[v] = ret;
}

int dfs(int p, int v){
    int mn1 = 0, mn2 = 0;
    int sz = G[v].size();
    if(p != 0 && sz == 1) return 0;
    for(int i = 0; i < sz; i++){
        int u = G[v][i];
        if(u == p) continue;
        need[u] = dfs(v, u);
    }
    for(int i = 0; i < sz; i++){
        int u = G[v][i];
        if(u == p) continue;
        if(node[u] - need[u] > mn1){
            if(mn1 > mn2)
                mn2 = mn1;
            mn1 = node[u] - need[u];
        }
        else if(node[u] - need[u] > mn2){
            mn2 = node[u] - need[u];
        }
    }
    if(p != 0 && sz > 2)
        return node[v] -1 - mn1 - mn2;
    if(p == 0 && sz == 2)
        return node[v] -1 - mn1 - mn2;
    return node[v] - 1;
}

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        scanf("%d",&n);
        printf("Case #%d: ",t);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i < n; i++){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        ans = n;
        for(int i = 1; i <= n; i++){
            dfs2(0, i);
            int q = dfs(0, i);
            if(q < ans) ans = q;
        }
        printf("%d\n",ans);
    }
    return 0;
}
