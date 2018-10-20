#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MAXN 2010
using namespace std;
int n,T,in[MAXN],head,tail,que[MAXN],f[MAXN],to[MAXN],next[MAXN],p[MAXN],vis[MAXN],g[MAXN],root,ans;
void add(int u,int v)
{
	to[++tail]=v; next[tail]=p[u]; p[u]=tail;
}
void dfs(int now)
{
	int i,son=0; vis[now]=1;
	for (i=p[now];i;i=next[i])
		if (!vis[to[i]])
			dfs(to[i]),g[now]+=g[to[i]],++son,f[now]+=f[to[i]];
	if (son==1)
		f[now]=g[now]-1;
	if (son>2)
	{
		int m1=-1,m2=-1;
		for (i=p[now];i;i=next[i])
		{
			if (vis[to[i]]) continue;
			if (m1!=-1)
			{
				if (g[to[i]]-f[to[i]]>m1)
					m2=m1,m1=g[to[i]]-f[to[i]];
				else
					if (m2!=-1)
					{
						if (g[to[i]]-f[to[i]]>m2)
							m2=g[to[i]]-f[to[i]];
					}
					else
						m2=g[to[i]]-f[to[i]];
			}
			else
				m1=g[to[i]]-f[to[i]];
		}
		f[now]=g[now]-1-m1-m2;
	}
	vis[now]=0;
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		tail=0;
		for (i=1;i<n;++i)
			scanf("%d%d",&j,&k),add(j,k),add(k,j);
		ans=n+1;
		for (root=1;root<=n;++root)
		{
			memset(f,0,sizeof(f));
			memset(vis,0,sizeof(vis));
			for (i=1;i<=n;++i)
				g[i]=1;
			dfs(root);
			ans=min(ans,f[root]);
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	
	//system("pause");
	return 0;
}
