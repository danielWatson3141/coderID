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
#define INF 100

using namespace std;

typedef long long ll;


void output (int t )
{
	printf ("Case #%d: ", t  );

}
bool same (vector<string> s, vector<string> t ){
	int n = s.size();
	rep (i, n ){
		if (s[i] == t[i] ) continue;
		return false;
	} // end rep

	return true;
}

int main()
{
	int T;
	scanf ("%d", &T );
	for (int t=1; t<=T; t++ ){
		int n, l; scanf ("%d %d", &n, &l );
		vector<string> sw1(n );
		rep (i, n ){
			cin >> sw1[i];
		} // end rep

		vector<string> sw2 (n );
		rep (i, n ){
			cin >> sw2[i];
		} // end rep
		sort (ALL (sw2 ) );

		bool ok = false;
		int res = INF;

		rep (i, 1<<l ){
			vector<string> tw1 = sw1;
			rep (j, l ){
				if (i & (1<<j ) ){
					rep (k, n ){
						if (sw1[k][j] == '1' ) 
							tw1[k][j] = '0';
						else
							tw1[k][j] = '1';
					} // end rep
				} // end if
			} // end rep
			sort (ALL (tw1 ) );
			if (same (tw1, sw2 ) ){
				ok |= true;
				res = min (res, __builtin_popcount (i ) );
			 } // end if
		} // end rep

		output (t );
		if (ok ){
			cout << res << endl;
		}else{
			cout << "NOT POSSIBLE" << endl;
 		} // end if
	} // end for
		
	return 0;
}
