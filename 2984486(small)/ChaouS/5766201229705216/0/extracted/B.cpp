#include <bits/stdc++.h>
#define N 1111
#define INF 10000000
using namespace std;

bool valid[N] , used[N];

vector<vector<int> > adj;
bool bynarytree;
void dfs(int u){
    used[u] = 1;

    int children = 0;
    for(int j = 0; j < adj[u].size(); ++j)
    {   int where = adj[u][j];
        if(!valid[where]) continue;

        if(!used[where]){
            children++;
            dfs(where);
        }
    }
    if(children!=0 && children!=2) bynarytree = false;
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
        for(int mask = 0 ; mask < 1<<n; mask++){
            int costo = 0;
            for(int i = 0; i < n; ++i)
                valid[i] = 1;

            vector<int> nodes;
            for(int i = 0; i < n; ++i)
                if(mask&(1<<i))
                   nodes.push_back(i);
                else
                    valid[i] = 0 , costo++;

            bool ok = 0;
            for(int i = 0; i < nodes.size(); ++i){
                int root = nodes[i];
                for(int k = 0; k < n; ++k) used[k] = 0;

                bynarytree = true;
                dfs(root);
                for(int k = 0; k < nodes.size(); ++k)
                    if(!used[nodes[k]]) bynarytree = false;

                if(bynarytree) { ok = 1; break; }
            }

            if(ok)
              res = min(res , costo);
        }

        printf("Case #%d: %d\n",nc++,res);
    }








    return 0;
}

