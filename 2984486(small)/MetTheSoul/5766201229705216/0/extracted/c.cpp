#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define mp make_pair
#define pb push_back
#define snuke(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it ++)
typedef long long lld;
typedef pair<int,int> PII;


const int N = 1010,INF = 0x3f3f3f3f;
vector<int> G[N];
int n,sz[N],cost[N];

void dfs(int u,int fa) {
        sz[u] = 1;
        int mx1 = -1,mx2 = -1;
        snuke(it,G[u]) {
                int v = *it;
                if (v==fa) continue;
                dfs(v,u);
                sz[u] += sz[v];
                int tmp = sz[v]-cost[v];
                if (tmp>mx2) {
                        mx2 = tmp;
                        if (mx2>mx1) {
                                swap(mx2,mx1);
                        }
                }
        }
        cost[u] = min(sz[u]-1,sz[u]-1-mx1-mx2);
        if (mx2==-1) {
                cost[u] = sz[u]-1;
        }
}

int main(int argc,char **argv) {
        if (argc>1) {
                freopen(argv[1],"r",stdin);
                freopen("out.txt","w",stdout);
        }
        int cas,ca = 0;
        scanf("%d",&cas);
        while (cas--) {
                scanf("%d",&n);
                for (int i = 0; i < n; i ++) {
                        G[i].clear();
                }
                for (int i = 0; i < n-1; i ++) {
                        int a,b;
                        scanf("%d%d",&a,&b); a --; b --;
                        G[a].pb(b);
                        G[b].pb(a);
                }
                int ans = INF;
                for (int i = 0; i < n; i ++) {
                        dfs(i,-1);
                        ans = min(ans,cost[i]);
                }
                printf("Case #%d: %d\n",++ca,ans);
        }
        return 0;
}
