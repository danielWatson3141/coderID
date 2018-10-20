#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1000 + 10;
const int inf = 1e9;


vector < int > e[maxn];
bool use[maxn];
int res;
/*int dist[maxn];
queue < int > q;

void bfs(int st) {
    int v;
    memset(dist, 63, sizeof(dist));
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < (int)e[v].size(); i++)
            if (dist[e[v][i]] > dist[v] + 1) {
                dist[e[v][i]] = dist[v] + 1;
                q.push(e[v][i]);
            }
    }
}
*/

int dfs(int v) {
    int r1 = 0, r2 = 0, tmp, sum = 0;
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (!use[e[v][i]]) {
            tmp = dfs(e[v][i]);
            sum += tmp;
            if (tmp > r2) swap(tmp, r2);
            if (r2 > r1) swap(r2, r1);
        }
    //epr("v r1 r2 sum: %d %d %d %d\n", v, r1, r2, sum);
    if (r1 != 0 && r2 != 0) {
        res += sum - (r1 + r2);
        return r1 + r2 + 1;
    }
    res += sum;
    return 1;
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
     freopen("out", "w", stdout);
#endif
    int tt;
    int n, v, u;
    scanf("%d", &tt);
    for (int ttt = 0; ttt < tt; ttt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            e[i].clear();
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &v, &u); v--; u--;
            e[v].pb(u);
            e[u].pb(v);
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            memset(use, 0, sizeof(use));
            res = 0;
            dfs(i);
            ans = min(ans, res);
        }
        //cerr << "n ans: " << n << " " << ans << endl;
        printf("Case #%d: %d\n", ttt + 1, ans);
    }



    return 0;
}

