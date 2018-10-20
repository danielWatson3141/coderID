#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int inf = 0x7fffffff;
int t, ct;
int n, cur;
vector<int> V[2000];
#define pb push_back
int cap[2000];
bool vis[2000];
void dfs(int x){
    cap[x]=1;
    int ch=0;
    int a, b;
    a = b = -1;
    for(int i=0; i<V[x].size(); i++){
        int j=V[x][i];
        if(vis[j])  continue;
        ch++;
        vis[j]=1;
        dfs(j);
        cap[x]+=cap[j];
        if(a==-1)   a=j;
        else if(b==-1){
            b=j;
            if(cap[b]>cap[a])   swap(a,b);
        }
        else{
            if(cap[j]>cap[b])   b=j;
            if(cap[b]>cap[a])   swap(a,b);
        }
    }
    if(ch==0)   return;
    if(ch==1){
        cur += cap[x]-1;
        cap[x]=1;
    }
    else if(ch>2){
        cur += cap[x];
        cap[x]=1;
        for(int i=0; i<V[x].size(); i++){
            int j=V[x][i];
            if(j==a){
                cap[x]+=cap[j];
            }
            if(j==b){
                cap[x]+=cap[j];
            }
        }
        cur -= cap[x];
    }
}
int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) V[i].clear();
        int x, y;
        for(int i=1; i<n; i++){
            scanf("%d %d", &x, &y);
            V[x].pb(y);
            V[y].pb(x);
        }
        int ans = inf;
        for(int i=1; i<=n; i++){
            cur=0;
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            dfs(i);
            ans = min(ans, cur);
        }
        printf("Case #%d: %d\n", ct, ans);
    }
    return 0;
}
