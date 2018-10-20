#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
vi g[1111];
int dp[1111];
void dfs(int u,int f)
{
	int i,j,k;
	vi c;
	foreach(e,g[u])
	{
		if (*e==f)continue;
		dfs(*e,u);
		c.pb(dp[*e]);
	}
	if (sz(c)<=1)
	{
		dp[u]=1;
	}
	else 
	{
		sort(all(c),greater<int>());
		dp[u]=c[0]+c[1]+1;
	}
}
int main()
{
	freopen("C:\\competition\\R1A\\B-large.in","r",stdin);
	freopen("C:\\competition\\R1A\\B.out","w",stdout);
	int i,j,k;
	int cas,cc=0,n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0;i<1111;i++)g[i].clear();
		for (i=0;i<n-1;i++)
		{
			int q,w;
			scanf("%d%d",&q,&w);
			g[q].pb(w);g[w].pb(q);
		}
		int ans=0;
		for (i=1;i<=n;i++)
		{
			clr(dp);
			dfs(i,-1);
			ans=max(ans,dp[i]);
		}
		printf("Case #%d: %d\n",++cc,n-ans);
	}
	return 0;
}
