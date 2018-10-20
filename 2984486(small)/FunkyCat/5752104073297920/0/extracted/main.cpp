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
int a[N];

int tBad, tGood;

bool read() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	return true;
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	int cnt1 = 0;
	for (int i = 1; i < n; i++) {
		if (i == a[i - 1]) {
			cnt1++;
		}
	}
	int cnt2 = 0;
	forn (i, 100) {
		if (a[i] >= 900) {
			cnt2++;
		}
	}

	int cnt3 = 0;
	for (int i = 400; i < 600; i++) {
		if (a[i] == i) {
			cnt3++;
		}
	}

	forn (i, 10) {
		if (a[i] >= 1000 - 10) {
			tGood++;
			cout << "GOOD" << endl;
			return;
		}
	}

	if ((cnt1 > 2 || cnt2 < 9) && cnt3 <= 1) {
		cout << "BAD" << endl;
		tBad++;
	} else {
		cout << "GOOD" << endl;
		tGood++;
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

	cerr << tBad << ' ' << tGood << endl;
	
    return 0;
}