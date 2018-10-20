#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1100;
int Cas;
vector<int> edge[maxn];
int sum[maxn],rem[maxn],rem2[maxn];

void dfs1(int u,int f){
	int mm = edge[u].size();
	int i,j;
	for(i = 0;i < mm;i++)
		if (edge[u][i] != f)
			dfs1(edge[u][i],u);
	sum[u] = 1;
	for(i = 0;i < mm;i++)
		if (edge[u][i] != f)
			sum[u] += sum[edge[u][i]];
	rem[u] = 1;
	for(i = 0;i < mm;i++)
		for(j = i+1;j < mm;j++)
			if (edge[u][i] != f && edge[u][j] != f)
				rem[u] = max(rem[u],rem[edge[u][i]] + rem[edge[u][j]] + 1);
}

void dfs2(int u,int f){
	int mm = edge[u].size();
	int i,j,ii,jj;
	rem2[u] = 1;
	for(i = 0;i < mm;i++)
		for(j = i+1;j < mm;j++)
			///if (edge[u][i] != f && edge[u][j] != f)
				rem2[u] = max(rem2[u],rem[edge[u][i]] + rem[edge[u][j]] + 1);
	for(i = 0;i < mm;i++)
		if (edge[u][i] != f){
			int t = rem[u];
			rem[u] = 1;
			for(ii = 0;ii < mm;ii++)
				for(jj = ii+1;jj < mm;jj++)
					if (ii != i && jj != i)
						rem[u] = max(rem[u],rem[edge[u][ii]] + rem[edge[u][jj]] + 1);
			dfs2(edge[u][i],u);
			rem[u] = t;
		}
	return ;
}

int Work(){
	int n,u,v,i;
	scanf("%d",&n);
	memset(sum,0,sizeof(sum));
	memset(rem,0,sizeof(rem));
	memset(rem2,0,sizeof(rem2));
	for(i = 1;i <= n;i++)
		edge[i].clear();
	for(i = 1;i < n;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans = 1;
	//for(i = 1;i <= n;i++)
	//	printf(" %d %d %d %d\n",i,rem[i],rem2[i],sum[i]);
	for(i = 1;i <= n;i++)
		ans = max(ans,rem2[i]);
	printf("Case #%d: %d\n",Cas,n-ans);
	return 0;
}

int main(){
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(Cas = 1;Cas <= T;Cas++)
		Work();
	return 0;
}