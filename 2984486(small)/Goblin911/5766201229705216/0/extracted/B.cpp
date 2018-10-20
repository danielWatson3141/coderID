#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int d;
    Edge* next;
    Edge(int a, Edge *b) {
        d = a;
        next = b;
    }
} *b[1001];

struct Info {
    int sz, f;
} tmp[1001];

int n, sz[1001], f[1001];
bool v[1001];

void addedge(int x, int y) {
    b[x] = new Edge(y, b[x]);
    b[y] = new Edge(x, b[y]);
}

bool cmp(Info a, Info b) {
    return a.sz - a.f < b.sz - b.f;
}

void dfs(int d) {
    v[d] = true;
    int ch = 0;
    sz[d] = 1;
    f[d] = 0;
    vector<int> child;
    for (Edge *i = b[d]; i; i = i->next) if (!v[i->d]) {
        dfs(i->d);
        child.push_back(i->d);
        ch++;
        sz[d] += sz[i->d];
    }
    if (ch == 0) {
        f[d] = 0;
        return;
    }
    if (ch == 1) {
        f[d] = sz[d] - 1;
        return;
    } else {
        for (int i = 1; i <= ch; i++) {
            tmp[i].sz = sz[child[i - 1]];
            tmp[i].f = f[child[i - 1]];
        }
        sort(tmp + 1, tmp + ch + 1, cmp);
        for (int i = 1; i <= ch - 2; i++) f[d] += tmp[i].sz;
        f[d] += tmp[ch - 1].f + tmp[ch].f;
    }
}

void solve() {
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        memset(v, 0, sizeof(v));
        memset(sz, 0, sizeof(sz));
        dfs(i);
        if (ans > f[i]) ans = f[i];
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
