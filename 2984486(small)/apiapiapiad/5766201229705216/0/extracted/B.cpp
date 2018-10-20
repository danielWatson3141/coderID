#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) printf("Case #%d: %d\n",++__,x)
#define POP(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
int sz[N],dp[N];
int u,v,_,__,n,ans;
VI son[N],e[N];
void dfs(int u,int f) {
	sz[u]=1;
	son[u].clear();
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (v==f) continue;
		son[u].pb(v);
		dfs(v,u);
	}
	rep(i,0,SZ(son[u])) sz[u]+=sz[son[u][i]];
	dp[u]=sz[u]-1;
	if (SZ(son[u])>=2) {
		dp[u]=sz[u]-1;
		int a[3]={dp[son[u][0]]-sz[son[u][0]],dp[son[u][1]]-sz[son[u][1]],0};
		rep(i,2,SZ(son[u])) {
			int v=son[u][i];
			a[2]=dp[v]-sz[v];
			sort(a,a+3);
		}
		dp[u]=min(dp[u],sz[u]-1+a[0]+a[1]);
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) e[i].clear();
		rep(i,1,n) {
			scanf("%d%d",&u,&v);
			e[u].pb(v);e[v].pb(u);
		}
		ans=n-1;
		rep(i,1,n+1) {
			dfs(i,0);
			ans=min(ans,dp[i]);
		}
		PRINTC(ans);
	}
}
