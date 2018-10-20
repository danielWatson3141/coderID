#include <bits/stdc++.h>
using namespace std;
int i=0,dp[1005],t,n,p1,p2;
vector <int> adj[1005];
int pa[1005];
int f(int v){
	if(dp[v]>=0) return dp[v];
	if(adj[v].size()<=2) return dp[v]=1;
	int ans1=0,ans2=0;
	for(int x=0;x<adj[v].size();x++){
		if(adj[v][x]==pa[v]) continue;
		pa[adj[v][x]]=v;
		int temp=f(adj[v][x]);
		if(temp>=ans1){
			ans2=ans1;
			ans1=temp;
		}
		else if(temp>ans2) ans2=temp;
	}
	return dp[v]=ans1+ans2+1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int x=0;x<n;x++) adj[x].clear();
		for(int x=0;x<n-1;x++){
			scanf("%d %d",&p1,&p2);
			adj[p1-1].push_back(p2-1);
			adj[p2-1].push_back(p1-1);
		}
		int ans=1;
		for(int x=0;x<n;x++){
			if(adj[x].size()<=1) continue;
			memset(pa,-1,sizeof(pa));
			memset(dp,-1,sizeof(dp));
			int ans1=0,ans2=0;
			for(int y=0;y<adj[x].size();y++){
				pa[adj[x][y]]=x;
				int temp=f(adj[x][y]);
				if(temp>=ans1){
					ans2=ans1;
					ans1=temp;
				}
				else if(temp>ans2) ans2=temp;
			}
			ans=max(ans,1+ans1+ans2);
		}
		printf("Case #%d: %d\n",++i,n-ans);
	}
	return 0;
}
