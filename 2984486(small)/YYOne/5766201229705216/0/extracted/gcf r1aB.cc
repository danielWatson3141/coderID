#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

const int N = 20;
const int E = N*2;

int h[N], el, nxt[E], v[E];

bool ban[N];
bool vis[N];

void initEdge() {
    clr(h, -1); el = 0;
}

void addEdge(int x, int y) {
    v[el] = y;
    nxt[el] = h[x];
    h[x] = el++;
}

bool dfs(int x, int f) {
    int cnt = 0;
    vis[x] = true;
    for(int i=h[x]; ~i; i=nxt[i]) {
        if(v[i] != f && !ban[v[i]]) {
            if(!dfs(v[i], x)) {
                return false;
            }
            ++ cnt;
        }
    }
    if(cnt != 0 && cnt != 2) return false;
    else return true;
}

int main() {

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    ios::sync_with_stdio(false);
    int T; cin>>T;
    int cas(0);
    while(T--) {
        int n; cin>>n;
        initEdge();
        for(int i=1; i<n; i++) {
            int x, y; cin>>x>>y;
            addEdge(x, y);
            addEdge(y, x);
        }
        int ans = 0x3f3f3f3f;
        for(int i=0; i<(1<<n); i++) {
            int tmp = 0;
            for(int j=0; j<n; j++) {
                if(i&(1<<j)) {
                    ++ tmp;
                    ban[j+1] = true;
                } else {
                    ban[j+1] = false;
                }
            }
            for(int j=1; j<=n; j++) {
                clr(vis, 0);
                if(dfs(j, -1)) {
                    bool can = true;
                    for(int i=1; i<=n; i++) {
                        if(!ban[i] && !vis[i]) {
                            can = false;
                        }
                    }
                    if(can) ans = min(ans, tmp);
                }
            }
        }
        cout<<"Case #"<<++cas<<": "<<ans<<endl;
    }

    return 0;
}
