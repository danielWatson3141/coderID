#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string problemName = "A";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

long long bit(string s) {
    long long res = 0;
    REP (i, sz (s))
	res = res * 2 + s[i]-'0';
    return res;
}

int main () {
    freopen(inputFileName.data(), "r", stdin);
    if (fileName == smallFileName || fileName == largeFileName)
    {
	freopen(outputFileName.data(), "w", stdout);
    }
    int T;
    cin >> T;
    REP (test, T) {
	cout << "Case #" << (test + 1) << ": ";
	int n, m;
	cin >> n >> m;
	vector<long long> a, b;
	REP (i, n) {
	    string x;
	    cin >> x;
	    a.pb(bit(x));
	}
	REP (i, n) {
	    string x;
	    cin >> x;
	    b.pb(bit(x));
	}
	sort(all(b));
	int inf = -1u/4;
	int best = inf;
	REP (i, n) {
	    REP (j, n) {
		long long u = a[i]^b[j];
		vector<long long> newa;
		REP (p, n) {
		    newa.pb(a[p]^u);
		}
		sort(all(newa));
		if (newa == b) {
		    best = min(best, __builtin_popcountll(u));
		}
	    }
	}
	if (best == inf) {
	    cout << "NOT POSSIBLE\n";
	    continue;
	}
	cout << best << endl;
    }
    return 0;
}
