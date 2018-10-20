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

double sqr(double x) {
    return abs(x);
}

int p[1024][1024];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	std::mt19937_64 rng;

    int n = 1000;
    int it = 1000000;


REP (i, it) {

    std::vector<int> a(n);
    REP (i,n) a[i] = i;

    REP (i, n) {
        swap(a[i], a[rng()%n]);
    }
    REP (i, n) {
        p[a[i]][i] ++;
    }
}


    int t;
    cin >> t;

    REP (tt, t) {
        cout << "Case #" << tt+1 << ": ";

        int n;
        cin >> n;
        VI a(n);
        REP (i, n)
            cin >> a[i];

        long double pbad = 1;

        REP (i, n) {
            pbad *= (long double)p[a[i]][i] / it;

            pbad *= n;
        }

        if (pbad < 1)
            cout << "GOOD" << endl;
        else
            cout << "BAD" << endl;
    }

	return 0;
}
