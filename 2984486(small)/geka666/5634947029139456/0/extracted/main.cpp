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

int n,l;

int brute(vector<string> a,vector<string> b){
	sort(all(b));
	int ans = INF;
	REP(mask,0,1<<l){
		vector<string> c;
		REP(i,0,n){
			string s = a[i];
			REP(i,0,l) if ((mask>>i)&1) s[i]^=1;
			c.pb(s);
		}
		sort(all(c));
		bool ok = true;
		REP(i,0,n) if(c[i] != b[i]){
			ok = false;
			break;
		}
		if (ok){
			int cnt = 0;
			REP(i,0,l) if ((mask>>i)&1) cnt++;
			ans=min(ans,cnt);
		}
	}
	return ans;
}

bool ok(vector<string> a,vector<string> b){
	return false;
}

void solve(){
	cin>>n>>l;
	vector<string> a,b;
	REP(i,0,n){
		string s; cin>>s;
		a.pb(s);
	}
	REP(i,0,n){
		string s; cin>>s;
		b.pb(s);
	}
	//sort(all(a));
	//sort(all(b));
	int ans = brute(a,b);
	if (ans == INF){
		cout<<"NOT POSSIBLE"<<endl;
	}else{
		cout<<ans<<endl;
	}
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