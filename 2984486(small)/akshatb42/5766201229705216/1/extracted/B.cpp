#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stack>
#include<assert.h>
#include<limits.h>
#define tr(i) for(typeof(i.begin()) it=i.begin(); it!=i.end();it++)
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,s,n) for(int i=s;i<n;i++)
#define s(n) scanf("%d",&n)
#define XX first
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define YY second.first
#define ZZ second.second
#define fill(a,b) memset(a,b,sizeof(a))
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define SZ(x) (int)(x.size())
#define lin(val,j) (DP[j]-val*D[j])
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MN 1000
int N;
vector<vector<int> > ad;
int par[MN],dp[MN],sz[MN],ch[MN];
int sdfs(int i)
{
	sz[i]=1,ch[i]=0;
	tr(ad[i])
	{
		if(par[i]==*it) continue;
		par[*it]=i;
		ch[i]++;
		sz[i]+=sdfs(*it);
	}
	return sz[i];
}
void dfs(int i)
{
	dp[i]=0;
	if(ch[i]==0) return;
	if(ch[i]==1)
	{
		tr(ad[i])
		{
			if(par[i]==*it) continue;
			dp[i]=sz[*it];
		}
		return;
	}
	int tot=0;
	vector<int> sub;
	tr(ad[i])
	{
		if(par[i]==*it) continue;
		dfs(*it);
		tot+=sz[*it];
		sub.pb(sz[*it]-dp[*it]);
	}
	sort(all(sub));
	int S=sub.size();
	dp[i]=tot-sub[S-1]-sub[S-2];
}
int main()
{	
	int T; s(T);
	REP(c,T)
	{
		s(N);
		ad.clear();
		ad.resize(N);
		int a,b;
		int mn=N;
		REP(i,N-1)
		{
			s(a); s(b);
			a--; b--;
			ad[a].pb(b);
			ad[b].pb(a);
		}
		REP(i,N)
		{
			REP(j,N) par[j]=-1,dp[i]=0,sz[i]=0,ch[i]=0;;
			sdfs(i);
			dfs(i);
//			cout<<dp[i]<<" "<<i+1<<endl<<endl<<endl;
			mn=min(mn,dp[i]);
		}
		printf("Case #%d: %d\n",c+1,mn);
	}
	return 0;
}
