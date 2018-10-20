#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int ans,res;
int n;
vector <int> e[1010];
int s[1010];
void dfs(int fu,int u){
    int v,l,i;
    vector <int> a;
    a.clear();
    s[u]=1;
    for (i=0;i<e[u].size();i++){
        v=e[u][i];
        if (fu==v) continue;
        dfs(u,v);
        s[u]+=s[v];
        a.push_back(s[v]);
    }
    l=a.size();
    if (l==1) {res+=a[0];s[u]-=a[0];}
    if (l>2){
        sort(a.begin(),a.end());
        for (i=0;i<l-2;i++){
            res+=a[i];
            s[u]-=a[i];
        }
    }
}
        
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int ca,cc;
    int i,u,v;
    scanf("%d",&ca);
    for (cc=1;cc<=ca;cc++){
        scanf("%d",&n);
        for (i=1;i<=n;i++) e[i].clear();
        for (i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=1000;
        for (i=1;i<=n;i++){
            memset(s,0,sizeof(s));
            res=0;
            dfs(i,i);
            ans=min(ans,res);
        }
        printf("Case #%d: %d\n",cc,ans);
    }
    //while (1);
    return 0;
}
