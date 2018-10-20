#include <bits/stdc++.h>
#define N 1111
#define INF 10000000
using namespace std;

vector<vector<int> > adj;

int dp[N] , c[N] , caso;
int solve(int u,int parent){
    if(c[u] == caso) return dp[u];
    c[u] = caso;

    int res = 1;

    for(int i = 0; i < adj[u].size(); ++i){
        int children1 = adj[u][i];
            if(children1 == parent) continue;

        int c1 = solve(children1,u);
        for(int j = i + 1; j < adj[u].size(); ++j){
        int children2 = adj[u][j];
            if(children2 == parent) continue;

            int c2 = solve(children2,u);
        res = max(res , 1 + c1 + c2);
        }
    }
    return dp[u] = res;

}

int main(){
    freopen("in.c","r",stdin);
    freopen("salida.cpp","w",stdout);

    int tc , nc = 1 , n , x , y;
    cin >> tc;

    while(tc--){
        cin >> n;

        adj.assign(n,vector<int>());
        for(int i = 0; i <  n - 1; ++i)
        { cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int res = INF;
        for(int root = 0; root < n; root++){
            ++caso;
            res = min(res , n - solve(root,-1));
        }
        printf("Case #%d: %d\n",nc++,res);
    }








    return 0;
}

