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

int n;
int nTest;
vector<int> e[1111];
int nChild[1111];
int sumChild[1111];
int res;
bool visited[1111];
int f[1111];
int parrent[1111];
int tmp[1111][1111];
int nTmp[1111];

void dfs1(int u) {
    visited[u] = true;
    bool tt = false;
    nTmp[u] = 0;
    int saveV = 0;
    for(int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (visited[v] == false) {
            //cout << "edge " << u << " " << v << endl;
            parrent[v] = u;
            dfs1(v);
            sumChild[u] += sumChild[v];
            nTmp[u]++;
            tmp[u][nTmp[u]] = f[v] - sumChild[v];
            //cout << "update tmp " << u << " " << v << " " << nTmp[u] << " " << tmp[u][nTmp[u]] << endl;
            tt = true;
            saveV = v;
        }
    }
    if (tt == false) {
        f[u] = 0;
        sumChild[u] = 1;
        //cout << "   " << u << " " << f[u] << " " << sumChild[u] << endl;
        return;
    }
    sort(tmp[u]+1, tmp[u]+nTmp[u]+1);
    //cout << "     " << nTmp[u] << " " << tmp[u][1] << " " << tmp[u][2] << endl;
    if (nTmp[u] >= 2)
        f[u] = sumChild[u] + tmp[u][1] + tmp[u][2];
    else
        f[u] = sumChild[saveV];
    sumChild[u]++;
    //cout << "   " << u << " " << f[u] << " " << sumChild[u] << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &nTest);
    FOR(test, 1, nTest) {
        scanf("%d", &n);
        FOR(i, 1, n)
            e[i].clear();
        FOR(i, 1, n-1) {
            int u, v;
            scanf("%d %d", &u, &v);
            e[u].pb(v);
            e[v].pb(u);
        }
        res = 1000000;
        FOR(root, 1, n) {
            memset(visited, false, sizeof(visited));
            memset(sumChild, 0, sizeof(sumChild));
            memset(nChild, 0, sizeof(nChild));
            memset(f, 0, sizeof(f));
            dfs1(root);
            //cout << f[root] << endl;
            res = min(res, f[root]);
        }
        printf("Case #%d: %d\n", test, res);
    }

    return 0;
}

