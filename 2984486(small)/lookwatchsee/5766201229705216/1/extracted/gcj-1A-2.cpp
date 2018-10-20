#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int dfs(vector<vector<bool> >& G, int p, int cur, const int N) {
    vector<int> neibor;
    for (int j=0;j<N;++j) {
        if (G[cur][j] && j!=p) {
            neibor.push_back(j);
        }
    }
    int n=neibor.size();
    //cout<<"neibor size="<<n<<endl;
    if (n<=1) return 1; 
    int ans=0;
    vector<int> record(n,0);
    for (int i=0;i<n;++i) {
        record[i]=dfs(G,cur, neibor[i] ,N);
    }
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j) {
            ans=max(ans, record[i]+record[j]);
        }
    }
    return 1+ans;
}
int solve(vector<vector<bool> >& G, const int N) {
    int ans=0;
    for (int root=0;root<N;++root) {
        //cout<<"root="<<root<<endl;
        //choose a root
        //ans=max(ans, dfs(G,-1, root,N));
        int t=dfs(G,-1, root,N);
        //cout<<"root="<<root<<" size="<<t<<endl;
        ans=max(ans,t);
    }
    return N-ans;
}
int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int N;
        cin>>N;
        vector<vector<bool> > G(N, vector<bool>(N,false));
        for (int i=0;i<N-1;++i) {
            int x,y;
            cin>>x>>y;
            x--;y--;
            G[x][y]=G[y][x]=true;
        }
        int ans=solve(G, N);
        cout<<"Case #"<<t<<": "<<ans<<endl;;
    }
    return 0;
}
