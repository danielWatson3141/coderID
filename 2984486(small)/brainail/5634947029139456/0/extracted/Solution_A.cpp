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

        int result = INF;

        _FORN(mask, 0, TWOP(L)) {
            int kbit_one = 0;
            vector<string> devices(N), devicesC(N);
            _FORN(i, 0, N) devices [i] = devicesA [i];
            _FORN(i, 0, N) devicesC [i] = devicesB [i];

            FORN(bit, 0, L - 1) {
                if (CONTAINB(mask, bit)) {
                    ++ kbit_one;
                    _FORN(i, 0, N) {
                        devices [i][bit] = devices [i][bit] == '0' ? '1' : '0';
                    }
                }
            }

            sort(ALL(devices));
            sort(ALL(devicesC));

            _FORN(i, 0, N) {
                if (devices [i] != devicesC [i]) {
                    kbit_one = INF;
                }
            }

            if (kbit_one < result) {
                result = kbit_one;
            }
        }

        if (INF != result) {
            printf("%d\n", result);
        } else {
            printf("NOT POSSIBLE\n");
        }
    }

    return 0;
}