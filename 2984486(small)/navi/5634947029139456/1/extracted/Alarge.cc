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
const int MAXN = 100;
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

int n, m;
ll a[150], b[150];
int res;

void init() {
}

ll readBinary() {
    char buf[1024];
    scanf("%s", buf);
    int len = strlen(buf);
    ll n = 0;
    for (int i = 0; i < len; ++i) {
        if (buf[i] == '1') {
            n |= 1LL << i;
        }
    }
    return n;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i] = readBinary();
    }
    for (int i = 0; i < n; ++i) {
        b[i] = readBinary();
    }
}

void solve() {
    res = INF;
    vector<ll> mask;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mask.push_back(a[i] ^ b[j]);
        }
    }
    for (ll i : mask) {
        vector<ll> va, vb;
        for (int j = 0; j < n; ++j) {
            va.push_back(a[j] ^ i);
            vb.push_back(b[j]);
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        if (va == vb) {
            res = min(res, __builtin_popcountll(i));
        }
    }
}


int main(int argc, char** argv) {
    int totalCaseNumber = 1;

    init();

    scanf("%d", &totalCaseNumber);
    for (int caseNum = 1; caseNum <= totalCaseNumber; ++caseNum) {
        input();
        solve();
        if (res == INF) {
            printf("Case #%d: NOT POSSIBLE\n", caseNum);
        } else {
            printf("Case #%d: %d\n", caseNum, res);
        }
    }

    return 0;
}
