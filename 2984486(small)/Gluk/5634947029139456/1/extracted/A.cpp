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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        cout << "Case #" << tt + 1 << ": ";

        int n, m;
        cin >> n >> m;

        std::vector<string> a(n), b(n);

        REP (i, n)
            cin >> a[i];
        REP (i, n)
            cin >> b[i];

        int res = INF;

        REP (i, n) {
            int c = 0;
            std::vector<bool> d(m);
            REP (j, m) {
                if (a[0][j] != b[i][j]) {
                    c++;
                    d[j] = true;
                }
            }

            std::set<string> aa, bb;

            FOR (j, 1, n) {
                aa.insert(a[j]);
            }

            REP (j, n) {
                if (j==i)
                    continue;
                string s = b[j];

                REP (k, m)
                    if (d[k])
                        s[k] = '0'+'1' - s[k];
                bb.insert(s);
            }

            if (aa == bb)
                res = min (res, c);
        }

        if (res < INF)
            cout << res << endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }

	return 0;
}
