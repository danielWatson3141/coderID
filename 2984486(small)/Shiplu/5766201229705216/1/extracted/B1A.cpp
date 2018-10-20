#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64
typedef pair<int,int> pii;

int child[1005],r[1005];
vector<int> adj[1005];
void dfs(int u,int p){
    int i,v,sz = adj[u].size();
    child[u] = 1;
    for(i = 0;i<sz;i++){
        v = adj[u][i];
        if(v == p) continue;
        dfs(v,u);
        child[u]+=child[v];
    }
}
int dfs2(int u,int p){
    int i,v,sz = adj[u].size();
    int ret = 0;
    vector<pii> a;
    for(i = 0;i<sz;i++){
        v = adj[u][i];
        if(v == p) continue;
        r[v] = dfs2(v,u);
        a.pb(pii(r[v] - child[v],v));
    }
    sort(all(a));
    if(a.size() == 0) return 0;
    if(a.size() == 1) return child[a[0].second];
    ret = r[a[0].second]+r[a[1].second];
    for(i = 2;i<a.size();i++){
        ret += child[a[i].second];
    }

    return ret;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,cs = 1,i,x,y,N,L,ans;

    cin>>t;
    while(t--){
        cin>>N;
        for(i = 0;i<=N;i++){
            adj[i].clear();
        }
        for(i = 0;i<N - 1;i++){
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ans = inf;
        for(i = 1;i<=N;i++){
            dfs(i,0);
            L = dfs2(i,0);
            ans = min(L,ans);
        }
        printf("Case #%d: %d\n",cs++,ans);

    }
	return 0;
}
