#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

#define N 1010

int n;
int t[N], d[N], sub_tree_size[N];
vector<vector<int> > g;

void readInput()
{
    cin >> n;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int rec(int u, int p)
{
    int childN = g[u].size() - (p != -1);
    sub_tree_size[u] = 1;
    if (childN == 0)
        return 0;
    if (childN == 1)
    {
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            if (v != p)
            {
                rec(v, u);
                sub_tree_size[u] += sub_tree_size[v];
                return sub_tree_size[v];
            }
        }
    }

    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v != p)
        {
            d[v] = rec(v, u);
            sub_tree_size[u] += sub_tree_size[v];
        }
    }
    int ret = INT_MAX;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == p)
            continue;
        for (int j = i + 1; j < g[u].size(); j++)
        {
            int w = g[u][j];
            if (w != p)
            {
                ret = min(ret, d[v] + d[w] + sub_tree_size[u] - sub_tree_size[v] - sub_tree_size[w] - 1);
            }
        }
    }
    return ret;
}

int solve()
{
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, rec(i, -1));
    return res;
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        readInput();
        int ans = solve();
        cout << ans;
        cout << endl;
    }
    return 0;
}
