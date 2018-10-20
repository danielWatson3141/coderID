#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef LL typec;
typedef LL type;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MAX 1005
#define E 2010

struct edge {
    int v;
    int nxt;
}e[E];

int from[MAX];
int to[MAX];
int g[MAX];
int son[MAX];

int idx;
int nNum;

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void init() {
    idx = 0;
    memset(g, -1, sizeof(g));
}

void addedge(int u, int v) {
    e[idx].v = v;
    e[idx].nxt = g[u];
    g[u] = idx++;
}

int f(int p, int u) {
    int nSum = 0;
    int nWay = 0;
    int mx = 0;
    int mx2 = 0;
    ++son[u];
    for (int i = g[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        if (v != p) {
            ++nWay;
            f(u, v);
            nSum += son[v];
            son[u] += son[v];
            if (mx < son[v]) {
                mx = son[v];
            } else if (mx == son[v]) {
                mx2 = son[v];
            } else {
                mx2 = max(mx2, son[v]);
            }
        }
    }
    if (nWay == 1) {
        nNum += nSum;
        son[u] = 1;
    } else if (nWay > 2) {
        nNum += nSum - mx - mx2;
        son[u] -= nSum - mx - mx2;
    }
    return 0;
}

int main(void) {
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int nCase;
    while (~scanf("%d", &nCase)) {
        for (int cas = 1; cas <= nCase; ++cas) {
            int N;
            scanf("%d", &N);
            init();
            for (int i = 0; i < N - 1; ++i) {
                scanf("%d %d", &from[i], &to[i]);
                --from[i];
                --to[i];
                if (from[i] > to[i]) {
                    Swap(from[i], to[i]);
                }
                addedge(from[i], to[i]);
                addedge(to[i], from[i]);
            }
            int mn = INF;
            for (int root = 0; root < N; ++root) {
                memset(son, 0, sizeof(son));
                nNum = 0;
                f(root, root);
                mn = min(mn, nNum);
            }
            printf("Case #%d: ", cas);
            printf("%d\n", mn);
        }
    }
    return 0;
}