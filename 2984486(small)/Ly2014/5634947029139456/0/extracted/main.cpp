#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
typedef long long LL;

const int N = 105;
const int inf = 1e9 + 7;
using namespace std;
int n, L;
char s[N][50], c[N][50];
LL maz[N][N];
int tot, pre[N];
struct edge {
    int v, next;
}e[N * N];
int match[N], vis[N];
vector<LL> g;
int nn;

void input() {
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
}

void work() {
    g.clear();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            LL st = 0;
            for (int k = 0; k < L; k ++) {
                 if (s[i][k] != c[j][k]) st |= (1LL << k);
            }
            maz[i][j] = st;
            g.push_back(st);
        }
    }
    sort(g.begin(), g.end());
    nn = unique(g.begin(), g.end()) - g.begin();
}

bool dfs(int u) {
    for (int i = pre[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == - 1 || dfs(match[v])){
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungry() {
    memset(match, -1, sizeof(match));
    int res = 0;
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) res ++;
    }
    return res;
}

int cal(LL st) {
    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (st  & (1LL << i)) cnt ++;
    }
    return cnt;
}

void init() {
    tot = 0;
    memset(pre, -1, sizeof(pre));
}

void add(int u,int v) {
    edge E = {v, pre[u]};
    e[tot] = E, pre[u] = tot++;
}

void build(LL st) {
    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maz[i][j] == st) add(i, j);
        }
    }
}

int get() {
    int res = inf;
    for (int i = 0; i < nn; i++) {
        int cnt = cal(g[i]);
        if (cnt >= res) continue;
        build(g[i]);
        if (hungry() == n) res = cnt;
    }
    return res;
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        input();
        work();
        int res = get();
        printf("Case #%d: ", cas ++);
        if (res < inf) printf("%d\n", res);
        else puts("NOT POSSIBLE");
    }
    return 0;
}











