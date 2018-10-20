#include<bits/stdc++.h>
using namespace std;
vector<int> e[1024];
int f[1024];
void dfs(int u,int p=-1){
	int c=0,m1=-1,m2=-1;
	f[u]=1;
	for(int v:e[u])if(v!=p){
		dfs(v,u);
		++c;
		if(f[v]>m1){m2=m1;m1=f[v];}
		else if(f[v]>m2){m2=f[v];}
	}
	if(c>=2)f[u]=m1+m2+1;
}
int solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,a,b;i<n;++i) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans = 0;
	for(int r=1;r<=n;++r) {
		dfs(r);
		ans=max(ans,f[r]);
	}
	return n-ans;
}
int main(){
	int T;
	cin >> T;
	for(int i=1;i<=T;++i)
		cout << "Case #"<< i<<": " << solve() << endl;
}
