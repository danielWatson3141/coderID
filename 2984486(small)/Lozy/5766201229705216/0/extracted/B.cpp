#include <iostream> 
#include <fstream>
#include <sstream> 
#include <cstring>
#include <string> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <utility> 
#include <functional> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) FOR(i,0,a)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr) 
#define X first
#define Y second
#define PB push_back
#define MP make_pair
int dp[1111],a,b,sz[1111],n,rt;
vector<int> G[1111],nxt[1111];
bool vis[1111];
int dfssz(int k){
	if(sz[k])return sz[k];
	vis[k]=true;
	sz[k]=1;
	for(int x:G[k]){
		if(!vis[x]){
			nxt[k].PB(x);
			sz[k]+=dfssz(x);
		}
	}
	return sz[k];
}
int dfs(int k){
	if(dp[k]!=-1)return dp[k];
	int t=nxt[k].size();
	if(t==0)return 0;
	if(t==1)return dp[k]=1+dfs(nxt[k][0]);
	if(t==2)return dp[k]=dfs(nxt[k][0])+dfs(nxt[k][1]);
	dp[k]=10000;
	for(int i=0;i<nxt[k].size();++i)for(int j=i+1;j<nxt[k].size();++j){
		int rr=0;
		for(int v=0;v<nxt[k].size();++v){
			if(v!=i&&v!=j){
				rr+=sz[nxt[k][v]];
			}else rr+=dfs(nxt[k][v]);
		}
		dp[k]=min(dp[k],rr);
	}
	return dp[k];
}
int main() {
	int T;scanf("%d",&T);
	rep(t,T){
		scanf("%d",&n);
		rep(i,1111)G[i].clear();
		rep(i,n-1){
			scanf("%d%d",&a,&b);
			G[a].PB(b);G[b].PB(a);
		}
		int best=100000;
		for(rt=1;rt<=n;++rt){
			memset(dp,-1,sizeof(dp));
			memset(vis,0,sizeof(vis));
			rep(i,1111)nxt[i].clear();
			memset(sz,0,sizeof(sz));
			dfssz(rt);
			int t=dfs(rt);
			best=min(best,t);
		}
		printf("Case #%d: %d\n", t+1,best);
	}
 	return 0;
}
