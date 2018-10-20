#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

/*

*/

VI vis;
int full(int idx, int prev, const VVI& G) {
	vis[idx]=1;
	
	if(G[idx].size()<=1) return 1;
	VI pts;
	REP(i, G[idx].size()) {
		int v = G[idx][i];
		if(v!=prev && !vis[v]) {
			int cnt = full(v, idx, G);
			pts.PB(cnt);
		}
	}
	if(pts.size()<=1) return 1;
	sort(ALLR(pts));
	if(pts[0]==0 || pts[1]==0) return 1;
	return 1+pts[0]+pts[1];
}

int main() {
	int test_cases;
	cin>>test_cases;
	ll N;
	string s;
	REP(ttt, test_cases) {
		cin>>N;
		VVI g(N);
		REP(i, N-1) {
			int u,v;
			cin>>u>>v;
			u--; v--;
			g[u].PB(v);
			g[v].PB(u);
		}
		int ans = 1<<30;
		REP(root, N) {
			vis = VI(N);
//			if(!(g[root].size()==0 || g[root].size()==2)) continue;
			int live = full(root, -1, g);
			ans = min(ans, (int)N-live);
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		break;
	}
	return 0;
}



