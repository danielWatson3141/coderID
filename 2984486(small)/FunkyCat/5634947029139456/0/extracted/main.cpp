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

const int N = 200;
const int L = 50;

int n, l;
li a[N], b[N], an[N];

bool read() {
	cin >> n >> l;
	forn (i, n) {
		string s;
		cin >> s;
		a[i] = 0ll;
		forn (j, l) {
			a[i] |= li(s[j] - '0') << (l - j - 1);
		}
	}
	forn (i, n) {
		string s;
		cin >> s;
		b[i] = 0ll;
		forn (j, l) {
			b[i] |= li(s[j] - '0') << (l - j - 1);
		}
	}
	return true;
}

inline li bit(li x, size_t pos) {
	return (x >> pos) & 1ll;
}

void solve(int test) {
	cout << "Case #" << test << ": ";

	sort(a, a + n);
	sort(b, b + n);

	/*
	forn (i, n) {
		cerr << a[i] << endl;
	}
	forn (i, n) {
		cerr << b[i] << endl;
	}
	*/

	int ans = INF;
	forn (k, n) {
		int curr = 0;
		li state = 0ll;
		forn (i, l) {
			if (bit(a[0], i) != bit(b[k], i)) {
				curr++;
				state |= 1ll << i;
			}
		}
		//cerr << "=====" << k << ' ' << state << "====" << endl;
		if (curr > ans) {
			continue;
		}
		forn (i, n) {
			an[i] = 0ll;
			forn (j, l) {
				an[i] |= li(bit(a[i], j) ^ bit(state, j)) << j;
			}
			//cerr << an[i] << endl;
		}
		sort(an, an + n);
		bool ok = true;
		forn (i, n) {
			if (b[i] != an[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans = min(ans, curr);
		}
	}
	if (ans == INF) {
		cout << "NOT POSSIBLE" << endl;
	} else {
		cout << ans << endl;
	}
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