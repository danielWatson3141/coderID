
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 1005;
const int INF = 0x3f3f3f3f;
int n;
vector<int> V[N];

bool vis[N];
int son[N], cnt[N];
void DFS(int root) {
    vis[root] = 1;
    son[root] = 1;
    cnt[root] = 1;
    int num = V[root].size();
    int p = 0, q = 0;
    for (int i = 0; i < num; i++) {
        int v = V[root][i];
        if (!vis[v]) {
            DFS(v);
            son[root] += son[v];
            p = max(p, cnt[v]);
            if(p > q) {
                p = p^q;
                q = q^p;
                p = p^q;
            }
        }
    }
    if (p != 0) {
        cnt[root] += p + q;
    }
}

int main () {
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    for (int cas = 1; cas <= cases; cas++) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            V[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf ("%d %d", &u, &v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        printf("Case #%d: ", cas);
        int ans = INF;
        for (int i = 1; i <= n; i++) {
//            memset(vis, 0, sizeof(vis));
//            memset(cnt, 0, sizeof(cnt));
//            memset(son, 0, sizeof(son));
            for (int j = 1; j <= n; j++) {
                vis[j] = 0;
                cnt[j] = 0;
                son[j] = 0;
            }
            DFS(i);
            ans = min(ans, n - cnt[i]);
        }
        cout<<ans<<endl;
    }






    return 0;
}
