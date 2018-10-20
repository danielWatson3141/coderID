#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <functional>
#include <cmath>
#define CLR(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
int n;
vector<int> G[1001];
int sz[1001],del[1001];
int dfs(int cur,int pre){
    //cout<<"in"<<cur<<endl;
    int s = G[cur].size();
    int sc=1,dc=0;
    int tot = 0;
    for(int i=0;i<s;i++){
        if(pre == G[cur][i])
            continue;
        dfs(G[cur][i],cur);
        sc+=sz[G[cur][i]];
        tot+=sz[G[cur][i]];
        dc+=del[G[cur][i]];
    }
    sz[cur] = sc;
    //cout<<"xxx"<<cur<<" "<<s<<" "<<pre<<endl;
    if((s == 1&&pre!=0)||(s==0&&pre==0)){//leaf{
        del[cur] = 0;
        return 0;
    }else if((s == 2&&pre!=0)||(s==1 && pre==0)){
        del[cur] = sc-1;
        //cout<<"oo"<<cur<<" "<<sc<<endl;
        return del[cur];
    }else{
        int msc = 10000000;
        for(int i=0;i<s;i++){
            if(G[cur][i] == pre)
                continue;
            for(int j=i+1;j<s;j++){
                if(G[cur][j] == pre)
                    continue;
                int ttt = tot-(sz[G[cur][i]]+sz[G[cur][j]])+del[G[cur][i]]+del[G[cur][j]];
                if(ttt<msc)
                    msc =ttt;
            }
        }
        del[cur] = msc;
        return msc;
    }
 
}
int main(){
    //ios::sync_with_stdio(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>n;
        int x,y;
        for(int i=0;i<=1000;i++)
            G[i].clear();
        for(int i=1;i<n;i++){
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = n;
        for(int i=1;i<=n;i++){
            CLR(sz);
            CLR(del);
            int tmp = dfs(i,0);
            //cout<<tmp<<endl;
            for(int i=1;i<=n;i++)
               // /cout<<i<<" "<<sz[i]<<" "<<del[i]<<endl;
            if(tmp<ans)
                ans = tmp;
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
}