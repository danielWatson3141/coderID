#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm> 
using namespace std;
#define maxn  1010
int res,cnt[maxn],f[maxn];
vector<int> e[maxn];
int n;
int work(int now, int fa){
	f[now] = 0;cnt[now] = 1;
	int tmp,i,j,k;
	if (fa==-1) tmp = e[now].size();
	else tmp = e[now].size()-1;

	for (i = 0;i< e[now].size(); i++){
		if (e[now][i]!=fa){
			work(e[now][i],now);
			cnt[now]+=cnt[e[now][i]];
		}
	}
	if (tmp==1) {
		f[now] = cnt[now]-1;	
	}else if(tmp>1){
		int one = -1, two = -1;
		for (i = 0;i <e[now].size();i++){
			int cur = e[now][i];
			if(cur==fa)continue;
			if (one==-1||f[cur]-cnt[cur]<f[one]-cnt[one]){
				two = one;
				one = cur;
			}else if (two==-1||f[cur]-cnt[cur]<f[two]-cnt[two]){
				two = cur;
			}
		}
		f[now] = cnt[now]-1+f[one]-cnt[one]+f[two]-cnt[two];
		
	}
	return f[now];
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t,cas;
	int i,j,k;
	scanf("%d",&t);
	for (cas = 1; cas<=t; cas++){
		scanf("%d",&n);
		for (i = 1;i <=n; i++)
			e[i].clear();
		for (i = 1;i < n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans = n;
		for (i = 1; i<=n; i++){
			work(i,-1);
			ans = min(ans, f[i]);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

