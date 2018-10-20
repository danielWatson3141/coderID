#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define ll long long
using namespace std;

int n;
vector<int> a[1005];
int sum[1005],d[1005];
void init(int u,int f){
    sum[u]=1;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(v==f) continue;
        init(v,u);
        sum[u]+=sum[v];
    }
}
void dfs(int u,int f){
    int son=0;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(v==f) continue;
        dfs(v,u);
        son++;
    }
    if(son==0) d[u]=0;
    else if(son==1){
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i];
            if(v==f) continue;
            d[u] = sum[v];
        }
    }else if(son==2){
        d[u]=0;
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i];
            if(v==f) continue;
            d[u] += d[v];
        }
    }else{
        int p1=0,p2=0;
        d[u]=0;
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i];if(v==f) continue;
            d[u]+=sum[v];
            int temp = d[v]-sum[v];
            if(temp<p1) p2=p1,p1=temp;
            else if(temp<p2) p2=temp;
        }
        d[u]+=p1+p2;
    }
}
int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int ans=n+1;
        for(int i=1;i<=n;i++){
            init(i,i);
            dfs(i,i);
            ans = min(ans,d[i]);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}

