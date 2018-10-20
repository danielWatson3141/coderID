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
#define MAX 16
#define E 35

struct edge {
    int v;
    int nxt;
}e[E];

int from[MAX];
int to[MAX];
int g[MAX];
int Pow[20];

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
    if (-1 == nNum) {
        return 0;
    }
    ++nNum;
    int nSum = 0;
    for (int i = g[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        if (v != p) {
            ++nSum;
            f(u, v);
            if (-1 == nNum) {
                return 0;
            }
        }
    }
    if ((nSum != 0) && (nSum != 2)) {
        nNum = -1;
    }
    return 0;
}

int main(void) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int nCase;
    while (~scanf("%d", &nCase)) {
        for (int i = 0; i < 20; ++i) {
            Pow[i] = 1 << i;
        }
        for (int cas = 1; cas <= nCase; ++cas) {
            int N;
            scanf("%d", &N);
            for (int i = 0; i < N - 1; ++i) {
                scanf("%d %d", &from[i], &to[i]);
                --from[i];
                --to[i];
                if (from[i] > to[i]) {
                    Swap(from[i], to[i]);
                }
            }
            int mn = INF;
            bool vis[MAX];
            for (int root = 0; root < N; ++root) {
                int nTotal = (1 << N) - 1;
                for (int k = 0; k <= nTotal; ++k) {
                    memset(vis, false, (N + 1) * sizeof(bool));
                    int nBits = 0;
                    for (int i = 0; i < N; ++i) {
                        if (Pow[i] & k) {
                            ++nBits;
                            vis[i] = true;
                        }
                    }
                    if (!vis[root]) {
                        continue;
                    }
                    init();
                    for (int i = 0; i < N - 1; ++i) {
                        if (vis[from[i]] && vis[to[i]]) {
                            addedge(from[i], to[i]);
                            addedge(to[i], from[i]);
                        }
                    }
                    nNum = 0;
                    f(root, root);
                    if (nNum == nBits) {
                        mn = min(mn, N - nBits);
                    }
                }
            }
            printf("Case #%d: ", cas);
            printf("%d\n", mn);
        }
    }
    return 0;
}