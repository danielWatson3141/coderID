#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define NAME "B-small-attempt0"
using namespace std;
typedef pair<int,int> pii;
#define xx first
#define yy second;
int T;
int n;
bool vis[1005];
vector<int> e[1005];
int dfs(int v) {
	vis[v]=1;
	vector<int> nodes;
	for(int i=0;i<(int)e[v].size();i++) {
		int u=e[v][i];
		if(!vis[u]) {
			nodes.push_back(dfs(u));
		}	
	}
	if(nodes.size()<=1) return 1;
	int ans=0;
	for(int i=0;i<(int)nodes.size();i++) {
		for(int j=i+1;j<(int)nodes.size();j++) {
			ans=max(nodes[i]+nodes[j],ans);
		}
	}
	return ans+1;
}

int main(){
	freopen(NAME".in","rt",stdin);
	freopen(NAME".out","wt",stdout);
	cin>>T;
	for(int I=1;I<=T;I++) {
		printf("Case #%d: ",I);
		cin>>n;
		int x,y;
		for(int i=0;i<n-1;i++) {
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans=n-1;
		for(int root=1;root<=n;root++) {
			for(int i=1;i<=n;i++) vis[i]=0;
			ans=min(ans,n-dfs(root));
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) e[i].erase(e[i].begin(),e[i].end());
	}
	return 0;
}