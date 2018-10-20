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
int res, cnt;
int found;

void change(int i) {
    for (int j = 0; j < n; j++)
        if (a[j][i] == '0') a[j][i] = '1';
        else a[j][i] = '0';
}

bool same(int i, int s) {
    for (int j = 0; j <= s; j++)
        if (a[i][j] != b[i][j]) return false;
    return true;
}

void attempt(int i) {
    if (i == l) {
        res = min(res, cnt);
        return;
    }
    FOR(j, 0, 1) {
        if (j == 1) {
            change(i);
            cnt++;
        }
        sort(a.begin(), a.end());
        bool tt = false;
        FOR(k, 0, n-1)
            if (!same(k, i)) {
                tt = true;
                break;
            }
        if (!tt) attempt(i+1);
        if (j == 1) {
            change(i);
            cnt--;
        }
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
        sort(b.begin(), b.end());
        cnt = 0;
        res = 1111111;
        attempt(0);
        printf("Case #%d: ", test);
        if (res == 1111111) cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }
    return 0;
}

