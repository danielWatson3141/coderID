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

vector< vector<int> > g;

int check(int v, int p = -1)
{
    vector<int> tmp;
    for(int to : g[v])
    {
        if (to == p)
            continue;
        tmp.push_back(check(to, v));
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    int ans = 1;
    if (tmp.size() >= 2)
    {
        ans += tmp[0];
        ans += tmp[1];
    }
    return ans;

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
        int n, x, y, ans = 0;
        scanf("%d", &n);
        g.clear();
        g.resize(n);
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d %d", &x, &y);
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int root = 0; root < n; ++root)
            ans = max(ans, check(root));

        printf("Case #%d: %d\n", _i, n - ans);
    }

    return 0;
}

