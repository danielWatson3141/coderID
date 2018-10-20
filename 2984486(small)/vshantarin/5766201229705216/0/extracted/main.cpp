#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
//#include <unordered_set>
//#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231
using namespace std;

bool isFullBinary(int v, vector< vector<int> > &g, int p = -1)
{
    if (p == -1)
    {
        if (g[v].empty())
            return true;
        if (g[v].size() == 2)
            return isFullBinary(g[v][0], g, v) && isFullBinary(g[v][1], g, v);
        return false;
    }
    if (g[v].size() == 1)
        return true;
    if (g[v].size() == 3)
    {
        bool ret = true;
        for (int i = 0; i < 3; ++i)
            ret &= g[v][i] == p ? true : isFullBinary(g[v][i], g, v);
        return ret;
    }
    return false;
}

void dfs(int v, vector< vector<int> > &g, vector<int> &used)
{
    used[v] = true;
    for (int j : g[v])
        if (!used[j])
            dfs(j, g, used);
}

int bitCount(int x)
{
    int ret = 0;
    while (x)
        x &= (x - 1), ++ret;
    return ret;
}

int main()
{
#ifdef MYLOCAL
    freopen("/home/vladimir/code/pain/input.txt", "rt", stdin);
    freopen("/home/vladimir/code/pain/output.txt", "wt", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int _i = 1; _i <= t; ++_i)
    {
        int n, x, y, ans = INT_MAX;
        scanf("%d", &n);
        vector< vector<int> > g(n);
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d %d", &x, &y);
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int m = 0; m < (1 << n); ++m)
        {
            vector< vector<int> > curG(n);
            for (int i = 0; i < n; ++i)
                if (!(m & (1 << i)))
                    for (int j : g[i])
                        if (!(m & (1 << j)))
                            curG[i].push_back(j);

            int compCnt = 0;
            vector<int> used(n);
            for (int i = 0; i < n; ++i)
            {
                if (!(m & (1 << i)) && !used[i])
                    dfs(i, curG, used), ++compCnt;
            }

            if (compCnt != 1)
                continue;


            int cnt = bitCount(m);
            bool ok = false;
            for (int i = 0; i < n; ++i)
            {
                if (!(m & (1 << i)))
                    ok = isFullBinary(i, curG);
                if (ok)
                    break;
            }
            if (ok)
                ans = min(ans, cnt);
        }

        printf("Case #%d: ", _i);
        if (ans == INT_MAX)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", ans);
    }

    return 0;
}

