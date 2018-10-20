#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1e8;

int N;
vector <int> V[MAXN];

int dp[MAXN],pass[MAXN];
int sum[MAXN];
int maxh;

void clearinput(){
	memset(sum,0,sizeof sum);
	for(int i=0;i<MAXN;i++) V[i].clear();
}

void input(){
	clearinput();
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
}

void buildsum(int u,int p){
	sum[u] = 1;
	for(int i=0;i<V[u].size();i++){
		int v = V[u][i];
		if(v == p) continue;
		buildsum(v,u);
		sum[u] += sum[v];
	}	

	// printf("sum[%d] = %d\n",u,sum[u]);
}

int run(int u,int p,int h){
	if(pass[u]) return dp[u];
	pass[u] = true;

	int child = 0;

	int val1,val2,id1,id2;
	int all = 0;
	for(int i=0;i<V[u].size();i++){
		int v = V[u][i];
		if(v == p) continue;
		child++;

		int xx = sum[v];
		all += xx;
	}

	// printf("all [%d][%d] = %d\n",u,p,all);

	// printf("[%d] => [%d]\n",u,child);
	if(child == 2){
		dp[u] = 0;
		for(int i=0;i<V[u].size();i++){
			int v = V[u][i];
			if(v == p) continue;
			dp[u] += run(v,u,h+1);
		}
		return dp[u];
	}else if(child == 0){
		return dp[u] = 0;
	}else if(child == 1){
		dp[u] = 0;
		for(int i=0;i<V[u].size();i++){
			int v = V[u][i];
			if(v == p) continue;
			dp[u] += sum[v];
		}
		return dp[u];
	}else{
		dp[u] = INF;
		for(int i=0;i<V[u].size();i++) for(int j=i+1;j<V[u].size();j++){
			if(V[u][i] == p || V[u][j] == p) continue;
			dp[u] = min(dp[u], all - sum[V[u][i]] - sum[V[u][j]] + run(V[u][i],u,h+1) + run(V[u][j],u,h+1) );
		}
		// printf("==> dp[%d] = %d %d %d\n",u,dp[u],all,);
		return dp[u];
	}
}

int ans;
void solve(){
	ans = INF;
	for(int i=1;i<=N;i++){
		memset(pass,0,sizeof pass);
		memset(dp,0,sizeof dp);
		buildsum(i,-1);
		ans = min(ans,run(i,-1,0));

		// for(int j=1;j<=N;j++) printf("dp[%d] = %d\n",j,dp[j]);
		// printf("run(%d) = %d\n",i,run(i,-1,0));
	}
	printf("%d\n",ans);
}

int main(){
	freopen("B-large.in.txt","r",stdin);
	freopen("B2.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		input();
		solve();
	}
	return 0;
}