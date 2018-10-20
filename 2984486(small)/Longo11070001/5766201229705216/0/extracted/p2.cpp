#include <iostream>
#include <cstring>
using namespace std;
const int maxN=1010;
int f[maxN],pt[maxN],lk[maxN*2],vt[maxN*2];
int n;
int solve();
int main(){
	int i,T;
	cin>>T;
	for(i=1;i<=T;i++)
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	return 0;
}
void dfs(int u,int fa){
	int i,son,first,second;
	first=second=0;
	for(i=pt[u];i;i=lk[i])if(vt[i]!=fa){
		dfs(vt[i],u);
		if(f[vt[i]]>first) second=first,first=f[vt[i]];
		else 
		if(f[vt[i]]>second) second=f[vt[i]];
	}
	if(!first||!second) f[u]=1;
	else f[u]=first+second+1;
}
int solve(){
	int e,u,v,i,j,ans;
	memset(pt,0,sizeof(pt));
	e=1;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>u>>v;
		vt[e]=v; lk[e]=pt[u]; pt[u]=e++;
		vt[e]=u; lk[e]=pt[v]; pt[v]=e++;
	}
	ans=0;
	for(i=1;i<=n;i++){
		dfs(i,-1);
		if(ans<f[i]) ans=f[i];
	}
	return n-ans;
}
