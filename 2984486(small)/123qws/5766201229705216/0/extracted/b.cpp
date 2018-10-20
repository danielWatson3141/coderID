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
vector<int> adj[100];
bool ban[100], vis[100];
int bitcount(int x) {
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
bool dfs(int u, int f) {
    vis[u] = true;
    int cnt = 0;
    for (int i = 0; i < adj[u].size(); i++) {
	int v = adj[u][i];
	if (v == f || ban[v-1]) continue;
	cnt++;
	if (!dfs(v, u)) return false;
    }
    return (cnt == 0 || cnt == 2);
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
	memset(ban, 0, sizeof(ban));
	int ans = n;
	for (int w = 0; w < (1<<n); w++) {
	    memset(ban, 0, sizeof(ban));
	    for (int i = 0; i < n; i++)
		if (w & (1<<i))
		    ban[i] = true;

	    bool succ = false;
	    
	    for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if (!ban[i-1] && dfs(i, 0)) {
		    succ = true;
		    for (int j = 1; j <= n; j++)
			if (!ban[j-1] && !vis[j])
			    succ = false;
		    break;
		}
	    }
	    if (succ)
	    ans = min(ans, bitcount(w));
	    
	}
	    
	cout << "Case #" << ca << ": ";
	cout << ans << endl;
    }
    return 0;
}

