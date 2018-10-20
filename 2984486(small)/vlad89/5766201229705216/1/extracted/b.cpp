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

string problemName = "B";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

vector<vector<int> > a;

int dfs(int x, int pred) {
    vector<int> childs;
    REP (i, sz (a[x]))
	if (a[x][i] != pred) {
	    childs.pb(dfs(a[x][i], x));
	}
    if (sz(childs) == 0) return 1;
    if (sz(childs) == 1) return 1;
    sort(all(childs));
    return 1 + childs[sz(childs)-1] + childs[sz(childs)-2];
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
	int n;
	cin >> n;
	a.clear();
	a.resize(n);
	REP (i, n-1) {
	    int x, y;
	    cin >> x >> y;
	    --x,--y;
	    a[x].pb(y);
	    a[y].pb(x);
	}
	int res = 0;
	REP (i, n) {
	    res = max(res, dfs(i, -1));
	}
	cout << n-res << endl;
    }
    return 0;
}
