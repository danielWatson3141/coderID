#include<stdio.h>
#include<algorithm>

typedef long long int lnt;
typedef double dou;

using namespace std;

#include<vector>
vector<int>e[5140];
int n;
int sub[5140];
int dp[5140];
void ok(int r,int f){
	sub[r]=1;
	int ans=0;
	for(int i=0;i<e[r].size();i++){
		int t=e[r][i];
		if(t==f){
			continue;
		}
		ok(t,r);
		sub[r]+=sub[t];
	}
	int mx1=-1,mx2=-1;
	for(int i=0;i<e[r].size();i++){
		int t=e[r][i];
		if(t==f){
			continue;
		}
		if(mx1<sub[t]-dp[t]){
			mx2=mx1;
			mx1=sub[t]-dp[t];
		}
		else if(mx2<sub[t]-dp[t]){
			mx2=sub[t]-dp[t];
		}
	}
	if(mx2==-1&&mx1==-1){
		dp[r]=0;
	}
	else if(mx2==-1){
		dp[r]=sub[r]-1;
	}
	else{
		dp[r]=sub[r]-1-mx1-mx2;
	}
}
void sol(int uuu){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans=n*10000+7122;
	for(int i=1;i<=n;i++){
		ok(i,-7122);
		ans=min(ans,dp[i]);
	}
	printf("Case #%d: %d\n",uuu,ans);
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
}

int main(){
	
	freopen("B-large.in","r",stdin);
	freopen("b_l.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		sol(ti);
	}
	return 0;
}
