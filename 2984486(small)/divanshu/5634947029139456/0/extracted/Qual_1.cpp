/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    // freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

string init[45], req[45];

char flip(char x) {
	if ( x == '0' ) return '1';
	return '0';
}

int main() {
	input();
	int t, tst = 1;
	cin >> t;
	while ( t-- ) {
		cout << "Case #" << tst++ << ": ";
		int n,l; cin >> n >> l;
		F(i,0,n) cin >> init[i]; 
		F(i,0,n) cin >> req[i];
		sort(req,req+n); 
		// F(i,0,n) cout << req[i] << endl;
		int ans = 101;
		int mx = (1<<l);
		F(i,0,mx) {
			string now[45];
			int c = 0;
			F(j,0,l) {
				if ( (i&(1<<j)) > 0 ) {
					c++;
					// cout << j << " ";
					F(k,0,n) now[k].pb(flip(init[k][j]));
				} else {
					F(k,0,n) now[k].pb((init[k][j]));
				}
			}
			sort(now,now+n);
			// cout << endl;
			// F(j,0,n) cout << now[j] << endl;
			bool poss = 1;
			F(j,0,n) {
				if ( now[j] != req[j] ) poss = 0;
			}
			if ( poss ) ans = min(ans,c);
		}
		if ( ans == 101 ) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
	return 0;
}