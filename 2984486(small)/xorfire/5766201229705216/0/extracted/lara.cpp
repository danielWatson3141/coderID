#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1006;
vector<int> g[N];
bool was[N];
int cost[N], siz[N];

int dfs(int v)
{
    was[v] = true;
    siz[v] = 1;

    vector<pair<int, int> > w;
    for(int x : g[v])
        if(!was[x])
        {
            int ct = dfs(x);
            w.push_back(make_pair(ct, siz[x]));
            siz[v] += siz[x];
        }

    int sz = w.size();
    if(sz == 0) return 0;
    if(sz == 1) return w[0].second;

    int ret = 0;
    for(int i = 0; i < sz; ++i)
        ret += w[i].second;

    for(int i = 1; i < sz; ++i)
        if(w[i].first - w[i].second < w[0].first - w[0].second)
            swap(w[0], w[i]);
    ret += w[0].first - w[0].second;

    for(int i = 2; i < sz; ++i)
        if(w[i].first - w[i].second < w[1].first - w[1].second)
            swap(w[1], w[i]);
    ret += w[1].first - w[1].second;

    return ret;
}

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i)
            g[i].resize(0);
        for(int i = 0; i < n-1; ++i)
        {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ret = n-1;
        for(int i = 1; i <= n; ++i)
        {
            memset(was, 0, sizeof(was));
            memset(cost, 0, sizeof(cost));
            memset(siz, 0, sizeof(siz));
            ret = min(ret, dfs(i));
        }

        printf("Case #%d: %d\n", tt, ret);
    }
    return 0;
}