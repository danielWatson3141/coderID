//Template

// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()

#define N 1024
vi adj[N];
int sub[N], cost[N];
int dp[1024][3];
int solve(vi &c1, vi &c2) {
	int n = c1.sz;
	dp[n][2] = 0;
	dp[n][0] = dp[n][1] = imax/10;
	for(int i=n-1; i>=0; i--) rep(j, 3) {
		//dont take
		dp[i][j] = dp[i+1][j] + c2[i];
		//take
		if(j != 2) dp[i][j] = min(dp[i][j], dp[i+1][j+1] + c1[i]);
	}
	return dp[0][0];
}

void dfs(int cur, int prev) {
	sub[cur] = 1;
	cost[cur] = 0;
	vi c1, c2;
	rep(i, adj[cur].sz) if(adj[cur][i] != prev) {
		dfs(adj[cur][i], cur);
		c1.pb(cost[adj[cur][i]]); //cost to take
		c2.pb(sub[adj[cur][i]]); //dont take cost
		sub[cur] += sub[adj[cur][i]];
	}
	if(c1.sz == 0) cost[cur] = 0;
	else if(c1.sz == 1) cost[cur] = sub[cur]-1;
	else cost[cur] = solve(c1, c2);
}

int main() {
	int t; gi(t);
	rep(T, t) {
		int n; gi(n);
		rep(i, n) adj[i].clear();
		rep(i, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
		}
		int ans = imax;
		rep(i, n) {
			dfs(i, -1);
			ans = min(ans, cost[i]);
		}
		printf("Case #%d: %d\n", T+1, ans);
	}
}