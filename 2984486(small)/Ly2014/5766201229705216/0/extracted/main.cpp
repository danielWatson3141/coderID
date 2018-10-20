//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
typedef long  long LL;

const int N = 1005;
const int M = 1000005;
const int inf = 1 << 28;
const int mod = 1e9 + 7;
const double eps = 1e-8;
using namespace std;
int n;
int tot, pre[N];
struct edge {
    int v, next;
}e[N << 1];
int dp[N];
int cnt[N];

void init() {
    tot = 0;
    memset(pre, -1, sizeof(pre));
}

void add(int u, int v) {
    edge E = {v, pre[u]};
    e[tot] = E, pre[u] = tot ++;
}

void input() {
    scanf("%d", &n);
    init();
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
}

int son[N];


void dfs(int u, int fa) {
    cnt[u] = 0;
    int tmp = inf, tmd = inf;
    for (int i = pre[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        int cc = dp[v] - cnt[v];
        if (cc < tmp) swap(cc, tmp);
        if (cc < tmd) swap(cc, tmd);
    }
    dp[u] = cnt[u], cnt[u] ++;
    dp[u] = min(dp[u], dp[u] + tmp + tmd);
}

int work() {
    int res = inf;
    for (int i = 1; i <= n; i++) {
        dfs(i, -1);
        res = min(res, dp[i]);
//        puts("");
    }
    return res;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        input();
        printf("Case #%d: %d\n", cas++, work());
    }
    return 0;
}










