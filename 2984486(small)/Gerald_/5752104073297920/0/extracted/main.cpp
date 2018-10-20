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

vector<int> gen1(int n){
    vector<int> a(n);
    forn(i, n)
        a[i] = i;
    forn(i, n){
        int pos = rand() % (i + 1);
        swap(a[pos], a[i]);
    }
    return a;
}

vector<int> gen2(int n){
    vector<int> a(n);
    forn(i, n)
        a[i] = i;
    forn(i, n){
        int pos = rand() % n;
        swap(a[pos], a[i]);
    }
    return a;
}

template<typename T>
void out(const vector<T>& a){
    forn(i, sz(a)){
        if(i)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

const int SZM = 3;
const ld M[] = {1, 1, 1};

vector<ld> func(const vector<int>& a){
    vector<ld> w;
    {
        ld x1 = INF;
        ld x2 = 0;
        ld mx = 0, cntmx = 0;
        vector<int> used(sz(a));
        forn(i, sz(a)){
            x2 += ld(a[i] == i);
            if(used[i])
                continue;
            vector<int> x;
            for(int v = i; !used[v]; v = a[v]){
                used[v] = 1;
                x.pb(v);
            }
            x1 = min(x1, (ld)sz(x));
            mx += sz(x), cntmx += 1.0;
        }
        w.pb(x1);
        w.pb(x2);
        w.pb(mx / cntmx);
    }
    assert(sz(w) == SZM);
    forn(i, sz(w)){
        w[i] /= M[i];
    }
    return w;
}


vector<ld> operator + (const vector<ld>& a, const vector<ld>& b){
    vector<ld> ans = a;
    forn(i, sz(b))
        ans[i] += b[i];
    return ans;
}

vector<ld> operator * (const vector<ld>& a, const ld& m){
    vector<ld> ans = a;
    forn(i, sz(a))
        ans[i] *= m;
    return ans;
}

ld dist(const vector<ld>& a, const vector<ld>& b){
    ld sm = 0;
    forn(i, sz(a))
        sm += sqr(a[i] - b[i]);
    return sqrt(sm);
}

#include <fstream>
vector<vector<ld> > cnt;
const ld pm = 1e-3000L;

ld prob(const vector<int>& a){
    ld p = 1;
    forn(i, sz(a)){
        p *= cnt[i][a[i]];
    }
    return p;
}

void test(){
    const int n = 1000;
    const int m = 1000000;
    srand(time(0));
    cnt = vector<vector<ld> >(n, vector<ld>(n));

    /*
    ofstream rout("res.txt");
    forn(iter, m){
        vector<int> q = gen2(n);
        forn(i, sz(q)){
            cnt[i][q[i]] += 1.0;
        }
        if(iter % 10000 == 0)
            cout << iter << endl;
    }
    forn(i, n)
        forn(j, n){
            rout << cnt[i][j] << " ";
        }
    rout.close();
    exit(0);*/
    ifstream rin("res.txt");
    forn(i, n)
        forn(j, n){
            rin >> cnt[i][j];
            cnt[i][j] /= m;
        }
//    cerr << RAND_MAX << endl;

    int cntok = 0;
    const int outans = 120;
    forn(iter, outans){
        vector<int> p = gen1(n);
        vector<int> q = gen2(n);
//        cntok += prob(p) < pm;
        cntok += prob(q) > pm;
    }
    cerr << outans << " " << cntok << endl;
}

void solve_test(){
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, sz(a)){  
        cin >> a[i];
    }
    if(prob(a) < pm)
        puts("GOOD");
    else
        puts("BAD");
}

int main() {
    #ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
//    freopen("output.txt", "wt", stdout);
    #endif

    test();

    int tcases;
    cin >> tcases;
    fori(i, 1, tcases){
        printf("Case #%d: ", i);
        solve_test();
//        fprintf(stderr, "-- Time for case %d = %.3lf\n\n", i, (((double)clock())/CLOCKS_PER_SEC));
    }
    return 0;
}


