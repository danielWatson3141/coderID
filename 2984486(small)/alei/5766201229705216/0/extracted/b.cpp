#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
typedef long long int uli;
using namespace std;

const int mx = 1000+10;
const int inf = 1e8;
vector<int>g[mx];
bool vis[mx];
int nch[mx];

int mincuts(int u){
    vis[u] = true;
    vector<int>cq;
    nch[u] = 1;
    int cnt = 0;
    for(int i=0;i<(int)g[u].size();i++){
        int v = g[u][i];
        if(!vis[v]){
            cnt++;
            int c = mincuts(v);
            nch[u] += nch[v];
            cq.push_back(c-nch[v]);
        }    
    }
//    cout<<"nch "<<u<<"="<<nch[u]<<endl;
    int ans;
    if(cnt==0) ans = 0;
    else if(cnt==1) ans = nch[u]-1;
    else{
        sort(cq.begin(),cq.end());
        int sq = nch[u]-1;
        ans = sq + cq[0]+cq[1];
    }
    return ans;
}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t,n,u,v;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        for(int i=0;i<mx;i++) g[i].clear();
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);            
        }
        int ans = inf;
        for(int i=1;i<=n;i++){
            memset(vis,false, sizeof vis);
            memset(nch,0,sizeof nch);
            int minc = mincuts(i);
            ans = min(ans, minc);        
        }
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
