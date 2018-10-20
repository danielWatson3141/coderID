#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxN=200;
const int maxL=50;
string s[maxN],tar[maxN];
int ans,n,l;
void solve();
int main(){
	int T,i;
	cin>>T;
	for(i=1;i<=T;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
void dfs(int x,int cost){
	string temp[maxN];
	int i;
	if(x==l){
		sort(s,s+n);
		for(i=0;i<n;i++)
			if(s[i]!=tar[i]) return;
		if(ans>cost) ans=cost;
		return;
	};
	dfs(x+1,cost);
	for(i=0;i<n;i++) temp[i]=s[i];
	for(i=0;i<n;i++)
		if(s[i][x]=='0') s[i][x]='1';
		else s[i][x]='0';
	dfs(x+1,cost+1);
	for(i=0;i<n;i++) s[i]=temp[i];
}
void solve(){
	int i,j;
	cin>>n>>l;
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<n;i++) cin>>tar[i];
	sort(tar,tar+n);
	ans=maxN;
	dfs(0,0);
	if(ans==maxN) cout<<"NOT POSSIBLE"<<endl;
	else cout<<ans<<endl;
}
