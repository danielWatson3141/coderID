#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l;
vector<string> so,sd;
bool f[50],possible;
int ans;
bool check(){
	vector<string> sf;
	for (int i=0;i<n;i++){
		string s="";
		for (int j=0;j<l;j++)
			if (f[j])
				s+=(so[i][j]=='0')?'1':'0';
			else
				s+=(so[i][j]=='0')?'0':'1';
		sf.push_back(s);
	}
	sort(sf.begin(),sf.end());
	for (int i=0;i<n;i++)
		if (sf[i]!=sd[i])
			return false;
	return true;
}
void dfs(int now,int flipped){
	if (now==l && flipped<ans && check()){
		possible=true;
		ans=flipped;
	}
	if (now>=l) return;
	if (flipped>ans) return;
	f[now]=false;
	dfs(now+1,flipped);
	f[now]=true;
	dfs(now+1,flipped+1);
	f[now]=false;
}
int main(){
	int t;
	cin >> t;
	for (int ti=0;ti<t;ti++){
		memset(f,false,sizeof(f));
		so.clear();
		sd.clear();
		cin >> n >> l;
		ans=l;
		possible=false;
		string temp;
		for (int i=0;i<n;i++){
			cin >> temp;
			so.push_back(temp);
		}
		for (int i=0;i<n;i++){
			cin >> temp;
			sd.push_back(temp);
		}
		sort(sd.begin(),sd.end());
		dfs(0,0);
		cout << "Case #" << ti+1 << ": ";
		if (possible)
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}
