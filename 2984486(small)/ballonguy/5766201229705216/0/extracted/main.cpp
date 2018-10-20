#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<sstream>
#include<ctime>
using namespace std;

typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
const int inf = 1000000000;
const int MOD = 1000000007;
const double pi = acos(-1.0);

vector<int>g[1111];
bool used[1111];
int fath[1111];
int dp[1111];
int cnt[1111];

void dfs(int v) {
	used[v]=true;
	int ch=0;
	dp[v]=inf;
	cnt[v]=1;
	vector<int> f;
	FOR(i,0,sz(g[v])-1) {
		int to = g[v][i];
		if(used[to]) fath[v]=to;else {
			dfs(to);
			ch++;
			cnt[v]+=cnt[to];
			f.pb(to);
		}
	}
	if(ch==0) dp[v]=0;
	if(ch==1) dp[v]=cnt[f[0]];else {
			FOR(i1,0,sz(f)-1)FOR(i2,i1+1,sz(f)-1) {
				int cur = cnt[v]-1-cnt[f[i1]]-cnt[f[i2]]+dp[f[i1]]+dp[f[i2]];
				dp[v]=min(dp[v], cur);
			}
	}
}

void get() {
	int n;cin>>n;
	FOR(i,1,n) g[i].clear();
	FOR(i,1,n-1) {
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans=inf;
	FOR(root,1,n) {
		memset(used, false, sizeof(used));
		fath[root]=0;
		dfs(root);
		ans=min(ans, dp[root]);
	}
	cout<<ans<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	FOR(tt,1,t)
	{
		cout << "Case #" << tt << ": ";
		get();
	}
}
