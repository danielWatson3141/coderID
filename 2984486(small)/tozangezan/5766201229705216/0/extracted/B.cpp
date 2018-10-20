#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[2000];
int sz[2000];
int solve(int a,int b){
	int ch=0;
	int v1=0;
	int v2=0;
	sz[a]=1;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==b)continue;
		ch++;
		int q=solve(g[a][i],a);
		sz[a]+=sz[g[a][i]];
		if(v1<q){
			v2=v1;
			v1=q;
		}else if(v2<q){
			v2=q;
		}
	}
	if(ch==0)return 1;
	if(ch==1)return 1;
	else return v1+v2+1;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int a;
		scanf("%d",&a);
		for(int i=0;i<a;i++)g[i].clear();
		for(int i=0;i<a-1;i++){
			int b,c;
			scanf("%d%d",&b,&c);
			b--;c--;
			g[b].push_back(c);
			g[c].push_back(b);
		}
		int ret=999999999;
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++)sz[j]=0;
			int dat=solve(i,-1);
		//	printf("%d: %d\n",i,a-dat);
			ret=min(ret,a-dat);
		}
		printf("Case #%d: %d\n",t+1,ret);
	}
}