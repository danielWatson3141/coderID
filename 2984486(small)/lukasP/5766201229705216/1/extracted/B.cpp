#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef vector<int> vi;
vi best, sub;
vector<bool> seen;
void dfs(int l, vector<vi> &g)
{
    seen[l] = true;
    sub[l] = 1;
    vi r;
    for (int w : g[l]) if (!seen[w])
    {
        dfs(w, g);
        sub[l] += sub[w];
        r.push_back(best[w] - sub[w]);
    }

    best[l] = sub[l] - 1;
    if (r.size() >= 2)
    {
        sort(r.begin(), r.end());
        best[l] = min(best[l], sub[l] - 1 + r[0] + r[1]);
    }
}
int main()
{
    int tt; scanf("%d", &tt);
    rep(sd,0,tt)
    {
        printf("Case #%d: ", sd+1);
        int n; cin >> n;

        vector<vi> g(n);
        rep(i,0,n-1)
        {
            int x, y;
            cin >> x >> y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int res = n + 3;
        sub.assign(n, 0);
        rep(i,0,n)
        {
            best.assign(n, n);
            seen.assign(n, false);
            dfs(i, g);
            res = min(res, best[i]);
        }
        cout << res << endl;
    }
}
