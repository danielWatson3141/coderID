/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: B.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-04-26
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (LL i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1000 + 5;

int psz;
struct Edge {
        int u, v;
        Edge *next;
} epool[maxn*2], *e[maxn];

void add_edge(int u, int v)
{
        Edge *p = epool + psz++;
        p->u = u; p->v = v; p->next = e[u]; e[u] = p;
}

int n;
int cnt[maxn];

int dfs(int u, int f)
{
        int m1 = -inf, m2 = -inf;
        cnt[u] = 0;
        for (Edge *i = e[u]; i; i = i->next) {
                int v = i->v;
                if (v == f) continue;
                int t = dfs(v, u);
                cnt[u] += cnt[v] + 1;
                t = cnt[v] + 1 - t;
                if (t > m1) {
                        m2 = m1;
                        m1 = t;
                } else if (t > m2) {
                        m2 = t;
                }
        }
        if (m1 == -inf) return 0;
        else if (m2 == -inf) return cnt[u];
        else return cnt[u] - m1 - m2;
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                psz = 0;
                memset(e, 0, sizeof(e));
                scanf("%d", &n);
                REP(i,n-1) {
                        int u, v;
                        scanf("%d%d", &u, &v);
                        --u; --v;
                        add_edge(u, v);
                        add_edge(v, u);
                }
                int res = inf;
                REP(i,n) res = min(res, dfs(i, -1));
                printf("Case #%d: %d\n", ++cas, res);
        }

        return 0;
}
