#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#define rep(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=(a);i<=(b);i++)
#define fba(i,b,a) for(int i=(b);i>=(a);i--)
#include<fstream>
using namespace std;
const int N=1005;
const int INF=0x3f3f3f3f;
vector<int>g[N];
int degree[N];
bool visit[N];
int dfs(int root,bool flag){
    visit[root]=1;
    if(flag){
        int max1=0,max2=0;
        rep(i,g[root].size()){
            int tp=dfs(g[root][i],0);
            if(tp>max1){
                max2=max1;
                max1=tp;
            }else if(tp>max2)max2=tp;
        }
        return 1+max1+max2;
    }else {
        if(g[root].size()==1||g[root].size()==2){
            return 1;
        }else if(g[root].size()>=3){
            int max1=0,max2=0;
            rep(i,g[root].size()){
                if(!visit[g[root][i]]){
                    int tp=dfs(g[root][i],0);
                    if(tp>max1){
                        max2=max1;
                        max1=tp;
                    }else if(tp>max2)max2=tp;
                }
            }
            return 1+max1+max2;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int T,n,v,u;
    //fstream fout;
    ////fout.open("data.txt",ios::out);
    cin>>T;
    fab(t,1,T){
        rep(i,N)g[i].clear();
        memset(visit,0,sizeof(visit));
        cin>>n;
        fab(i,1,n-1){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=n;
        int use=0;
        fab(root,1,n){
            memset(visit,0,sizeof(visit));
            if(g[root].size()>=2)use=max(use,dfs(root,true));
        }
        ans=n-use;
        if(n==2)ans=1;
        cout<<"Case #"<<t<<": ";
        cout<<ans<<endl;

    }
    //fout.close();
    return 0;
} 
