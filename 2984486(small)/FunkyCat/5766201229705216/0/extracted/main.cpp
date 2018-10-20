#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <limits>
#include <cstring>
using namespace std;

typedef long long li;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> pt;


#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n - 1); i >= 0; i--)
#define pb push_back
#define mp make_pair
#define matrix(T,n,m,v) vector<vector<T> >(n, vector<T>(m, v))
#define ft first
#define sc second
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

template<class T> T sqr(const T& x) { return x * x; }
template<class T> T abs(const T& x) { return x < 0 ? -x : x; }

template<class T, class P>
ostream& operator << (ostream& out, std::pair<T, P> p) {
	return (out << '(' << p.first << ' ' << p.second << ')');
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-8;
const ld PI = 3.1415926535897932384626433832795;

const int N = 1000 + 13;

int n;
vector<int> g[N];

bool read() {
	cin >> n;
	forn (i, n) {
		g[i].clear();
	}
	forn (i, n - 1) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--, v2--;
		g[v1].pb(v2);
		g[v2].pb(v1);
	}
	return true;
}

vector<int> t[N];
int sz[N];
int d[N];

void dfs(int v, int prev) {
	forn (i, g[v].size()) {
		int to = g[v][i];
		if (to == prev) {
			continue;
		}
		t[v].pb(to);
		dfs(to, v);
	}
}

void prepare(int root) {
	forn (i, n) {
		t[i].clear();
	}
	dfs(root, -1);
}

void precalc(int v) {
	sz[v] = 1;
	forn (i, t[v].size()) {
		int to = t[v][i];
		precalc(to);
		sz[v] += sz[to];
	}
}

void calc(int v) {
	d[v] = 0;
	if (t[v].size() == 0) {
		return;
	}
	forn (i, t[v].size()) {
		int to = t[v][i];
		calc(to);
	}
	if (t[v].size() == 1) {
		d[v] = sz[t[v][0]];
		return;
	}
	int best = INF;
	forn (i, t[v].size()) {
		forn (j, t[v].size()) {
			int min1 = t[v][i];
			int min2 = t[v][j];
			if (min1 == min2) {
				continue;
			}
			int curr = 0;
        	forn (i, t[v].size()) {
        		int to = t[v][i];
        		if (to == min1 || to == min2) {
        			curr += d[to];
        		} else {
        			curr += sz[to];
        		}
        	}
        	best = min(best, curr);
        }
    }
    d[v] = best;
}

void solve(int test) {
	cout << "Case #" << test << ": ";

	int ans = INF;
	forn (i, n) {
		prepare(i);
		precalc(i);
		calc(i);
		ans = min(ans, d[i]);
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCnt;
	cin >> testCnt;
	forn (test, testCnt) {
		read();
		solve(test + 1);
	}
	
    return 0;
}