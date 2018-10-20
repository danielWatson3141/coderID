#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
const int MAXN = 1024;
std::vector<int>adj[MAXN];
int sum[MAXN], tmp = 0;
const int INF = 0x3fffffff;
#define dprintf //printf
void dfs(int k, int p){
    int deg = adj[k].size();
    sum[k] = 1;
    for(int i = 0; i < deg; ++i){
        int v = adj[k][i];
        if(v != p){
            dfs(v, k);
            sum[k] += sum[v];
        }
    }
}

void dfs2(int k, int p){
    int deg = adj[k].size();
    int max1 = 0, max1v = -1;
    int max2 = 0, max2v = -1;
    for(int i = 0; i < deg; ++i){
        int v = adj[k][i];
        if( v != p){
            if(sum[v] > max1) {
                max2 = max1, max2v = max1v;
                max1 = sum[v], max1v = v;
            }
            else if(sum[v] > max2) max2 = sum[v], max2v = v;
        }
    }
    if(max1v == -1 && max2v == -1) {// leaf
        return;
    }
    if(max1v == -1 || max2v == -1){ // only one branch
        tmp += sum[k] - 1;
        return;
    }
    tmp += sum[k] - 1 - max1 - max2; // keep the maximum two branches
    dfs2(max1v, k);
    dfs2(max2v, k);
    return;
}


void solve(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        adj[i].clear();
    for(int i = 1; i < N; ++i){
        int s, t;
        scanf("%d %d\n", &s, &t);
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    int ans = N;
    for(int i = 1; i <= N; ++i){
        dfs(i, -1);
        tmp = 0;
        dfs2(i, -1);
        if(tmp < ans) ans = tmp;
    }
    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        solve();
    }
}
