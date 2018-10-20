#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define N 1005
int n,f[N];
vector<int> edge[N];

void init()
{
	int i,t1,t2;
	scanf("%d",&n);
	FOR(i,1,n)edge[i].clear();
	FOR(i,1,n-1)
	{
		scanf("%d%d",&t1,&t2);
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
}

void dfs(int v,int fa)
{
	int p,i,m1=-1,m2=-1;
	f[v]=1;
	FOR(i,0,(int)edge[v].size()-1)
	{
		p=edge[v][i];
		if(p!=fa)
		{
			dfs(p,v);
			if(f[p]>m1)
			{
				m2=m1;m1=f[p];
			}else
			{
				if(f[p]>m2)m2=f[p];
			}
		}
	}
	if(m2!=-1)f[v]+=m1+m2;
}

int work()
{
	int i,ans=123456789;
	FOR(i,1,n)
	{
		memset(f,0,sizeof(f));
		dfs(i,-1);
		//cout<<f[i]<<endl;
		ans=min(ans,n-f[i]);
	}
	return ans;
}

int main()
{
	int i,T;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		init();
		printf("Case #%d: %d\n",i,work());
	}
}