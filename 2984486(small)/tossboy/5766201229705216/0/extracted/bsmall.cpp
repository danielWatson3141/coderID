#include <iostream>
#include <vector>
using namespace std;

const int N=1000+5;
int n,src,num[N];
vector<int> g[N];

int build(int u, int f){
    num[u] = 1;
    for(int i=0; i<g[u].size(); i++)
        if(g[u][i]!=f)
            num[u] += build(g[u][i],u);
    return num[u];
}

int dfs(int u, int f){
    int res=1;
    int t[N],l=0;
    for(int i=0; i<g[u].size(); i++)
        if(g[u][i]!=f){
            t[l++] = dfs(g[u][i],u);
        }
    if(l<=1) return res;
    
    sort(t, t+l);
    return res+t[l-1]+t[l-2];
}

int main(int argc, const char * argv[])
{
    int ncase; cin>>ncase;
    for(int ca=1; ca<=ncase; ca++){
        cin>>n;
        for(int i=1; i<=n; i++) g[i].clear();
        for(int i=1; i<=n-1; i++){
            int a,b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int res=0;
        for(int i=1; i<=n; i++){
            src=i;
            for(int j=1; j<=n; j++) num[i]=0;
            build(src, -1);
            res = max(res, dfs(src,-1));
        }
        cout<<"Case #"<<ca<<": "<<n-res<<endl;
    }
    return 0;
}

