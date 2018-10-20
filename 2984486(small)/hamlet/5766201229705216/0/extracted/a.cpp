#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
vector<int>v[1005];
bool visited[1005];
vector<int>adj[1005];
int memo[1005];

void dfs(int node){
    visited[node]=1;
    for(int i=0;i<v[node].size();i++){
        int t=v[node][i];
        if(!visited[t]){
            adj[node].push_back(t);
            dfs(t);    
        }    
    }    
}

int dp(int node){
    if(adj[node].size()<2)return 1;
    if(memo[node]!=-1)return memo[node];
    
    int maxi1=-1;
    int maxi2=-100000;
    for(int i=0;i<adj[node].size();i++){
        int val=dp(adj[node][i]);
        if(val>=maxi1){
            maxi2=maxi1;
            maxi1=val;    
        }else{
            if(val>maxi2){
                maxi2=val;    
            }    
        }
        
    }
    
    memo[node]=1+maxi1+maxi2;    
    return memo[node];
}

int main(){
    
    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int N;
        cin>>N;
        
        for(int i=0;i<1005;i++)v[i].clear();
        
        for(int i=0;i<N-1;i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);    
        }
        
        int mini=N-1;
        
        for(int i=1;i<=N;i++){
            for(int j=0;j<1005;j++)adj[j].clear();
            memset(visited,0,sizeof(visited));
            dfs(i);
            memset(memo,-1,sizeof(memo));
            int val=dp(i);
            mini=min(mini,N-val);
        }        
        
        cout<<mini<<endl;
        
    }
    
    
    return 0;
}
