#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
                  
#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>   


using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

void dbg() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg (Head H, Tail... T) {
  cerr << H << ' ';
  dbg(T...);
}

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

const int N = 2000;

int n;
int x[N], y[N];
vector < int > g[N];


inline bool read() 
{
 	if (scanf("%d", &n) != 1)
 		return false;

 	forn(i, n - 1)
 	{
 		assert(scanf("%d %d", &x[i], &y[i]) == 2);
 		x[i]--, y[i]--;
    }

 	return true;
}

inline void solve(int CURTEST) 
{
	int ans = INF;
	cout << "Case #" << CURTEST << ": ";

	forn(mask, (1 << n))
	{
	 	int tans = 0;

	 	forn(i, n)
	 		if (hasBit(mask, i))
	 			tans++;

	 	forn(i, n)
	 		g[i].clear();

    	forn(i, n - 1)
    	{
    		if (hasBit(mask, x[i]))
    			continue;

    		if (hasBit(mask, y[i]))
    			continue;

    		g[x[i]].pb(y[i]);
    		g[y[i]].pb(x[i]);
    	}            

    	int nmask = mask;
    	int szUPD = 0;
    	forn(i, n)
    	{
    	 	if (hasBit(nmask, i))
    	 		continue;
            
            queue < int > q;
    	   	queue < int > pr;

    	   	q.push(i);
    	   	pr.push(-1);

    	   	vector < int > nused;

            bool ok = true;
            
            while (!q.empty())
    	   	{
    	   	 	int v = q.front();
                     
    	   	 	nused.pb(v);

    	   	 	int prev = pr.front();

    	   	 	q.pop();
    	   	 	pr.pop();

    	   	 	int cnt = 0;

    	   	 	forn(j, sz(g[v]))
    	   	 	{
    	   	 		if (g[v][j] == prev) 
    	   	 			continue;
    	   	 		
    	   	 		if (hasBit(nmask, g[v][j])) 
    	   	 			continue;

    	   	 		cnt++;      
    	   	 	}

    	   	 	if (cnt != 2 && cnt != 0)
    	   	 		ok = false;

    	   	 	forn(j, sz(g[v]))
    	   	 	{
    	   	 		if (g[v][j] == prev)
    	   	 	 		continue;

    	   	 	 	if (hasBit(nmask, g[v][j])) continue;
    	   	 	 	q.push(g[v][j]);
    	   	 	 	pr.push(v);
    	   	 	}
            }        
                     
            if (ok)
            {
             	forn(j, sz(nused))
             		nmask |= (1 << nused[j]);
             	szUPD ++;
            }
        }
                     

        if (nmask == ((1 << n) - 1) && szUPD == 1)
        {
         	ans = min(ans, tans);
         }
    }	

    cout << ans << endl;


}

int main() 
{

#ifdef gridnevvvit
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    
	srand(time(NULL));
	
	int testCnt;

	assert(scanf("%d", &testCnt) == 1);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	forn(test, testCnt) 
	{
		assert(read());
		solve(test + 1);
		cerr << "test " << test + 1 << ' ' << "solved" << endl;
		cerr << clock() << endl;
	}

/*	assert(read());
	solve();
*/

#ifdef gridnevvvit
	cerr << "===Time: " << clock()  << "===" << endl;
#endif

}       