//{
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (i = 0; i < (int)(n); ++i)
#define FOR(i, n) for (i = 1; i <= (int)(n); ++i)
#define LIN(i, u) for (i = head[u]; ~i; i = nxt[i])
#define MP make_pair
#define PB push_back
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define all(x) (x).begin(), (x).end()
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void CIN(T &a) { cin >> a; }
template <class T> void CIN(T &a, T &b) { cin >> a >> b; }
template <class T> void CIN(T &a, T &b, T &c) { cin >> a >> b >> c; }
template <class T> void CIN(T &a, T &b, T &c, T &d) { cin >> a >> b >> c>> d; }
template <class T> void PI(T a) { cout << a << endl; }
template <class T> void PI(T a, T b) { cout << a << " " << b << endl; }
template <class T> void PIS(T a) { cout << a << " "; }
template <class T> T abs(T a) { return a < 0 ? -a : a; }

//}

const int N = 1010;
const int inf = 0x3f3f3f3f;

int T;
int n;
int head[N], pre[N << 1], nxt[N << 1], e;
int d[N], son[N], dp[N];
int root;

void init() {
    clr(head, -1);
    e = 0;
    clr(d, 0);
}

void addedge(int u, int v) {
    pre[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dfs1(int u, int f) {
    son[u] = 1;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = pre[i];
        if (v == f) continue;
        dfs1(v, u);
        son[u] += son[v];
    }
}

void dfs(int u, int f) {
    dp[u] = son[u] - 1;
    int max1 = -inf, max2 = -inf;
    for (int i = head[u]; ~i; i = nxt[i]) {
        int v = pre[i];
        if (v == f) continue;
        dfs(v, u);
        if (son[v] - dp[v] > max1) {
            max2 = max1;
            max1 = son[v] - dp[v];
        }
        else if (son[v] - dp[v] > max2) {
            max2 = son[v] - dp[v];
        }
    }
    dp[u] = min(dp[u], dp[u] - (max1 + max2));
}

int deal() {
    dfs1(root, 0);
    dfs(root, 0);
    return dp[root];
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    scanf("%d", &T);
    int ix = 0;
    while (T--) {
        printf("Case #%d: ", ++ix);
        scanf("%d", &n);
        int i;
        int x, y;
        init();
        REP(i, n - 1) {
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
            ++d[x], ++d[y];
        }
        int ans = n;
        FOR(i, n) {
            root = i;
            ans = min(deal(), ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
