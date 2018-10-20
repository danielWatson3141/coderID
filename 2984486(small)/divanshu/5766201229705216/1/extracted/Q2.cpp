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

vector<int> g[1015];

int use[1015];

void dfs(int whr,int par) {

	vector<int> child;

	F(i,0,g[whr].size()) {
		int nxt = g[whr][i];
		if ( nxt == par ) continue;
		dfs(nxt,whr);
		child.pb(use[nxt]);
	}

	if ( child.size() < 2 ) {
		use[whr] = 1;
		return;
	}

	int mx = max(child[0],child[1]), smx = min(child[0],child[1]);
	F(i,2,child.size()) {
		int x = child[i];
		if ( x >= mx ) {
			smx = mx;
			mx = x;
		} else if ( x >= smx ) {
			smx = x;
		}
	}
	use[whr] = smx+mx+1;

}

int main() {
	input();
	int t, tst = 1;
	cin >> t;
	while ( t-- ) {
		cout << "Case #" << tst++ << ": ";
		int n; cin >> n;
		F(i,0,1015) g[i].clear();
		F(i,1,n) {
			int a,b; cin >> a >> b;
			a--; b--;
			g[a].pb(b); g[b].pb(a);
		}
		int ans = n-1;
		
		F(i,0,n) {
			dfs(i,-1);
			ans = min(ans,n-use[i]);
		}

		cout << ans << endl;
	}
	return 0;
}