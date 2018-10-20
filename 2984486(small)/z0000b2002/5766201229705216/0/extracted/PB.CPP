#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#define LEN 1005
#define INF 2147483647

using namespace std;

struct ccost{
	int del;
	int cost;
};

int tt;
int N;
vector <int> edge[LEN];
int seen[LEN];
int total[LEN];
int cost[LEN];
ccost toc[LEN][LEN];

int ccmp(const void *p,const void *q)
{
	ccost *a=(ccost*)p;
	ccost *b=(ccost*)q;
	return a->cost-b->cost;
}

void DFS(int cur)
{
	seen[cur]=1;
	total[cur]=1;
	int toct=0;
	int child=0;
	for(int i=0;i<edge[cur].size();++i){
		int nnode=edge[cur][i];
		if(0==seen[nnode]){
			DFS(nnode);
			++child;
			total[cur]+=total[nnode];
			toc[cur][toct].del=nnode;
			toc[cur][toct++].cost=cost[nnode]-total[nnode];
		}
	}
	
	if(0==child){
		cost[cur]=0;
		return;
	}
	if(1==child){
		cost[cur]=total[cur]-1;
		return;
	}
	qsort(toc[cur],toct,sizeof(toc[cur][0]),ccmp);
	int d1=toc[cur][0].del;
	int d2=toc[cur][1].del;
	//printf("%d:%d tod(%d %d) t(%d,%d) c(%d,%d)\n",cur,total[cur],d1,d2,total[d1],total[d2],cost[d1],cost[d2]);
	cost[cur]=total[cur]-1-total[d1]+cost[d1]-total[d2]+cost[d2];
	//printf("cost%d:%d\n",cur,cost[cur]);
}

int main(void)
{
	scanf("%d",&tt);
	for(int tc=1;tc<=tt;++tc){
		scanf("%d",&N);
		for(int i=1;i<=N;++i)edge[i].clear();
		for(int ec=1;ec<N;++ec){
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		int ans=INF;
		
		for(int i=1;i<=N;++i){
			int temp;
			memset(seen,0,sizeof(seen));
			memset(total,0,sizeof(total));
			memset(cost,0,sizeof(cost));
			DFS(i);
			temp=cost[i];
			//printf("temp%d:%d\n",i,cost[i]);
			ans=min(temp,ans);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}