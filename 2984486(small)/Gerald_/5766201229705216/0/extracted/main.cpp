#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif
#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define forit(i, a) for(typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 1100;

int n;
vector<int> g[NMAX];

int d[NMAX], cnt[NMAX];

void dfs(int v, int pv){
    cnt[v] = 1;
    forn(i, sz(g[v])){
        int u = g[v][i];
        if(u == pv)
            continue;
        dfs(u, v);
        cnt[v] += cnt[u];
    }
}

int solve(int v, int pv){
    int& ans = d[v];
    if(ans == -1){
        ans = cnt[v] - 1;

        vector<int> x;
        forn(i, sz(g[v])){
            int u = g[v][i];
            if(pv == u)
                continue;
            x.pb(solve(u, v) - cnt[u]);
        }
        sort(all(x));

        if(sz(x) > 1){
            ans = min(ans, (cnt[v] - 1) + x[0] + x[1]);
        }
    }
    return ans;
}

void solve_test(){
    forn(i, NMAX)
        g[i].clear();
    cin >> n;
    forn(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int ans = INF;

    forn(r, n){
        memset(d, -1, sizeof d);
        memset(cnt, 0, sizeof cnt);
        dfs(r, -1);
        ans = min(ans, solve(r, -1));
    }

    cout << ans << endl;
}

int main() {
    #ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
//    freopen("output.txt", "wt", stdout);
    #endif

    int tcases;
    cin >> tcases;
    fori(i, 1, tcases){
        printf("Case #%d: ", i);
        solve_test();
//        fprintf(stderr, "-- Time for case %d = %.3lf\n\n", i, (((double)clock())/CLOCKS_PER_SEC));
    }

    return 0;
}


