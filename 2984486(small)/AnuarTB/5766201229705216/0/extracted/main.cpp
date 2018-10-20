#include <bits/stdc++.h>

#define debug

using namespace std;

const int MXN = 1e6 + 10;
const int INF = 1e9 + 7;

int n, u, v, T, ans, tmpk, root;
int cnt[20];
bool used[20];
vector <int> g[20];

void dfs(int v){
    used[v] = true;
    cnt[v] = 1;
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(!used[to]){
            dfs(to);
            cnt[v] += cnt[to];
        }
    }
}

void dfs2(int v){
    used[v] = true;
    bool del[20];
    memset(del, 0, sizeof(del));
    vector < pair <int, int> > tmp;
    if(root == v && g[v].size() == 1){
        tmpk = 1;
        return ;
    }
    if(root != v && g[v].size() == 2){
        tmpk -= cnt[v];
        return;
    }
    if(g[v].size() > 3 || (root == v && g[v].size() == 3)){
        for(int i = 0; i < g[v].size(); ++i)
            tmp.push_back(make_pair(cnt[g[v][i]], g[v][i]));
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < g[v].size() - 2; ++i){
            tmpk -= cnt[g[v][i]];
            del[tmp[i].second] = true;
        }
    }
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(!used[to] && !del[to]){
            dfs2(to);
        }
    }

}

void solve(){
    ans = n - 1;
    for(int i = 1; i <= n; ++i){
        tmpk = n;
        root = i;
        memset(used, 0, sizeof(used));
        memset(cnt, 0, sizeof(cnt));
        dfs(i);
        memset(used, 0, sizeof(used));
        dfs2(i);
        ans = min(n - tmpk, ans);
    }
    printf("%d\n", ans);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(int s = 1; s <= T; ++s){
        scanf("%d", &n);
        for(int i = 1; i < n; ++i){
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("Case #%d: ", s);
        solve();
        for(int i = 1; i <= n; ++i)
            g[i].clear();
    }
    return 0;
}
