#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T,n,l;
int p[12];
vector<string>a,b;
string s;
int ans;
bool vis[12];
void dfs(int cur, int st, int res){
     if(cur==n){
             //   cout<<st<<endl;
               ans=min(ans,res);
               return ;
     }
     for(int i=0;i<n;++i){
             if(!vis[i]){
                  vis[i]=true;
                  if(cur==0){
                             st=0;
                             int cnt=0;
                      for(int j=0;j<l;++j)
                              if(b[cur][j]!=a[i][j]){
                                  st|=(1<<j);
                                  cnt++;
                              }
                         //     cout<<cur<<" "<<i<<st<<endl;
                      dfs(cur+1,st,cnt);
                  }
                  else{
                       int j;
                       for(j=0;j<l;++j){
                            if(b[cur][j]!=a[i][j]){
                                if((1<<j)&st)continue;
                                break;
                            }
                            else {
                                 if((1<<j)&st)break;
                            }
                       }
                //       cout<<cur<<" "<<i<<endl;
                       if(j>=l)dfs(cur+1,st,res);
                  }
                  vis[i]=false;
             }
     }
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            cin>>n>>l;
            a.clear();
            b.clear();
            for(int i=0;i<n;++i)
                    p[i]=i;
            for(int i=0;i<n;++i){
                    cin>>s;
                    a.push_back(s);
            }
            for(int i=0;i<n;++i){
                    cin>>s;
                    b.push_back(s);
            }
            ans=l+1;
            memset(vis,false,sizeof(vis));
            dfs(0,0,0);
            printf("Case #%d: ",cas);
            if(ans==l+1)
                printf("NOT POSSIBLE\n");
            else 
                 printf("%d\n",ans);       
    }
    return 0;
}
