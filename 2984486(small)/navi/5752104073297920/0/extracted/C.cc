#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ext/rope>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;
const int MAXM = 100;
const int MOD = 1000000007;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const double PI = acos(-1.0);

#define DEBUG(args...) fprintf(stderr, args)
#define all(c) (c).begin(), (c).end()
#define pb push_back

template<typename U, typename V> void add(U& ret, const V& val) { ret = (ll)(ret + val) % MOD; }
template<typename U, typename V> void chkmax(U& ret, const V& val) { if (ret < val) { ret = val; } }
template<typename U, typename V> void chkmin(U& ret, const V& val) { if (val < ret) { ret = val; } }
template<typename T> T gcd(T a, T b) { return a == 0 ? b : gcd(b % a, a); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int n;
int a[MAXN];
double res;
double p[MAXN][MAXN];
double q[MAXN][MAXN];

void init() {
    n = 1000;
    double p1 = 1.0 / n;
    double p2 = 1.0 - p1;
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; ++i) {
        p[i][i] = 1.0;
    }
    for (int i = 0; i < n; ++i) {
        memset(q, 0, sizeof(q));
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < n; ++l) {
                        q[k][l] += p[k][j] * p1;
                    }
                }
            } else {
                for (int k = 0; k < n; ++k) {
                    q[k][i] += p[k][j] * p1;
                    q[k][j] += p[k][j] * p2;
                }
            }
        }
        memcpy(p, q, sizeof(p));
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.13f%c", p[i][j], j + 1 == n ? '\n' : ' ');
        }
    }
    */
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    res = 1.0;
    for (int i = 0; i < n; ++i) {
        res *= p[a[i]][i] / p[a[i]][n - 1];
    }
}


int main(int argc, char** argv) {
    int totalCaseNumber = 1;

    init();

    scanf("%d", &totalCaseNumber);
    for (int caseNum = 1; caseNum <= totalCaseNumber; ++caseNum) {
        input();
        solve();
        printf("Case #%d: %s\n", caseNum, res > 1.0 ? "BAD" : "GOOD");
    }

    return 0;
}
