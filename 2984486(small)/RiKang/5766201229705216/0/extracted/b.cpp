#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>


using namespace::std;

int n,ans;
vector<int> ad[1005];
int d[1005];
int c[1005];
bool chk[1005];

void dfs1(int v){
	chk[v]=true;
	int cnt=0;
	for(int i=0;i<ad[v].size();i++){
		int next=ad[v][i];
		if(!chk[next]){
			dfs1(next);
			cnt+=c[next];
		}
	}
	cnt++;
	c[v]=cnt;
}

int dfs(int v){
	chk[v]=true;
	vector<int> re;
	for(int i=0;i<ad[v].size();i++){
		int next=ad[v][i];
		if(!chk[next])
			re.push_back(c[next]-dfs(next));
	}
	if(re.size()==0) return 0;
	if(re.size()==1) return c[v]-1;
	sort(re.begin(),re.end());
	int cnt=0;
	for(int i=re.size()-1;i>=(int)re.size()-2;i--){
		cnt+=re[i];
	//printf("                 %d\n",(int)re[i]);
	}
	return c[v]-cnt-1;
}

void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) ad[i].clear();
	for(int i=1;i<n;i++){
		int in1,in2;
		scanf("%d %d",&in1,&in2);
		ad[in1].push_back(in2);
		ad[in2].push_back(in1);
	}
	ans=n-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[j]=2140000000,chk[j]=false,c[j]=0;
		dfs1(i);
		for(int j=1;j<=n;j++) chk[j]=false;
		ans=min(ans,dfs(i));
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ca=0,t;
	scanf("%d",&t);
	while(t--){
		input();
		printf("Case #%d: ",++ca);
		printf("%d\n",ans);
	}
	return 0;
}