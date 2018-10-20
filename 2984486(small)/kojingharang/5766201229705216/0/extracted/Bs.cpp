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
map<int, int> hi;
int full(int idx, int prev, const VVI& G) {
	int cnt=1;
	vis[idx]=1;
	hi[G[idx].size()]++;
	
	REP(i, G[idx].size()) {
		int v = G[idx][i];
		if(v!=prev && !vis[v]) {
			cnt += full(v, idx, G);
		}
	}
	return cnt;
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
//		cout<<"NNNN "<<N<<endl;
//		cout<<g<<endl;
		int ans = 1<<30;
		REP(bits, 1<<N) {
			VVI G(N);
			REP(i, N) {
				REP(j, g[i].size()) {
					int v=g[i][j];
					if(((bits>>i)&1)==0 && ((bits>>v)&1)==0) {
						G[i].PB(v);
					}
				}
			}
//			cout<<bits<<" ============= "<<endl;
//			cout<<G<<endl;
			int ok=0;
			vis = VI(N);
			int roots = 0;
			REP(i, N) {
				if( ((bits>>i)&1) ) continue;
				
				if(!vis[i]) {
					roots++;
					hi.clear();
					int sub = full(i, -1, G);
//					cout<<"DFS "<<i<<" "<<hi<<endl;
					if(hi[0]+hi[2]==1 && hi[1]+hi[3]==sub-1) {ok=1;}
				}
			}
			if(roots!=1) ok=0;
//			if(ok) cout<<" -> "<<POPCOUNT(bits)<<" OK "<<endl;
			if(ok) ans=min(ans, POPCOUNT(bits));
		}
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		break;
	}
	return 0;
}



