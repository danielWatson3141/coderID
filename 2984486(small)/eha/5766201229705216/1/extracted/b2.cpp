#include <bits/stdc++.h>
using namespace std;

vector<int> G[1024];
bool used[1024];
int dp[1024][2];

//use 1 : true, 0 : false
int cnt(int v, bool use){
    //cout << v << " " << use << endl;
    if(dp[v][use] != -1) return dp[v][use];

    used[v] = true;

    //remove v
    if(use == 0){
        int rem = 1;
        for(int i = 0; i < G[v].size(); i++){
            int w = G[v][i];
            if(used[w]) continue;
            rem += cnt(w,false);
        }
        dp[v][0] = rem;
    } else {
        //use v : leave no child
        int use0 = 0;
        for(int i = 0; i < G[v].size(); i++){
            int w = G[v][i];
            if(used[w]) continue;
            use0 += cnt(w,false);
        }
        //use v : leave 2 child
        int use2 = use0;
        for(int i = 0; i < G[v].size(); i++){
            int w = G[v][i];
            if(used[w]) continue;
            for(int j = i+1; j < G[v].size(); j++){
                int u = G[v][j];
                if(used[u]) continue;
                use2 = min(use2, use0 - cnt(w,false) - cnt(u,false) + cnt(w,true) + cnt(u,true));
            }
        }
        dp[v][1] = use2;
    }

    used[v] = false;
    return dp[v][use];
}

int solve(){
    int n; cin >> n;

    //init
    for(int i = 0; i < n; i++) G[i].clear();

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 1000;
    for(int i = 0; i < n; i++){
        memset(dp,-1,sizeof(dp));
        int tmp = min(cnt(i,0),cnt(i,1));
        //cout << i << " " << cnt(i,0) << " " << cnt(i,1) << endl;
        ans = min(ans,tmp);
    }
    return ans;
}

int main(){
    int t; scanf("%d\n",&t);
    for(int i = 0; i < t; i++){
        printf("Case #%d: %d\n",i+1,solve());
    }
}

