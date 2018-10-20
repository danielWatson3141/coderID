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
char s[100];
ll a[200];
ll b[200];
const int inf = 10000;
int n, L;
void read(ll& x) {
    x = 0;
    scanf("%s", s);
    for (int i = 0; i < L; i++) {
        if (s[i] == '1') {
            x |= 1ll << i;
        }
    }
}
int solve(vector<vector<ll> > a, vector<vector<ll> > b, int k) {
    if (k == 0) return 0;
    int n = sz(a);
    vector<vector<ll> > na[2];
    vector<vector<ll> > nb[2];
    bool can[2];
    can[0] = true;
    can[1] = true;
    for (int i = 0; i < n; i++) {
        vector<ll> nna[2];
        vector<ll> nnb[2];
        for (int j = 0; j < sz(a[i]); j++) {
            nna[a[i][j] & 1].pb(a[i][j] >> 1);
            nnb[b[i][j] & 1].pb(b[i][j] >> 1);
        }
        na[0].pb(nna[0]);
        nb[0].pb(nnb[0]);        
        na[0].pb(nna[1]);
        nb[0].pb(nnb[1]);        
        na[1].pb(nna[0]);
        nb[1].pb(nnb[1]);        
        na[1].pb(nna[1]);
        nb[1].pb(nnb[0]);        
        if (sz(nna[0]) != sz(nnb[0]) || sz(nna[1]) != sz(nnb[1])) {
            can[0] = false;
        }
        if (sz(nna[0]) != sz(nnb[1]) || sz(nna[1]) != sz(nnb[0])) {
            can[1] = false;
        }
    }
    int res = inf;
    if (can[0]) {
        res = min(res, solve(na[0], nb[0], k - 1));
    }
    if (can[1]) {
        res = min(res, solve(na[1], nb[1], k - 1) + 1);
    }
    return res;
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
        scanf("%d %d", &n, &L);
        vector<ll> a, b;
        for (int i = 0; i < n; i++) {
            ll x;
            read(x);
            a.pb(x);
        }
        for (int i = 0; i < n; i++) {
            ll x;
            read(x);
            b.pb(x);
        }
        vector<vector<ll> > a0;
        a0.pb(a);
        vector<vector<ll> > b0;
        b0.pb(b);
        int res = solve(a0, b0, L);
        if (res == inf) {
            printf("NOT POSSIBLE\n");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}
