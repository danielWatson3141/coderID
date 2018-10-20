#include <bits/stdc++.h>
#define mpr std::make_pair
#define lg std::__lg
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
typedef double LD;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
const int N=1010;
using namespace std;
vector<int>G[N];
int n;
int dp[N],sz[N];
const int INF=1<<20;
void DFS(int x,int par){
	vector<int>V;
	sz[x]=1;
	dp[x]=0;
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=par){
			DFS(G[x][i],x);
			sz[x]+=sz[G[x][i]];
			V.push_back(sz[G[x][i]]-dp[G[x][i]]);
		}
	if(V.size()==0)return;
	if(V.size()==1){
		dp[x]=sz[x]-1;
	}
	else if(V.size()==2){
		for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=par){
			dp[x]+=dp[G[x][i]];
		}
	}
	else{
		sort(V.begin(),V.end());
		dp[x]=sz[x]-1-V[V.size()-1]-V[V.size()-2];
	}
}
int makeDP(int r){
	DFS(r,-1);
	//printf("%d:%d\n",r,dp[r]);
	return dp[r];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T,w=1;RI(T);
	while(T--){
		RI(n);
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			RI(x);RI(y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int ans=INF;
		for(int i=1;i<=n;i++){
			int ret=makeDP(i);
			if(ans>ret)ans=ret;
		}
		printf("Case #%d: %d\n",w++,ans);
	}
	return 0;
}

