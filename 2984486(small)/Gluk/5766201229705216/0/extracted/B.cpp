#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int n;

VVI e, e2;
VI u;

VI total;
VI cost;

void makee(int x) {
    //cout << "makee " << x << endl;
    if (u[x])
        return;
    u[x] = 1;

    REP (i, e[x].size()) {
        int y = e[x][i];
        if (!u[y]) {
            e2[x].pb(y);
            makee(y);
        }
    }
}

void solve(int x) {
    std::vector<int> cc;
    total[x] = 1;
    REP (i, e2[x].size()) {
        int y = e2[x][i];

        solve(y);
        total[x] += total[y];
        cost[x] += total[y];
        cc.pb(cost[y]-total[y]);
    }

    if (cc.size() > 1) {
        SORT (cc);
        cost[x] += cc[0];
        cost[x] += cc[1];
    }
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        cout << "Case #" << tt+1 << ": ";

        cin >> n;
        e = VVI(n);
        REP (i, n-1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            e[x].pb(y);
            e[y].pb(x);
        }

        int res = n-1;

        REP (i, n) {
            //cout << i << endl;
            e2 = VVI(n);
            u = VI(n);

            makee(i);
            total = VI(n);
            cost = VI(n);
            solve(i);
            res = min (res, cost[i]);
        }

        cout << res << endl;
    }

	return 0;
}
