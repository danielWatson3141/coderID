#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <numeric>
#include <algorithm>
using namespace std;

#define N 1005
#define M 80000
#define ll long long
#define inf 0X3f3f3f3f
#define lson (id<<1)
#define rson (id<<1|1)

#define mod 1000000007
#define eps 1e-6
#define pii pair<int,int>
#define pdd pair<double,int>
#define MP(i,j) make_pair(i,j)

int n, sons[N], minDelete[N];
struct Node {
    int v, nxt;
} edge[N << 1];
int head[N], eid = 0;

void addEdge(int u, int v) {
    edge[eid].v = v;
    edge[eid].nxt = head[u];
    head[u] = eid++;
    swap(u, v);
    edge[eid].v = v;
    edge[eid].nxt = head[u];
    head[u] = eid++;
}

void madan(int &big, int &small, int x) {
    if (x <= small) {
        big = small;
        small = x;
    } else if (x < big)
        big = x;
}

void madan2(int &big, int &small, int x) {
    if (x >= big) {
        small = big;
        big = x;
    } else if (x > small)
        small = x;
}

int dfs(int root, int father) {
    // if (father != -1)
    //     printf("%d->%d\n", father, root);
    sons[root] = 1;
    int n = 0, son_id = 0;
    int big = 0, small = 0;
    int sum_delete = 0;
    for (int p = head[root]; p != -1; p = edge[p].nxt) {
        int v = edge[p].v;
        if (father == v)
            continue;
        n++;
        son_id = v;
        sons[root] += dfs(v, root);
        sum_delete += minDelete[v];
        madan2(big, small, minDelete[v]);
    }
    // printf("n[%d]=%d\n", root, n);
    if (n == 0)
        minDelete[root] = 0;
    else if (n == 1) {
        minDelete[root] = sons[son_id];
        // printf("minDelete[%d]=%d, %d\n", root, minDelete[root], son_id);
    } else {
        // printf("%d %d:%d\n", root, small, big);
        minDelete[root] = sum_delete + n - 2;
        // printf("%d\n", sons[root]);
        // minDelete[root] -= big + (int)(big != 0);
        // minDelete[root] -= small + (int)(small != 0);
    }
    // printf("sons[%d]=%d\n", root, sons[root]);
    // printf("minDelete[%d]=%d\n", root, minDelete[root]);
    return sons[root];
}

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    eid = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int cas, pcas = 1;
    scanf("%d", &cas);
    while (cas--) {
        init();
        int result = inf;
        for (int i = 1; i <= n; i++) {
            // init
            for (int j = 1; j <= n; j++)
                minDelete[j] = inf;
            dfs(i, -1);
            result = min(result, minDelete[i]);
        }
        printf("Case #%d: %d\n", pcas++, result);
    }
    return 0;
}
