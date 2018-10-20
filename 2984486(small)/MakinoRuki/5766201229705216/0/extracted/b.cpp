#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 20
using namespace std;
int T,n;
vector<int>E[N];
int x,y;
int vis;
int bits(int s){
    int cnt=0;
    while(s){
             if(s&1)cnt++;
             s/=2;
    }
    return cnt;
}
bool dfs(int u, int f, int st){
     vis|=(1<<(u-1));
     int num=0;
     for(int i=0;i<E[u].size();++i){
             int v=E[u][i];
             if(v==f)continue;
             if((1<<(v-1))&st)continue;
             num++;
     }
     if(num!=0 && num!=2)return false;
     if(num==0)return true;
     if(num==2){
                bool ok=true;
                for(int i=0;i<E[u].size();++i){
                        int v=E[u][i];
                        if(v==f)continue;
                        if((1<<(v-1))&st)continue;
                        if(!dfs(v,u,st)){
                                         ok=false;
                                         break;
                        }
                }
                return ok;
     }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
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
            for(int i=0;i<(1<<n);++i){
                    int r;
                    for(r=1;r<=n;++r){
                            int rr=r-1;
                            if((1<<rr)&i)continue;
                            vis=0;
                            if(dfs(r,0,i) && ((vis^i)==((1<<n)-1))){
                               break;}
                    }
                    if(r<=n){
                          //   if(bits(i)==1)cout<<i<<" "<<r<<endl;
                            ans=min(ans,bits(i));}
            }
            printf("Case #%d: ",cas);
            printf("%d\n",ans);
    }
    return 0;
}
