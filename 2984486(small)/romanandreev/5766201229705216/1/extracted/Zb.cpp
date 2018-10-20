#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n;
vector<int> g[1010];
int dp1[1010][1010];
int dp2[1010][1010];
int x[1010];
int y[1010];

void calc(int v1, int v2) {
    if (dp1[v1][v2] != -1) {
        return;
    }
    dp1[v1][v2] = 1;
    for (int i = 0; i < sz(g[v2]); i++) {
        int v3 = g[v2][i];
        if (v3 != v1) {
            calc(v2, v3);
            dp1[v1][v2] += dp1[v2][v3];
        }
    }
}
void calc2(int v1, int v2) {
    if (dp2[v1][v2] != -1) {
        return;
    }
    int sum = dp1[v1][v2] - 1;
    dp2[v1][v2] = sum;    
    vector<int> ls;
    for (int i = 0; i < sz(g[v2]); i++) {
        int v3 = g[v2][i];
        if (v3 != v1) {
            calc2(v2, v3);
            ls.pb(dp2[v2][v3] - dp1[v2][v3]);
        }
    }
    sort(all(ls));
    if (sz(ls) >= 2) {
        dp2[v1][v2] = min(dp2[v1][v2], sum + ls[0] + ls[1]);
    }
}
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp1[i][j] = -1;
                dp2[i][j] = -1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &x[i], &y[i]);
            x[i]--,y[i]--;
            g[x[i]].pb(y[i]);
            g[y[i]].pb(x[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            calc(x[i], y[i]);
            calc(y[i], x[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            calc2(x[i], y[i]);
            calc2(y[i], x[i]);
        }
        int ans = n - 1;
        for (int i = 0; i < n; i++) {
            int val = 0;
            vector<int> ls;
            for (int j = 0; j < sz(g[i]); j++) {
                ls.pb(dp2[i][g[i][j]] - dp1[i][g[i][j]]);
                val += dp1[i][g[i][j]];
            }
            sort(all(ls));
            if (sz(ls) >= 2)
            ans = min(ans, val + ls[0] + ls[1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
