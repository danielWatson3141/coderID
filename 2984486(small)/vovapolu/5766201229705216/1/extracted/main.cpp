#include <iostream>
#include <limits.h>
#include <vector>
#include <cstdio>

using namespace std;

vector <vector <int> > g;
vector <int> sz;

int getsz(int v, int p)
{
    if (sz[v] == -1)
    {
        sz[v] = 1;
        for (int i = 0; i < g[v].size(); i++)
            if (g[v][i] != p)
                sz[v] += getsz(g[v][i], v);
    }
    return sz[v];
}

int calc(int v, int p)
{
    int ans = 0;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (g[v][i] == p)
            continue;
        ans += getsz(g[v][i], v);
        int c = calc(g[v][i], v) - getsz(g[v][i], v);
        if (c <= min1)
        {
            min2 = min1;
            min1 = c;
        }
        else if (c <= min2)
        {
            min2 = c;
        }
    }
    if (min2 != INT_MAX)
        return ans + min1 + min2;
    else
        return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int q = 0; q < t; q++)
    {
        printf("Case #%d: ", q + 1);
        int n;
        scanf("%d", &n);
        g.clear();
        g.resize(n);
        sz.resize(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int minval = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sz.assign(n, -1);
            minval = min(minval, calc(i, -1));
        }
        printf("%d\n", minval);
    }
    return 0;
}
