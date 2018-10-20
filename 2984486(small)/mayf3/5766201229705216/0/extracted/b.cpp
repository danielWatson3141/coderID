//label : graph
//By myf
//#pragma comment(linker, "/STACK:16777216")  //C++
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <complex>
#include <list>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, l, r) for(int i = (l) ; i < (r); i++)
#define MP make_pair
#define PB push_back
#define Cls(x) memset(x,0,sizeof x)
#define Print(n,x) for(int i=0;i<(n);i++) cout<<x<<" ";cout<<endl;
#define foreach(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++) //G++
#define F first
#define S second
#define X real()
#define Y imag()
#define Sqr(x) (x)*(x)
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef long long LL;
typedef complex<double> Point;
typedef Point Vec;
typedef pair<Point, Point> Line;
//typedef complex<double> Comp;

const int N = 1000000;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-6;

typedef pair<int, int> pii;

#define get_pii(now, x) ((x > now.F) ? MP(x, now.F) : (x > now.S) ? MP(now.F, x) : now)

int n;
vector<int> E[N];
int dp[N];
pii v[N];

int dfs(int x, int f){
	dp[x] = 1;
	v[x] = MP(0, 0);
	pii &now = v[x];
	rep(i, E[x].size()){
		int y = E[x][i];
		if (y == f) continue;
		now = get_pii(now, dfs(y, x));
	}
	if (now.S > 0) dp[x] += now.F + now.S;
	return dp[x];
}

int main(){
	int T;
	scanf("%d", &T);
	rep(cas, T){
		scanf("%d", &n);
		rep(i, n){
			E[i].clear();
		}
		rep(i, n - 1){
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			E[x].PB(y);
			E[y].PB(x);
		}
		int ans = n - 1;
		rep(i, n){
			ans = min(ans, n - dfs(i, -1));
		}
		printf("Case #%d: %d\n", cas + 1, ans);
	}
	return 0;
}
