#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;

#define DB(x) cerr<<#x<<"="<<x<<" "
#define DBN(x) cerr<<#x<<"="<<x<<"\n"
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define INF 1000000000
#define EPS (double)1e-9
#define MOD 1000000007
#define PI 3.14159265358979328462
int n;
vector<int> adj[1005];
int dp1[1005];			// not delete
int dp2[1005];			// delete
void upd(int &a, int b) {
    if (a < 0) a = b;
    else if (b < a) a = b;
}
int dp[1005][3];
int dfs(int u, int f) {
    dp1[u] = 0;
    dp2[u] = 1;
    vector<int> a, b;
    int cnt = 0;
    for (int i = 0; i < adj[u].size(); i++) {
	int v = adj[u][i];
	if (v == f) continue;
	dfs(v, u);
	dp2[u] += dp2[v];
	dp1[u] += dp2[v];
	a.pb(dp1[v]);
	b.pb(dp2[v]);
	cnt++;
    }


    if (cnt >= 2) {
	for (int i = 0; i < cnt; i++)
	    for (int j = 0; j < 3; j++)
		dp[i][j] = -1;

	dp[0][0] = b[0];
	dp[0][1] = a[0];
	for (int i = 0; i < cnt-1; i++)
	    for (int k = 0; k <= 2; k++) {
		if (dp[i][k] == -1) continue;
		if (k < 2) upd(dp[i+1][k+1], dp[i][k] + a[i+1]);
		upd(dp[i+1][k], dp[i][k] + b[i+1]);
	    }
    
	dp1[u] = min(dp1[u], dp[cnt-1][2]);
    }
    return dp1[u];
}


int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 0; i < n-1; i++) {
	    int x, y; cin >> x >> y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	int ans = n;

	for (int i = 1; i <= n; i++) {
	    ans = min(ans, dfs(i, 0));
	}
	
	cout << "Case #" << ca << ": ";
	cout << ans << endl;
    }
    return 0;
}

