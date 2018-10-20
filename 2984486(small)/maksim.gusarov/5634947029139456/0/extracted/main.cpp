#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 150 + 3;
const int LEN = 40 + 3;

int n, m;
string a[N], b[N];

inline bool read()
{
	if (scanf("%d%d", &n, &m) != 2) return false;
	
	char buf[LEN];
	
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		a[i] = string(buf);
	}
	
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		b[i] = string(buf);
	}
	
	return true;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	sort(b, b + n);
	
	int ans = INF;
	
	forn(mask, 1 << m)
	{
		vector<string> cur;
		int cnt = 0;
		
		forn(i, m) if (mask & (1 << i)) cnt++;
		
		forn(i, n)
		{
			string t = a[i];
			
			forn(j, m)
				if (mask & (1 << j))
				{
					if (t[j] == '0') t[j] = '1';
					else t[j] = '0';
				}
				
			cur.pb(t);
		}
		
		sort(all(cur));
		
		bool ok = true;
		forn(i, n) if (cur[i] != b[i]) { ok = false; break; }
		
		if (ok) ans = min(ans, cnt);
	}
	
	if (ans > INF / 2)
		puts("NOT POSSIBLE");
	else
		printf("%d\n", ans);
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
	    assert(read());
    	solve(test);
    }
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}
