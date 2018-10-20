#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

const int dx[8] = {  1, 0,-1, 0, 1,-1,-1, 1 };
const int dy[8] = {  0, 1, 0,-1, 1, 1,-1,-1 };

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int N;
VVI conn;

bool cmp(const VI& a, const VI& b)
{
	if ( a[1]-a[0]!=b[1]-b[0] ) return a[1]-a[0]<b[1]-b[0];
	return a[1]<b[1];
}

VI del(int c, int p)
{
	debug("subdel(%d,%d)\n",c,p);
	VI res(2), tmp;
	res[1] = 1;

	VVI subdel;
	REP(i,conn[c].size()) {
		if ( conn[c][i]==p ) continue;
		tmp = del(conn[c][i],c);
		res[1] += tmp[1];
		subdel.push_back(tmp);
	}
	sort(ALL(subdel),cmp);

	if ( subdel.size()<2 ) {
		if ( subdel.size()==1 ) res[0] = subdel[0][1];
	} else {
		int i;
		for(i=0; i<subdel.size()-2; i++) res[0] += subdel[i][1];
		for(;    i<subdel.size();   i++) res[0] += subdel[i][0];
	}

	debug("subdel(%d,%d) = %d,%d\n",c,p,res[0],res[1]);
	return res;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> N;

		conn = VVI(N);

		REP(i,N-1) {
			int a,b;
			cin >> a >> b;
			a--; b--;
			conn[a].push_back(b);
			conn[b].push_back(a);
		}

		int best = infty;
		REP(r,N) {
			debug("trying root %d\n",r);
			VI curr = del(r,-1);
			minimize(best,curr[0]);
		}

		cout << "Case #" << run << ": ";
		cout << best << endl;
	}

	return 0;
}
