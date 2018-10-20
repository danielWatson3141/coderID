//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int T, n, ret;
vector<int> g[1010];
int sz[1010];
pii e[1010];

void dfs1(int v, int p){
    sz[v] = 1;
    rep(i, g[v].size()) if(g[v][i] != p){
	dfs1(g[v][i], v);
	sz[v] += sz[g[v][i]];
    }
}

int dfs(int v, int p){
    int s = (p == -1 ? (int)g[v].size() : (int)g[v].size() - 1);

    if(s < 2){
	int x = 0;
	rep(i, g[v].size()) if(g[v][i] != p) x += sz[g[v][i]];
	return x;
    }

    vector<int> vv;
    rep(i, g[v].size()) if(g[v][i] != p) vv.pb(dfs(g[v][i], v) - sz[g[v][i]]);
    sort(vv.begin(), vv.end());
    return sz[v] - 1 + vv[0] + vv[1];
}

int main(){
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t){
	printf("Case #%d: ", t);
	ret = 1000;

	scanf("%d", &n);
	rep(i, n) g[i].clear();

	rep(i, n - 1){
	    scanf("%d %d", &e[i].fi, &e[i].se);
	    --e[i].fi; --e[i].se;
	    g[e[i].fi].pb(e[i].se);
	    g[e[i].se].pb(e[i].fi);
	}

	//r = root
	
	rep(r, n){
	    dfs1(r, -1);
	    ret = min(ret, dfs(r, -1));
	}
	printf("%d\n", ret);
    }

    return 0;
}
