#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <cassert>
#include <ctime>
#include <list>
#include <bitset>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <complex>
//#include <tuple>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
template<typename T> inline T Abs(T a){ return a>0 ? a : -a; }
template<typename T> inline T sqr(T a){ return a*a; }
template<typename T> inline void relaxMin(T &a,T b){ if (b<a) a=b; }
template<typename T> inline void relaxMax(T &a,T b){ if (b>a) a=b; }

#define _(a,val) memset(a,val,sizeof a);
#define REP(i, a, b) for(int i(a),_bb(b); i < _bb; ++i)
//#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
 
const int INF = (int)1E9;
//const int INF = INT_MAX/2-1;
const long double EPS = 1E-6;
const long double PI = 3.1415926535897932384626433832795;
#define y1 idfgoseincdjkg
typedef vector<int> vint;
typedef pair<int,int> pii;

#undef assert
#define assert(expr){if (!(expr)) { ++*(char*)0; } }

vector< vector<int> > gr;

bool cmp(pii a,pii b){
	return (a.first-a.second) > (b.first-b.second);
}

pii dfs(int v,int par = -1){
	vector<pii> ans;
	REP(i,0,gr[v].size()){
		int to = gr[v][i];
		if (to == par) continue;
		pii cnt = dfs(to,v);
		ans.pb(cnt);
	}
	if (ans.size() == 0) return mp(1,0);
	if (ans.size() == 1) return mp(ans[0].first+1,ans[0].first);
	int s = 0;
	REP(i,0,ans.size()) s+=ans[i].first;
	sort(all(ans),cmp);
	return mp(s+1,s-(ans[0].first-ans[0].second)-(ans[1].first-ans[1].second));
}

void solve(){
	int n; cin>>n;
	gr.clear();
	gr.assign(n,vector<int>());
	REP(i,0,n-1){
		int a,b; cin>>a>>b;
		a--; b--;
		gr[a].pb(b); gr[b].pb(a);
	}

	int ans = INF;
	REP(i,0,n) ans=min(ans,dfs(i).second);

	cout<<ans<<endl;
}



#define TASK "circles"
int main(){
	//freopen("input.txt", "wt", stdout);
	//freopen("input.txt", "wt", stdin);
#ifdef acm
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	freopen("error.txt", "wt", stderr);
#else
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	//freopen(TASK".in", "rt", stdin);
	//freopen(TASK".out", "wt", stdout);
#endif
	//srand(time(0));
	//srand(0xA1B2C3D4);

	//pre();
	int tc; scanf("%d\n",&tc);
	for(int t=1;t<=tc;t++){
		printf("Case #%d: ",t);
		solve();
	}
	//solve();


#ifdef acm
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);
#endif
	return 0;
}