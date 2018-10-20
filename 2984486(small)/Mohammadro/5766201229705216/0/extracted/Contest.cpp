#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
const int maxn=1000+10;
const int INF=1000000000;
int n,t;
vi adj[maxn];
int dp[maxn];
int sz[maxn];
int ans;
void Dfs(int v,int par){
    sz[v]=1;
    for(int i=0;i<adj[v].size();i++){
        int u=adj[v][i];
        if(u!=par){
            Dfs(u,v);
            sz[v]+=sz[u];
        }
    }
    if(par==0){
        if(adj[v].size()>=2){
            int mn1,mn2;
        int p1,p2;
        mn1=-1;
        mn2=-1;
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(sz[u]-dp[u]>mn1){
                mn1=sz[u]-dp[u];
                p1=u;
            }
        }
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(sz[u]-dp[u]>mn2 && u!=p1){
                mn2=sz[u]-dp[u];
                p2=u;
            }
        }
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(u!=p1 && u!=p2)dp[v]+=sz[u];
        }
        dp[v]+=dp[p1];
        dp[v]+=dp[p2];
        }
        else if(adj[v].size()==1){
            int u=adj[v][0];
            dp[v]+=sz[u];
        }
    }
    else{
        if(adj[v].size()>2){
        int mn1,mn2;
        int p1,p2;
        mn1=-1;
        mn2=-1;
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(u!=par && sz[u]-dp[u]>mn1){
                mn1=sz[u]-dp[u];
                p1=u;
            }
        }
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(u!=par && sz[u]-dp[u]>mn2 && u!=p1){
                mn2=sz[u]-dp[u];
                p2=u;
            }
        }
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            if(u!=par && u!=p1 && u!=p2)dp[v]+=sz[u];
        }
        dp[v]+=dp[p1];
        dp[v]+=dp[p2];
        }
        else if(adj[v].size()==2){
            int u;
            if(adj[v][0]==par)u=adj[v][1];
            else u=adj[v][0];
            dp[v]+=sz[u];
        }
    }
    return;
}
int main(){
    ifstream cin("ans.in");
    ofstream cout("ans.out");
    cin>>t;
    for(int l=1;l<=t;l++){
        for(int i=0;i<maxn;i++)adj[i].clear();
        ans=INF;
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=1;i<=n;i++){
            memset(dp,0,sizeof(dp));
            memset(sz,0,sizeof(sz));
            Dfs(i,0);
            ans=min(ans,dp[i]);
        }
        cout<<"Case #"<<l<<": "<<ans<<endl;
    }

}
