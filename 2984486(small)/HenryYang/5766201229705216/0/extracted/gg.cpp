#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int adj[1003][1003], temp, Ans, v[1003];
int n, l, ctt = 0, tt;
void dfs(int x){
    temp++;
    v[x] = 1;
    int nct = 0;
    for(int i = 1; i <= n; i++)
        nct += !v[i] && adj[x][i];
    if(nct == 2){
        for(int i = 1; i <= n; i++)
            if(!v[i] && adj[x][i])
                dfs(i);
    }
}
int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    cin >> tt;
    while(tt--){
        Ans = 0;
        memset(adj, 0, sizeof(adj));
        cin >> n;
        for(int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            adj[a][b] = adj[b][a] = 1;
        }
        for(int i = 1; i <= n; i++){
            memset(v, 0, sizeof(v));
            temp = 0;
            dfs(i);
            Ans = max(temp, Ans);
        }
        printf("Case #%d: ", ++ctt);
        printf("%d\n", n - Ans);
    
    }
    return 0;
}