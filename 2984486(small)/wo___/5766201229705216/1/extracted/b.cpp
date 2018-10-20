#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[1010];
int dp[1010];
int N;

int root;
int par[1010];
int sz[1010];
int ans;

void init(){
	for(int i=0;i<1010;i++) G[i].clear();
}

void dfs(int v,int p){
	par[v]=p;
	sz[v]=0;
	vector<int> tmp;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u!=p){
			dfs(u,v);
			sz[v]+=sz[u];
			tmp.push_back(dp[u]-sz[u]);
		}
	}
	int res=sz[v];
	sz[v]++;
	sort(tmp.begin(),tmp.end());
	if(tmp.size()==0){
		dp[v]=0;
	}else if(tmp.size()==1){
		dp[v]=sz[v]-1;
	}else{
		int x=tmp[0]+tmp[1];
		res+=x;
		dp[v]=res;
	}
}

int solve(int r){
	root=r;
	dfs(root,-1);
/*	printf("root=%d\n",r);
	for(int i=0;i<N;i++) printf("%d ",dp[i]);
	printf("\n");
	for(int i=0;i<N;i++) printf("%d ",sz[i]);
	printf("\n");*/
	return dp[r];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int datano=0;datano<T;datano++){
		scanf("%d",&N);
		init();
		for(int i=0;i<N-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans=N-1;
		for(int i=0;i<N;i++){
			ans=min(ans,solve(i));
		}
		printf("Case #%d: %d\n",datano+1,ans);
	}
	return 0;
}
