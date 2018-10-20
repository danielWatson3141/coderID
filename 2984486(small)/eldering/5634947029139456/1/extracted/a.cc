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

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int N,L;
		cin >> N >> L;

		VS sock(N), dev(N);
		string tmp;
		REP(i,N) cin >> sock[i];
		REP(i,N) cin >> dev[i];

		int best = infty;
		REP(d,N) REP(s,N) {
			int curr = 0;
			VS sock2 = sock;
			for(int i=0; i<L; i++) {
				if ( dev[d][i]!=sock[s][i] ) {
					curr++;
					REP(j,N) sock2[j][i] = (sock2[j][i]=='0' ? '1' : '0');
				}
			}
			int j;
			set<string> devs(ALL(dev));
			for(j=0; j<N; j++) if ( devs.count(sock2[j])!=1 ) break;
			if ( j>=N ) minimize(best,curr);
		}

		cout << "Case #" << run << ": ";
		if ( best<infty ) {
			cout << best << endl;
		} else {
			cout << "NOT POSSIBLE" << endl;
		}
	}

	return 0;
}
