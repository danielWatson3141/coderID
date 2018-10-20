#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN=15;
string switches[MAXN], target[MAXN];
int n, m;
bool checks(){
	sort(switches, switches+n);
	for(int i=0; i<n; i++)
		if(switches[i]!=target[i])return false;
	return true;
}
int ans;
void dfs(int pt, int times){
	if(times>=ans)return ;
	if(pt==m){
		if(checks())ans=times;
		return ;
	}
	dfs(pt+1, times);
	for(int i=0; i<n; i++){
		if(switches[i][pt]=='0')switches[i][pt]='1';
		else switches[i][pt]='0';
	}
	dfs(pt+1, times+1);
	for(int i=0; i<n; i++){
		if(switches[i][pt]=='0')switches[i][pt]='1';
		else switches[i][pt]='0';
	}

}
int main(){
	int ncase;
	cin>>ncase;
	for(int id=1; id<=ncase; id++){
		scanf("%d%d", &n, &m);
		//if(id==87)cout<<n<<" "<<m;
		for(int i=0; i<n; i++){
			switches[i].clear();
			cin>>switches[i];
			//if(id==87)cout<<switches[i]<<endl;
		}
		for(int i=0; i<n; i++){
			target[i].clear();
			cin>>target[i];
			//if(id==87)cout<<target[i]<<endl;
		}
		sort(target, target+n);
		ans=1000000000;
		dfs(0, 0);
		printf("Case #%d: ", id);
		if(ans!=1000000000){
			printf("%d\n", ans);
		}
		else puts("NOT POSSIBLE");
	}
}