// INCLUDES
#include <functional>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cmath>
#include <ctime>

#include <numeric>
#include <iomanip>
#include <complex>
#include <float.h>
#include <cfloat>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdio>

#include <cstring>
#include <string>

#include <iterator>
#include <vector>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

// TYPEDEFS
typedef long long LL;
typedef long double LD;         
typedef unsigned long UL;
typedef vector < int > VI;
typedef vector < string > VS;
typedef vector < long long > VLL;
typedef vector < long double > VLD;

// DEFINES
#define FORN(i, st, en) for(int i = (int) (st); i <= (int) (en); ++ i)
#define FORDN(i, en, st) for(int i = (int) (en); i >= (int) (st); -- i)
#define FORN_(i, st, en) for(int i = (int) (st); i <= (int) (en); i += 2)
#define FORDN_(i, en, st) for(int i = (int) (en); i >= (int) (st); i -= 2)
#define _FORN(i, st, en) for(int i = (int) (st); i < (int) (en); ++ i)
#define _FORDN(i, en, st) for(int i = (int) (en); i > (int) (st); -- i)
#define _FORN_(i, st, en) for(int i = (int) (st); i < (int) (en); i += 2)
#define _FORDN_(i, en, st) for(int i = (int) (en); i > (int) (st); i -= 2)
#define FILL(a, w) memset(a, w, sizeof(a))
#define ALL(A) A.begin(), A.end()
#define SIZE(X) ((int) (X.size()))
#define LENGTH(X) ((int) (X.length()))
#define MP(X, Y) make_pair(X, Y)
#define TWOP(X) (1<<(X))
#define TWOLP(X) (((LL)(1))<<(X))
#define CONTAINB(MASK, X) (((MASK) & TWOP(X)) != 0)
#define CONTAINLB(MASK, X) (((MASK) & TWOLP(X)) != 0)
#define MSG(X) cout << #X << " = " << X << endl;

// CONSTS
const LD PI = acos(-1.0);
const LD EPS = 1e-7;
const int INF = 1000000000;
const LL INFL = (LL) 1000000000 * (LL) 1000000000;
const string INPUT_FILE = "inputB.txt";
const string OUTPUT_FILE = "outputB.txt";

template<class T> inline T gcd(T A, T B)	{
    if (A < 0) return gcd(-A, B); 
    if (B < 0) return gcd(A, -B);
    return (B == 0) ? A : gcd(B, A % B);
}

template<class T> inline T lcm(T A, T B) {
    if (A < 0) return lcm(-A, B);
    if (B < 0) return lcm(A, -B);
    return A * (B / gcd(A, B));
}

// MY
int N;
vector<vector<int>> tree;

int find_kvertex(int v, int p = -1) {
    if (0 == tree [v].size()) return 1;
    if (1 == tree [v].size() && tree [v][0] == p) return 1;

    int kvertex = 1;

    _FORN(i, 0, tree [v].size()) {
        if (tree [v][i] != p) {
            kvertex += find_kvertex(tree [v][i], v);
        }
    }

    return kvertex;
}

int find_deleted(int v, int p = -1) {
    if (0 == tree [v].size()) return 0;
    if (1 == tree [v].size() && tree [v][0] == p) return 0;
    int v_deleted = 0;
    
    bool useless_deleted = (1 == tree [v].size() && p == tree [v][0]);
    useless_deleted = useless_deleted || (0 == tree [v].size());
    useless_deleted = useless_deleted || (2 == tree [v].size() && p < 0);
    useless_deleted = useless_deleted || (3 == tree [v].size() && (tree [v][0] == p || tree [v][1] == p || tree [v][2] == p));

    vector<int> min_z(2, -INF);
    vector<int> min_v(2, -1);

    if (!useless_deleted) {
        int vk = 0;

        _FORN(i, 0, tree [v].size()) {
            if (tree [v][i] != p) {
                int k = find_kvertex(tree [v][i], v);
                vk += k;

                if (k >= min_z [0]) {
                    min_z [1] = min_z [0];
                    min_v [1] = min_v [0];
                    min_z [0] = k;
                    min_v [0] = tree [v][i];
                } else if (k > min_z [1]) {
                    min_z [1] = k;
                    min_v [1] = tree [v][i];
                }
            }
        }

        if (min_v [1] >= 0) {
            _FORN(i, 0, tree [v].size()) {
                if (tree [v][i] != p && (tree [v][i] == min_v [0] || tree [v][i] == min_v [1])) {
                    v_deleted += find_deleted(tree [v][i], v);
                }
            }

            vk -= min_z [0];
            vk -= min_z [1];
        }

        v_deleted += vk;
    } else {
        _FORN(i, 0, tree [v].size()) {
            if (tree [v][i] != p) {
                v_deleted += find_deleted(tree [v][i], v);
            }
        }
    }

    return v_deleted;
}

// MAIN
int main() {
    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);   

    int nTests;
    scanf("%d", &nTests);

    FORN(testIndex, 1, nTests) {
        printf("Case #%d: ", testIndex);
        
        scanf("%d", &N);
        
        tree.resize(N);
        _FORN(v, 0, N) tree [v].clear();

        _FORN(i, 0, N - 1) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            -- X, --Y;
            tree [X].push_back(Y);
            tree [Y].push_back(X);
        }

        int result_deleted = INF;
        _FORN(i, 0, N) {
            int v_deleted = find_deleted(i);
            result_deleted = min(result_deleted, v_deleted);
        }

        printf("%d\n", result_deleted);
    }

    return 0;
}