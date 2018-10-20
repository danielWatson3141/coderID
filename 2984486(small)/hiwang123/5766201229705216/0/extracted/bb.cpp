#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[1004];
int vis[1004];
int dfs(int now,int node){
	int i;
	int qq=0;
	for(i=0;i<v[now].size();i++)
	  if(vis[v[now][i]]==0) qq++; 
	if(qq<2) return node+0;
	int aaa[1004],cnt=0;
	int max1,max2;
	for(i=0;i<v[now].size();i++)
	  if(vis[v[now][i]]==0){
	  	vis[v[now][i]]=1;
	  	int vv=dfs(v[now][i],1);
	  	//printf("%d: %d %d\n",now,v[now][i],vv);
	  	aaa[cnt++]=vv;
	  } 
	sort(aaa,aaa+cnt);
	max1=aaa[cnt-1];
	max2=aaa[cnt-2];
	return node+max1+max2;
}
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		scanf("%d",&n);
		int i; 
		for(i=0;i<=n;i++)
		  v[i].clear();
		for(i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans=10000;
		int j;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
		  		vis[j]=0;
			vis[i]=1;
			int aa=dfs(i,1);
			if(n-aa<ans) ans=n-aa;
		}
		printf("Case #%d: %d\n",hh,ans);
	}
	return 0;
}
