#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

vector<int> adj[1005];
int cache[1005];
int sz[1005];

int size(int i, int p=-1) {
    if (sz[i] != -1) return sz[i];
    else {
        sz[i] = 1;
        FO(j,0,adj[i].size()) if (adj[i][j] != p)
            sz[i] += size(adj[i][j], i);
        return sz[i];
    }
}

int dp(int i, int p=-1) {
    if (cache[i] != -1) return cache[i];
    int ss = 0;
    FO(j,0,adj[i].size()) if (adj[i][j] != p) ss += sz[adj[i][j]];
    //printf("dp %d, ss=%d\n", i, ss);
    int c0 = 1e5, c1 = 1e5;
    FO(j,0,adj[i].size()) if (adj[i][j] != p) {
        int dv = dp(adj[i][j],i) - sz[adj[i][j]];
        if (dv < c0) {
            c1 = c0;
            c0 = dv;
        } else if (dv < c1) {
            c1 = dv;
        }
    }
    return cache[i] = min(ss, ss+c0+c1);
}

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,1,T+1) {
        printf("Case #%d: ", Z);
        FO(i,0,1005) adj[i].clear();
        int n;
        scanf("%d", &n);
        FO(i,0,n-1) {
            int x,y;
            scanf("%d %d", &x, &y);
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }

        int res = 1e9;
        FO(i,0,n) {
            memset(cache, -1, sizeof cache);
            memset(sz, -1, sizeof sz);
            size(i);
            //FO(i,0,n) printf("sz[%d]=%d\n", i, sz[i]);
            res = min(res, dp(i));
        }

        printf("%d\n", res);
done:;
    }

    return 0;
}

