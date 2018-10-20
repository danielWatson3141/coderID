#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> e[1010];
bool isSearch[1010];
int sz[1010];
int keep[1010];
int par[1010];
int runSize(int now){
	sz[now]=1;
	isSearch[now]=1;
	for(int i = 0 ; i < e[now].size() ; ++ i ){
		if(!isSearch[e[now][i]])sz[now]+=runSize(e[now][i]);
	}
	return sz[now];
}
int  trySolve(int now){
	int ctr=0;
	int ret=0;
	isSearch[now]=1;
	vector<int> vt;
	for(int i = 0 ; i < e[now].size() ; ++ i ){
		if(isSearch[e[now][i]])continue;
		par[e[now][i]]=now;
		vt.push_back(trySolve(e[now][i])-sz[e[now][i]]);
		ret+=sz[e[now][i]];
	}
	sort(vt.begin(),vt.end());
	if(vt.size()>=2){
		ret+=vt[0]+vt[1];
	}
	return ret;
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i <= 1000 ; ++ i ) e[i].clear();
	
	for(int i = 1 ; i < n ; ++ i ){
		int a,b;
		scanf("%d %d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans=10000;
	for(int i = 1 ; i <= n ; ++ i ){
		memset(isSearch,0,sizeof(isSearch));
		memset(sz,0,sizeof(sz));
		runSize(i);
		memset(isSearch,0,sizeof(isSearch));
		par[i]=i;
		ans=min(ans,trySolve(i));
	}
	printf("%d\n",ans);

}

int main(){
	int t;
	scanf("%d",&t);
	for(int i = 1 ; i <= t ; ++ i ){
		printf("Case #%d: ",i);
		solve();
	}
}
