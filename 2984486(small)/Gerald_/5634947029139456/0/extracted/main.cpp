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

int n, m;

const int NMAX = 200;
vector<int> g[NMAX];

int p[NMAX], used[NMAX], fused;

int go(int v){
    if(used[v] == fused)
        return 0;
    used[v] = fused;
    forn(i, sz(g[v])){
        int u = g[v][i];
        if(p[u] == -1 || go(p[u])){
            p[u] = v;
            return 1;
        }
    }
    return 0;
}

int match(){
    fused = 1;
    memset(used, 0, sizeof used);
    memset(p, -1, sizeof p);
    int ans = 0;
    forn(i, NMAX){
        fused++;
        ans += go(i);
    }
    return ans;
}

int bits(const string& s){
    int ans = 0;
    forn(i, sz(s))
        ans += s[i] == '1';
    return ans;
}

void solve_test(){
    cin >> n >> m;
    vector<string> a(n), b(n);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
    }

    vector<vector<string> > dif(n, vector<string>(n));
    set<string> vals;
    forn(i, n){
        forn(j, n){
            dif[i][j].resize(m, '0');
            forn(k, m){
                if(a[i][k] == b[j][k])
                    dif[i][j][k] = '0';
                else
                    dif[i][j][k] = '1';
            }
            vals.insert(dif[i][j]);
        }
    }

    /*
    forn(i, n){
        forn(j, n){
            cout << dif[i][j] << " ";
        }
        cout << endl;
    }*/

    int ans = INF;
    forit(vit, vals){
        forn(i, NMAX)
            g[i].clear();
        forn(i, n)
            forn(j, n)
                if(dif[i][j] == *vit){
                    g[i].pb(j);
                }
        if(match() == n)
            ans = min(ans, bits(*vit));
    }

    if(ans == INF)
        puts("NOT POSSIBLE");
    else{
        cout << ans << endl;
    }
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


