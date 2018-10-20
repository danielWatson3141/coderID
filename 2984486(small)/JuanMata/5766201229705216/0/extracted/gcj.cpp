#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rev(i,n) REV(i,n,0)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define GI ({ int x; scanf("%d",&x); x; })
#define GLL ({ LL x; scanf("%lld",&x); x; })
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define inf (int)(1e9)
#define linf (LL)(1e18)
#define eps (double)(1e-9)
#define leps (LD)(1e-18)
#define PI (double)(3.141592653589793238)


int n;
int x[1005],y[1005];
VI adj[1005];
bool vis[1005];

bool dfs(int curr,int root)
{
	if(vis[curr])
		return 1;
	vis[curr]=1;
	int c=adj[curr].size()-(curr!=root);
	bool ret=(c==0||c==2);
	rep(i,adj[curr].size())
		ret&=dfs(adj[curr][i],root);
	return ret;
}

bool check(int mask)
{
	REP(i,1,n+1)
		adj[i].clear();
	rep(i,n)
		if((mask&(1<<x[i]))&&(mask&(1<<y[i])))
		{
			adj[x[i]].PB(y[i]);
			adj[y[i]].PB(x[i]);
		}
	bool ret=0;
	REP(i,1,n+1)
		if(mask&(1<<i))
		{
			memset(vis,0,sizeof vis);
			bool curr=dfs(i,i);
			REP(j,1,n+1)
				if((mask&(1<<j))&&!vis[j])
					curr=0;
			ret|=curr;
		}
	return ret;
}

void solve(int t)
{
	cin>>n;
	rep(i,n-1)
		cin>>x[i]>>y[i];
	int ans=0;
	rep(i,(1<<n))
		if(check(i<<1))
			ans=max(ans,__builtin_popcount(i));
	cout<<"Case #"<<t<<": "<<n-ans<<'\n';
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	REP(i,1,t+1)
		solve(i);
	return 0;
}
