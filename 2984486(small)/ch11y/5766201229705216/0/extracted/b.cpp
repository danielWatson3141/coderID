#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <vector> 
#include <cstdio>
#include <stack>
#include <cassert>
#include <sstream>
using namespace std;  

const int maxn = 1000 + 10; 
vector< int > adj[maxn] ; 
int dp[maxn][2];
int have[maxn][3];
int N; 
void dfs( int u, int p=-1 ){ 
    if( 1 == adj[u].size()){ 
        if( p != -1 ) {
        dp[u][0]=1; 
        dp[u][1]=0;
        }else{
            dp[u][1] =N-1; 
            dp[u][0] = N; 
        }

        return;
    }
    for(int i = 0 ; i < adj[u].size(); ++i){
        if(adj[u][i] == p) {
            swap(adj[u][i], adj[u][0]);
            break;
        }
    }

    for(int i = 0 ; i < adj[u].size() ;++i){
        if(adj[u][i] == p) continue; 
        dfs(adj[u][i],u);
    }  
    for(int i = 0 ; i < adj[u].size(); ++i)
        memset(have[i],0x3f, sizeof(have[i]));
    for(int i = 0 ; i < adj[u].size(); ++i){
        if( i== 0  ){
            if( p != -1 ) have[0][0]=0;
            else{
                have[0][0]= dp[adj[u][i]][0]; 
                have[0][1]= dp[adj[u][i]][1];
            }
            continue; 
        }  
        for(int j=0  ; j <=2 ; ++j){ 
                have[i][j] = min( have[i-1][j] + dp[adj[u][i]][0], 
                        have[i][j]); 
                if(j) have[i][j] = min(have[i-1][j-1] 
                        + dp[adj[u][i]][1], have[i][j]);
        }
    } 
    dp[u][0]= have[ adj[u].size()-1][0] + 1; 
    dp[u][1] =min(have[adj[u].size()-1][0], have[ adj[u].size()-1][2]);
    //cout << u << " " << dp[u][0] <<" "<< dp[u][1]<<endl; 
}
        
int main (){
     freopen("b.in","r",stdin); 
    freopen("b.out","w",stdout); 
    int T;  
    cin >> T ; 
    for(int Cas = 1; Cas <= T ; ++Cas){
        int N ; 
        cin >>N;
        ::N=N;
        int ans = 0x3f3f3f3f; 
        for(int i=1; i <= N; ++i) 
            adj[i].clear(); 
        for(int i=1; i <=N-1; ++i){
            int u , v ; 
            cin >> u >> v ; 
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }
        for(int i=1; i <= N; ++i){
            memset(dp,0x3f,sizeof(dp));
            dfs(i); 
            ans = min(ans, dp[i][1]); 
        }
        cout <<"Case #"<<Cas<<": "<< ans << endl; 
    }
    return 0;
}


