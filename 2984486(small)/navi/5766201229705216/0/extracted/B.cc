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
const int MAXM = 1000;
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
int res;
vector<int> e[MAXN];
int dp[MAXN];
int size[MAXN];

void init() {
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }
}

void dfs(int u, int fa) {
    vector<int> sz;
    size[u] = 1;
    for (auto i : e[u]) {
        if (i != fa) {
            dfs(i, u);
            size[u] += size[i];
            sz.push_back(dp[i] - size[i]);
        }
    }
    sort(sz.begin(), sz.end());
    dp[u] = size[u] - 1;
    if (sz.size() >= 2 && sz[0] + sz[1] < 0) {
        dp[u] += sz[0] + sz[1];
    }
}

void solve() {
    res = INF;
    for (int i = 0; i < n; ++i) {
        memset(dp, 0x3f, sizeof(dp));
        dfs(i, -1);
        res = min(res, dp[i]);
    }
}


int main(int argc, char** argv) {
    int totalCaseNumber = 1;

    init();

    scanf("%d", &totalCaseNumber);
    for (int caseNum = 1; caseNum <= totalCaseNumber; ++caseNum) {
        input();
        solve();
        printf("Case #%d: %d\n", caseNum, res);
    }

    return 0;
}
