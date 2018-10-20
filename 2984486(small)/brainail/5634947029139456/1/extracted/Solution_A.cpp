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
const string INPUT_FILE = "inputA.txt";
const string OUTPUT_FILE = "outputA.txt";

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
int N, L;
vector<string> devicesA, devicesB;
vector<vector<string>> similarity;
vector<vector<int>> g;

vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

// MAIN
int main() {
    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);   

    int nTests;
    scanf("%d\n", &nTests);

    FORN(testIndex, 1, nTests) {
        printf("Case #%d: ", testIndex);
        cin >> N >> L;
        devicesA.resize(N);
        devicesB.resize(N);
        _FORN(i, 0, N) cin >> devicesA [i];
        _FORN(i, 0, N) cin >> devicesB [i];

        similarity.resize(N);
        g.resize(N);

        int result = INF;

        _FORN(i, 0, N) {
            similarity [i].resize(N);
            _FORN(j, 0, N) {
                similarity [i][j] = "";
                _FORN(q, 0, L) {
                    similarity [i][j] += (devicesA [i][q] != devicesB [j][q]) ? '1' : '0';
                }
            }
        }

        _FORN(q, 0, N) {
            _FORN(j, 0, N) g [j].clear();

            int kE = 0;
            _FORN(i, 0, L) kE += similarity [0][q][i] == '1';
            if (kE >= result) continue;

            _FORN(i, 0, N)
                _FORN(j, 0, N)
                    if (similarity [i][j] == similarity [0][q]) {
                        g [i].push_back(j);
                    }

            mt.resize(N);
            used.resize(N);
            mt.assign (N, -1);
            int pp = 0;

	        _FORN(v, 0, N) {
		        used.assign (N, false);
		        pp += try_kuhn (v);
	        }

            if (pp == N) result = kE;
        }

        if (INF != result) {
            printf("%d\n", result);
        } else {
            printf("NOT POSSIBLE\n");
        }
    }

    return 0;
}