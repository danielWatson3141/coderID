#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

vector<int> adj[MAXN];

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int casos,ans;
    cin >> casos;
    for(int caso = 1 ; caso <= casos ; caso++){

        int n, u, v;
        cin >> n;

        for(int i = 0 ; i < n ; i++){
            adj[i].clear();
        }

        for(int i = 0 ; i < n-1 ; i++){
            cin >> u >> v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = n-1;
        int d[n],out[n];
        for(int mask = 1 ; mask < (1 << n) ; mask++){
            int nodes = __builtin_popcount(mask);
            vector<int> on;
            for(int i = 0 ; i < n ; i++){
                if(mask&(1<<i)){
                    on.push_back(i);
                }
            }
            for(int root = 0 ; root < nodes ; root++){
                memset(d,-1,sizeof d);
                memset(out,0,sizeof out);
                queue<int> q;
                q.push(on[root]);
                d[on[root]] = 0;
                int checker = 0;
                while(!q.empty()){
                    u = q.front() ; q.pop();
                    checker |= (1<<u);
                    for(int j = 0 ; j < adj[u].size() ; j++){
                        v = adj[u][j];
                        if(find(on.begin(),on.end(),v) != on.end() && d[v] == -1){
                            d[v] = d[u]+1;

                            out[u]++;
                            q.push(v);
                        }
                    }
                }
                bool sw = true;
                for(int i = 0 ; i < nodes ; i++){
                    sw &= (out[on[i]] == 2) || (out[on[i]] == 0);
                }
                if(sw && checker == mask){
                    if(ans > n-nodes){
                        ans = n - nodes;
                    }
                }
            }
        }
        cout << "Case #"<<caso<<": "<< ans << endl;
    }
    return 0;
}
