#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

vector<int> operator + (const vector<int> &a, const vector<int>& b) {
	vector<int> ans(a.size());
	forn(i, a.size())
		ans[i] = (a[i] + b[i]) % 2;
	return ans;
}

vector<int> a[MAXN], b[MAXN];
int n, m;

bool check(const vector<int> &d) {
	vector<vector<int> > aa, bb;
	forn(i, n) {
		bb.pb(b[i]);
		aa.pb(a[i] + d);
	}

	sort(all(aa));
	sort(all(bb));
	return aa == bb;
}

int stupid() {
    int ans = INF;
	forn(mask, 1 << m) {
		vector<int> d;
		forn(i, m) d.pb(bit(mask, i));
		if (check(d)) ans = min(ans, int(count(all(d), 1)));
	}

	return ans;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
		m = nextInt();
		forn(i, n) {
			string s;
			cin >> s;
			a[i].resize(m);
			forn(j, m)
				a[i][j] = s[j] - '0';
		}
		forn(i, n) {
			string s;
			cin >> s;
			b[i].resize(m);
			forn(j, m)
				b[i][j] = s[j] - '0';
		}
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

    int ans = INF;
	forn(i, n) {
		forn(j, n) {
			vector<int> d = a[i] + b[j];
			if (check(d)) ans = min(ans, int(count(all(d), 1)));
		}
	}

	string ANS = ans < INF/2 ? toStr(ans) : "NOT POSSIBLE";
	cout << ANS << endl;
    cerr << "\tclever answer is '" << ANS << "'." << endl;
    if (m <= 18) {
        int stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    int tests = nextInt();
    clock_t totalStartTime = clock();
    for(int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ": ";
        solve(skipThisTest);

        char formattedTime[100];
        clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
