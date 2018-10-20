#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
const int MAX_N =  1005;

vector<int> G[MAX_N];

void output (int t, int res )
{
	printf ("Case #%d: %d\n", t, res );

}


bool ok1;
int cnt;
int visit[MAX_N];

void dfs (int curr, int prev ){

	if (!ok1 || cnt ) return;

	visit[curr] = true;

	vector<int> cand; cand.clear();
	rep (i, G[curr].size() ){
		int u = G[curr][i];
		if (u == prev || visit[u] ) continue;
		cand.push_back (u );
	} // end rep

	if (cand.size() == 0 ){
		return;
	}else
	if (cand.size() == 2 ){
		rep (j, 2 ){
			dfs (cand[j], curr );
		} // end rep
	}else{
		ok1 = false;
		if (curr == 0 ){
			if (cand.size() == 1 ){
				cnt = 1;
			}else{
				cnt = (int)cand.size() - 2;
			} // end if
		}else{
			cnt++;
		} // end if

		return;
	} // end if
}			

int main()
{
	int T;
	scanf ("%d", &T );
	for (int t=1; t<=T; t++ ){
		rep (i, MAX_N ) G[i].clear();
		int n; scanf ("%d", &n );
		rep (i, n - 1 ){
			int x, y; scanf ("%d %d", &x, &y );
			x--; y--;
			G[x].push_back (y );
			G[y].push_back (x );
		} // end rep
		int res = 2;
		memset (visit, false, sizeof (visit ) );
		ok1 = true;
		cnt = 0;
		dfs (0, -1 );
		if (ok1 ){
			res = 0;
		}else{
			res = cnt;
		} // end if

		output (t, res );
	} // end for
		
	return 0;
}
