// Author: QCC
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <utility>
#include <bitset>
#include <memory.h>
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define read(a) scanf("%d", &(a))
#define write(a) printf("%d ", a);

using namespace std;

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }


typedef pair< int, int > pii;
typedef long long LL;

//const int MAXINT = 2147483647;
//const LL MAXLL = (long long)9223372036854775807;

int n, l;
int nTest;
vector<string> a, b;
map<string, int> myMap;
int cntA[55][3], cntB[55][3];
int res;
bool tt[55];
int found;

void check() {
    //cout << " ok ";
    int cntStep = 0;
    FOR(j, 0, l-1)
        if (tt[j]) {
            cntStep++;
            FOR(i, 0, n-1)
                if (a[i][j] == '0') a[i][j] = '1';
                else
                    a[i][j] = '0';
        }
    myMap.clear();
    FOR(i, 0, n-1)
        myMap[a[i]]++;
    int cnt = 0;
    FOR(j, 0, l-1)
        if (tt[j]) {
            //cntStep++;
            FOR(i, 0, n-1)
                if (a[i][j] == '0') a[i][j] = '1';
                else
                    a[i][j] = '0';
        }
    FOR(i, 0, n-1)
        if (myMap[b[i]] > 0) cnt++;
    //cout << cntStep << " " << cnt << endl;
    if (cnt == n) res = min(res, cntStep);
}

void attempt(int i) {
    if (found == -1) return;
    if (i == l) {
        check();
        return;
    }
    //cout << i << " " << cntA[i][0] << " " << cntA[i][1] << " " << cntB[i][0] << " " << cntB[i][1] << endl;
    if (cntA[i][0] == cntB[i][0] && cntA[i][1] == cntB[i][1] && cntA[i][0] != cntA[i][1])
        attempt(i+1);
    else if (cntA[i][1] == cntB[i][0] && cntA[i][0] == cntB[i][1] && cntA[i][0] != cntA[i][1]) {
            tt[i] = true;
            attempt(i+1);
            tt[i] = false;
        }
        else if (cntA[i][1] == cntB[i][1] && cntA[i][0] == cntB[i][0] && cntA[i][0] == cntA[i][1]) {
            tt[i] = false;
            attempt(i+1);
            tt[i] = true;
            attempt(i+1);
        }
        else {
            found = -1;
            return;
        }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &nTest);
    FOR(test, 1, nTest) {
        scanf("%d %d\n", &n, &l);
        a.clear();
        b.clear();
        myMap.clear();
        FOR(i, 1, n) {
            string s;
            cin >> s;
            a.pb(s);
        }
        scanf("\n");
        FOR(i, 1, n) {
            string s;
            cin >> s;
            b.pb(s);
        }
        scanf("\n");
        for(int i = 0; i < l; i++) {
            cntA[i][0] = 0;
            cntA[i][1] = 0;
            FOR(j, 0, n-1)
                cntA[i][a[j][i] - '0']++;
        }
        for(int i = 0; i < l; i++) {
            cntB[i][0] = 0;
            cntB[i][1] = 0;
            FOR(j, 0, n-1)
                cntB[i][b[j][i] - '0']++;
        }
        res = 1111111;
        memset(tt, false, sizeof(tt));
        found = 0;
        attempt(0);
        printf("Case #%d: ", test);
        if (found == -1) cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }
    return 0;
}

