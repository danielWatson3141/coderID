#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,ans,a,b,num;
vector<int> g[1001];
int vis[1001],dp[1001],sz[1001];

int dfs1(int i) {
	vis[i]=1;
	sz[i]=1;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0)
			sz[i]+=dfs1(g[i][j]);
	}
	// cout<<i<<" "<<sz[i]<<"--\n";
	return sz[i];
}

int dfs(int i) {
	vis[i]=1;
	dp[i]=sz[i]-1;

	set<ii> s;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0)
			s.insert(ii(sz[g[i][j]]-dfs(g[i][j]),j));
	}

	// cout<<s.size()<<endl;

	if((int)(s.size())>1) {
		// cout<<"man\n";
		set<ii>::reverse_iterator it=s.rbegin();
		int val=it->first;
		it++;
		val+=it->first;
		dp[i]=min(dp[i],dp[i]-val);
	}
	// cout<<i<<" "<<dp[i]<<"   s \n";
	return dp[i];
}

int main() {
	// freopen("inp","r",stdin);
	freopen("B-large.in", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	inp(t);

	for(int c=1;c<=t;c++) {
		// cout<<"test :  "<<c<<endl;
		inp(n);

		for(int i=1;i<=n;i++)
			g[i].clear();

		for(int i=1;i<n;i++) {
			inp(a);
			inp(b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ans=n-1;

		// cout<<ans<<endl;
		for(int i=1;i<=n;i++) {
			memset(vis,0,sizeof vis);
			num=dfs1(i);

			memset(vis,0,sizeof vis);
			ans=min(ans,dfs(i));
			// cout<<i<<" "<<dp[i]<<" "<<ans<<endl;
		}

		printf("Case #%d: %d\n",c,ans);
	}




	return 0;
}