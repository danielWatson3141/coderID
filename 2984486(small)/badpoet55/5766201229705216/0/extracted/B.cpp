//Full binary tree

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

#define deinfo //printf

#define max(a, b) ((a > b) ? (a) : (b))
#define MAXN (3010)

using namespace std;

struct edge
{
    int v, next;
} e[MAXN];
int mpt = 1;
int v[MAXN], d[MAXN], clr[MAXN], f[MAXN], n, tc;

void add_edge(int x, int y)
{
    e[mpt].v = y;
    e[mpt].next = v[x];
    v[x] = mpt;
    mpt++;
}

void add_undir_edge(int x, int y)
{
    add_edge(x, y);
    add_edge(y, x);
    d[x]++;
    d[y]++;
}

void dfsdp(int p)
{
    clr[p] = 1;
    int m1 = -1, m2 = -2;
    for (int j = v[p]; j > 0; j = e[j].next)
    {
        int q = e[j].v;
        if (clr[q] == 0)
        {
            dfsdp(q);
            if (f[q] >= m2)
            {
                if (f[q] >= m1)
                {
                    m2 = m1;
                    m1 = f[q];
                }
                else
                    m2 = f[q];
            }
        }
    }
    if (m1 < 0 && m2 < 0)
        f[p] = 1;
    else if (m2 < 0)
        f[p] = 1;
    else
        f[p] = m1 + m2 + 1;
}

void work(int tid)
{
    memset(v, 0, sizeof(v));
    memset(e, 0, sizeof(e)); 
    memset(clr, 0, sizeof(clr));
    cin >> n;
    int s, t, x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        add_undir_edge(x, y);
    }
    int ans = 0;
    for (int root = 1; root <= n; root++)
    {
        memset(clr, 0, sizeof(clr));
        memset(f, 0, sizeof(f));
        dfsdp(root);
        ans = max(f[root], ans);
        deinfo("root %d ans %d", root, ans);
    }
    printf("Case #%d: %d\n", tid, n - ans);
}

int main()
{
    cin >> tc;
    for (int tid = 1; tid <= tc; tid++)
        work(tid);
    return 0;
}