#include <bits/stdc++.h>




using namespace std;




#define fr(i,a,b) for(int i=a; i < b; ++i)
const int oo = 0x3f3f3f3f;
typedef pair<int,int> pii;
#define F first
#define S second
#define mp make_pair
vector<int> inc[1010];
vector<pii> rs[1010];
int tam[1010];
int t,n;
bool cmp(pii a, pii b){
	return a.F - a.S < b.F - b.S;
}

int dfs(int a, int b){
	int ret = oo;
	tam[a] = 1;
	fr(i,0,inc[a].size()){
		if(inc[a][i] == b) continue;
		int aux = dfs(inc[a][i],a);
		rs[a].push_back(mp(aux,tam[inc[a][i]]));
		tam[a] += tam[inc[a][i]];
	}
	if(a == b){
		if(inc[a].size() == 0) return 0;
		else if(inc[a].size() == 1) return tam[a] - 1;
	}
	else{
		if(inc[a].size() <= 1) return 0;
		if(inc[a].size() == 2){
			return tam[a]-1;
		}
	}
	sort(rs[a].begin(),rs[a].end(),cmp);
	return min(tam[a]-1, tam[a]-1 + rs[a][0].F-rs[a][0].S + rs[a][1].F-rs[a][1].S);
}



int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		fr(i,0,1010) inc[i].clear(), rs[i].clear();
		scanf("%d",&n);
		fr(i,0,n-1){
			int a,b;
			scanf("%d %d",&a,&b);
			a--;
			b--;
			inc[a].push_back(b);
			inc[b].push_back(a);
		}
		int ans = oo;
		fr(i,0,n){
			fr(j,0,n) rs[j].clear();
			int aux = dfs(i,i);
			ans = min(ans,aux);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}













