#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1010;

vector<int> adj[MAXN];
int qchild[MAXN];

int calc(int v,int prev) {
    int ret = 1;
    for(int nxt: adj[v])
        if(nxt != prev)
            ret += calc(nxt,v);
    return qchild[v] = ret;
}

int go(int v,int prev) {
    int ret = qchild[v]-1;
    int hi1 = -INF, hi2 = -INF;
    int q = 0;
    for(int nxt: adj[v]) {
        if(nxt == prev) continue;
        q++;
        int got = qchild[nxt]-go(nxt,v);
        if(got >= hi1) {
            hi2 = hi1;
            hi1 = got;
        }
        else if(got > hi2) hi2 = got;
    }
    if(q < 2) return ret;
    return ret-(hi1 + hi2);
}    

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        printf("Case #%d: ",t);
        int n;
        scanf("%d",&n);
        for(int a=1;a<=n;++a) adj[a].clear();
        for(int a=1;a<n;++a) {
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INF;
        for(int a=1;a<=n;++a) {
            calc(a,-1);
            ans = min(ans,go(a,-1));
        }
        printf("%d\n",ans);
    }        
    return 0;
}
