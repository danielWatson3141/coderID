#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>



using namespace std;
#define INFY 100000000

int n;
vector<vector<int> > Graph;
vector<int> visited;
vector<int> visited1;

int root;
int dfs1(int v) {
    visited1[v] = 1;
    int ans = 1;
    for(int i = 0;i < Graph[v].size();i++) {
        if(!visited1[Graph[v][i]]) {
            ans+=dfs1(Graph[v][i]);
        }
    }
    return ans;
}

int dfs(int v) {
    visited[v] = 1;
    int nc = 0;
    for(int i = 0;i < Graph[v].size();i++) {
        if(!visited[Graph[v][i]]) nc++;
    }
    //cout<<v<<' '<<"nc = "<<nc<<endl;
    if(nc == 0) return 0;
    if(nc == 1) {
        for(int i = 0;i < Graph[v].size();i++) {
            if(!visited[Graph[v][i]]) {
                visited1[v] = 1;
                return dfs1(Graph[v][i]);
            }
        }
    }
    vector<pair<int,int> > poss;
    for(int i = 0;i < Graph[v].size();i++) {
        if(!visited[Graph[v][i]]) {
            poss.push_back(make_pair(dfs(Graph[v][i]),Graph[v][i]));
        }
    }
    sort(poss.begin(),poss.end());
    int ans = poss[0].first + poss[1].first;
    for(int i = 2;i < poss.size();i++) {
        ans+=dfs1(poss[i].second);
    }
    
    return ans;
    
    
    
}


int main() {
    freopen("/Users/arunamahesh/B-small-attempt0.in","r",stdin);
    freopen("/Users/arunamahesh/GCJ_output.txt","w",stdout);
    int t; cin>>t;
    for(int T = 1;T <= t;T++) {
        int n; cin>>n;
        Graph.clear();
        Graph.resize(n + 1);
        visited.resize(n + 1,0);
        visited1.resize(n + 1,0);
        for(int i = 0;i < n - 1;i++) {
            int a,b; cin>>a>>b;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
        int best = INFY;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) visited[j] = visited1[j] =  0;
            root = i;
            
            int q = dfs(i);
            //cout<<i<<' '<<q<<endl;
            if(q < best) best = q;
        }
        cout<<"Case #"<<T<<": "<<best<<endl;
    }
}