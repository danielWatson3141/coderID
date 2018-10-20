//============================================================================
// Name        : a1.cpp
// Author      : L_Ecry
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<set>
#include<vector>
#define N 50
#define INF 1000000001
#define LL __int64
using namespace std;
vector<int >e[N];
int d[N],all[N];
void gao(int now,int fa)
{
	int sum=0;
	for(int i=0;i<e[now].size();i++)
	{
		int u=e[now][i];
		if(u==fa)continue;
		gao(u,now);
		sum+=all[u];
	}

	all[now]=sum+1;
	d[now]=sum;

	for(int i=0;i<e[now].size();i++)
	{

		for(int j=i+1;j<e[now].size();j++)
		{
			int u,v;
			u=e[now][i];
			v=e[now][j];
			if(u==fa)continue;
			if(v==fa)continue;


			int tmp=d[u]+d[v]+sum-all[u]-all[v];
			if(d[now]>tmp)
				d[now]=tmp;
		}
	}


}
int main() {
	freopen("B-small-attempt0.in","r",stdin);
		freopen("output.txt","w",stdout);
	int tt,ri=0,i,j,k,n,m;
	scanf("%d",&tt);
	while(tt--)
	{
		ri++;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			e[i].clear();
		for(i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans=-1;
		for(i=1;i<=n;i++)
		{
			memset(d,0,sizeof(d));
			memset(all,0,sizeof(all));
			gao(i,-1);
			if(ans==-1||d[i]<ans)
				ans=d[i];
			//printf("%d %d\n",i,d[i]);
		}
		printf("Case #%d: %d\n",ri,ans);
	}
}
