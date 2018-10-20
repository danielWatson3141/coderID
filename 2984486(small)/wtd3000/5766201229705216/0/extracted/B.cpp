#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define inf 1999999
#define MIN(a,b) if(b<a)a=b
int vis[10001],size[10001],data[10001];
int son[10001],next[10001],ed[10001],cnt;
int T,n,ans,res1,res2,tmp1,tmp2;
void dfs(int x){
	#define v ed[i]
	size[x]=1; vis[x]=1;
	for (int i=son[x];i;i=next[i])
	if(!vis[v]){
		dfs(v);
		size[x]+=size[v];
	}
	
	res1=res2=inf;
	for (int i=son[x];i;i=next[i])
	if(!vis[ed[i]]){
		if(data[v]-size[v]<res1){
			res2=res1;
			res1=data[v]-size[v]; 
			continue;
		}
		if(data[v]-size[v]<res2){
			res2=data[v]-size[v];
			continue;
		} 
	}
	data[x]=min(size[x]-1,res1+res2+size[x]-1);
//	printf("dfs %d %d %d %d  \n",x,data[x],res1,res2);
	#undef v
	vis[x]=0;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	int i,j,x,y,ttt=0;
	while(T--){
		scanf("%d",&n);
		for (i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			next[++cnt]=son[x]; son[x]=cnt; ed[cnt]=y;
			next[++cnt]=son[y]; son[y]=cnt; ed[cnt]=x;
		}
		ans=inf;
		for (i=1;i<=n;i++){
		//	for (j=1;j<=n;j++) data[j]=0x7f7f7f7f;
			dfs(i);
		//	printf("---------\n");
			MIN(ans,data[i]);
		}
		for (i=1;i<=n;i++) son[i]=0; cnt=0;
		printf("Case #%d: %d\n",++ttt,ans);
	}
//	system("pause");
}
