#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

const int N = 1010;
const int E = N*2;

int h[N], el, nxt[E], v[E];

void initEdge() {
    clr(h, -1); el = 0;
}

void addEdge(int x, int y) {
    v[el] = y;
    nxt[el] = h[x];
    h[x] = el++;
}

int dp[N];

void dfs(int x, int f) {
    int m1 = -1;
    int m2 = -1;
    for(int i=h[x]; ~i; i=nxt[i]) {
        int y = v[i];
        if(y == f) continue;
        dfs(y, x);
        if(m1 < dp[y]) {
            m2 = m1;
            m1 = dp[y];
        } else if(m2 < dp[y]) {
            m2 = dp[y];
        }
    }
    if(m2 == -1) dp[x] = 1;
    else dp[x] = m1 + m2 + 1;
}

int main() {

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

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
        clr(dp, 0x3f);
        for(int i=1; i<=n; i++) {
            dfs(i, -1);
            ans = min(ans, n - dp[i]);
        }
        cout<<"Case #"<<++cas<<": "<<ans<<endl;
    }

    return 0;
}
