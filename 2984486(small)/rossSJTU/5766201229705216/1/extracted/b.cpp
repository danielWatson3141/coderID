#include<stdio.h>
#include<string.h>
#define Max 1005
struct ed
{
	int v,next;
};
ed edge[2*Max];
int head[Max];
int sz[Max];
int M;
int dfs(int u,int f)
{
	int v;
	int tmp,min1,min2,tot,num;
	min1 = min2 = Max;
	tot   = num = 0;
	for(int i=head[u];i;i=edge[i].next)
	{
		v = edge[i].v;
		if(v==f) continue;
		num++;
		tmp = dfs(v,u);
		tmp -=sz[v];
		tot +=sz[v];
		if(tmp<=min1){
			min2 = min1;
			min1 = tmp;
		}else if(tmp<=min2){
			min2 = tmp;
		}
	}
	sz[u] = tot+1;
	if(num==0) tmp= 0;
	else if(num==1) tmp = tot;
	else tmp= min1+min2+tot;
	return tmp; 
}
int main ()
{
	int T,n,x,y,ans,tmp;
	scanf("%d",&T);
	for(int _=1;_<=T;_++){
		printf("Case #%d: ",_);
		M = 1;
		memset(head,0,sizeof(head));
		ans = Max;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			edge[M].v = y;
			edge[M].next = head[x];
			head[x] = M++;
			edge[M].v = x;
			edge[M].next = head[y];
			head[y] = M++;
		}
		for(int i=1;i<=n;i++){
			tmp = dfs(i,-1);
			
			if(tmp<ans)
			ans = tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
