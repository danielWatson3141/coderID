/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: A.cpp
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

const int maxn = 150 + 5;
const int maxe = 500000 + 5;

class Hungarian {
        int n, psz;
        struct Edge {
                int u, v;
                Edge *next;
        } epool[maxe], *e[maxn];
        int match[maxn];
        bool vis[maxn];

        bool aug(int u)
        {
                for (Edge *i = e[u]; i; i = i->next) {
                        int v = i->v;
                        if (vis[v]) continue; vis[v] = true;
                        if (match[v] == -1 || aug(match[v])) {
                                match[v] = u;
                                return true;
                        }
                }
                return false;
        }

        public:
        void init(int n)
        {
                this->n = n; psz = 0;
                memset(e, 0, sizeof(e));
        }

        void add_edge(int u, int v)
        {
                Edge *p = epool + psz++;
                p->u = u; p->v = v; p->next = e[u]; e[u] = p;
        }

        int solve()
        {
                int cnt = 0;
                memset(match, -1, sizeof(match));
                for (int i = 0; i < n; ++i) {
                        memset(vis, false, sizeof(vis));
                        cnt += aug(i);
                }
                return cnt / 2;
        }
} solver;

int n, l;
char s[maxn][64], t[maxn][64];
map<LL, vector<Pii> > mp;

int bit_count(LL S)
{
        int res = 0;
        while (S) {
                ++res;
                S -= (S & -S);
        }
        return res;
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                mp.clear();
                scanf("%d%d", &n, &l);
                REP(i,n) scanf("%s", s[i]);
                REP(i,n) scanf("%s", t[i]);
                REP(i,n) REP(j,n) {
                        LL d = 0;
                        REP(k,l) if (s[i][k] != t[j][k]) d |= (1LL << k);
                        mp[d].push_back(Pii(i, j));
                }
                int res = inf;
                FOREACH(it,mp) {
                        if (it->second.size() < n) continue;
                        solver.init(n * 2);
                        FOREACH(i,it->second) {
                                solver.add_edge(i->first, i->second + n);
                                solver.add_edge(i->second + n, i->first);
                        }
                        if (solver.solve() == n)
                                res = min(res, bit_count(it->first));
                }
                printf("Case #%d: ", ++cas);
                if (res == inf) puts("NOT POSSIBLE");
                else printf("%d\n", res);
        }

        return 0;
}
