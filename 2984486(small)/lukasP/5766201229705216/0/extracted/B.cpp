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
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi best, sub;
vector<bool> seen;
void dfs(int l, vector<vi> &g)
{
    seen[l] = true;

    vi q;
    vi sons;
    sub[l] = 1;
    for (int w : g[l]) if (!seen[w])
    {
        dfs(w, g);
        q.push_back(best[w]);
        sons.push_back(w);
        sub[l] += sub[w];
    }

    best[l] = sub[l] - 1;
    if (sons.size() >= 2)
    {
        rep(k,0,q.size())
            rep(j,0,k)
                best[l] = min(best[l], q[k] + q[j] + sub[l] - 1 - sub[sons[k]] - sub[sons[j]]);
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
