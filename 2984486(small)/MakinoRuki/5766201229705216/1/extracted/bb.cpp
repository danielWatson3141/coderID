#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1005
#define inf 1000000000
using namespace std;
int T,n;
vector<int>E[N];
int x,y;
int f[N],son[N];
void dfs1(int u, int fa){
     son[u]=1;
     for(int i=0;i<E[u].size();++i){
             int v=E[u][i];
             if(v==fa)continue;
             dfs1(v,u);
             son[u]+=son[v];
     }     
}
int dfs2(int u, int fa){
    int num=0;
    for(int i=0;i<E[u].size();++i)
            if(E[u][i]!=fa)
                          num++;
    if(num==0)return f[u]=0;
    if(num==1){
               for(int i=0;i<E[u].size();++i)
                       if(E[u][i]!=fa){
                           f[u]=f[E[u][i]]+1;
                           return f[u];
                       }
    }
    int max1=0;
    int max2=0;
    for(int i=0;i<E[u].size();++i){
          int v=E[u][i];
          if(v==fa)continue;
          dfs2(v,u);
          if(son[v]-f[v]>max1){
               max2=max1;
               max1=son[v]-f[v];
          }
          else if(son[v]-f[v]>max2){
               max2=son[v]-f[v];
          }
    }
    f[u]=son[u]-1-max1-max2;
    return f[u];
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            cin>>n;
            for(int i=1;i<=n;++i)
                    E[i].clear();
            for(int i=1;i<n;++i){
                   cin>>x>>y;
                   E[x].push_back(y);
                   E[y].push_back(x); 
            }
            int ans=n;
            for(int i=1;i<=n;++i){
                    memset(son,0,sizeof(son));
                    dfs1(i,0);
                    dfs2(i,0);
                  //  if(i==2)cout<<i<<endl;
                  ans=min(ans,f[i]);  
            }
            printf("Case #%d: ",cas);
            printf("%d\n",ans);
    }
    return 0;
}
