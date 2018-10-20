#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)

// assert or gtfo

#define MAXN 5000
int dist[MAXN+1], q[MAXN+1];
#define dist(v) dist[v == -1 ? MAXN : v]
struct bipartite_graph {
    int N, M, *L, *R; vi *adj;
    bipartite_graph(int _N, int _M) : N(_N), M(_M),
        L(new int[N]), R(new int[M]), adj(new vi[N]) {}
    ~bipartite_graph() { delete[] adj; delete[] L; delete[] R; }
    bool bfs() {
        int l = 0, r = 0;
        for(int v = 0; v < N; ++v) if(L[v] == -1) dist(v) = 0, q[r++] = v;
            else dist(v) = INF;
        dist(-1) = INF;
        while(l < r) {
            int v = q[l++];
            if(dist(v) < dist(-1)) {
                foreach(u, adj[v]) if(dist(R[*u]) == INF)
                    dist(R[*u]) = dist(v) + 1, q[r++] = R[*u];
            }
        }
        return dist(-1) != INF;
    }
    bool dfs(int v) {
        if(v != -1) {
            foreach(u, adj[v])
                if(dist(R[*u]) == dist(v) + 1)
                    if(dfs(R[*u])) {
                        R[*u] = v, L[v] = *u;
                        return true;
                    }
            dist(v) = INF;
            return false;
        }
        return true;
    }
    void add_edge(int i, int j) { adj[i].push_back(j); }
    int maximum_matching() {
        int matching = 0;
        memset(L, -1, sizeof(int) * N);
        memset(R, -1, sizeof(int) * M);
        while(bfs()) for(int i = 0; i < N; ++i)
            matching += L[i] == -1 && dfs(i);
        return matching;
    }
};

int bitcount(ll x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x &= x - 1;
    }

    return cnt;
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d: ", t+1);

        int n, l;
        scanf("%d %d\n", &n, &l);

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ll x = 0;
            for (int j = 0; j < l; j++)
                x = (x << 1) | (s[j] == '1' ? 1 : 0);
            a[i] = x;
        }

        vector<ll> b(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ll x = 0;
            for (int j = 0; j < l; j++)
                x = (x << 1) | (s[j] == '1' ? 1 : 0);
            b[i] = x;
        }

        set<ll> poss;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                poss.insert(a[i] ^ b[j]);

        int mn = -1;
        for (set<ll>::iterator it = poss.begin(); it != poss.end(); ++it)
        {
            bipartite_graph g(n, n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((a[i] ^ *it) == b[j])
                    {
                        g.add_edge(i, j);
                    }
                }
            }

            int curcnt = bitcount(*it);
            if (g.maximum_matching() == n && (mn == -1 || curcnt < mn))
            {
                mn = curcnt;
            }
        }

        if (mn == -1)
        {
            printf("NOT POSSIBLE\n");
        }
        else
        {
            printf("%d\n", mn);
        }
    }

    return 0;
}

