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

string problemName = "C";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

template<int N>
struct Summator {
    int a[N + 1];
    int n;
    #define PREV(x) (x & (x - 1))
    #define NEXT(x) ((x << 1) - PREV(x))
    int sum(int q,int w) {
	if (q > w) return 0;
        q++;    w++;        
        static int r, x;
        r = 0;
        for(x = w; x; x = PREV(x)) r += a[x];
        for(x = q - 1;x;x = PREV(x)) r -= a[x];
        return r;
    }
    void modify(int x, int value) {
        x++;
        for(;x <= n; x = NEXT(x)) a[x] += value;
    }    
    void init(int _n) { 
        n = _n;
        memset(a, 0, sizeof(a));
    }
};

Summator<1024> s;

double prob(vector<int> x) {
    int n = sz(x);
    double add = 0;
    REP (i, n/2) {
	if (x[i] > i) {
	    double dp = (double) (x[i] - i) / (n - i - 1);
	    add += (1-dp)*(1-dp);
	}
    }
    return add;
}

int main () {
    freopen(inputFileName.data(), "r", stdin);
    //    if (fileName == smallFileName || fileName == largeFileName)
    {
	freopen(outputFileName.data(), "w", stdout);
    }
    int T;
    cin >> T;
    int ave = 0;
    REP (test, T) {
	cout << "Case #" << (test + 1) << ": ";
	int n;
	cin >> n;
	vector<int> a(n);
	REP (i, n)
	    cin >> a[i];
	//	cout << abs(cutoff * (cutoff-1) / 4 - res) << endl;
	if (prob(a) < 134)
	    cout << "GOOD"; else cout << "BAD";
	cout << endl;
	    //	ave += res;
    }

    return 0;
}
