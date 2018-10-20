#include <iostream>
#include <map>
#include <bitset>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long big;

const int N=2020;
int f[N],nxt[N],v[N],head[N],t=1;
int cas,n;
int lst[N],top=0,sz[N],lst2[N];
inline void add(int x,int y)
{
	nxt[++t]=head[x];v[t]=y;head[x]=t;
	nxt[++t]=head[y];v[t]=x;head[y]=t;
}
int dfs(int x,int fa)
{
	int i;
	f[x]=0;
	for(i=head[x];i;i=nxt[i])
		if(fa!=v[i])
			dfs(v[i],x);
	top=0;
	for(i=head[x];i;i=nxt[i])
		if(fa!=v[i])
		{
			lst[++top]=sz[v[i]]-f[v[i]];
			lst2[top]=sz[v[i]];
		}
	if(top==1)
		f[x]+=lst2[1];
	else if(top>=2)
	{
		sort(lst+1,lst+1+top);
		for(i=head[x];i;i=nxt[i])
			if(fa!=v[i])
				f[x]+=sz[v[i]];
		reverse(lst+1,lst+1+top);
		f[x]-=lst[1];
		f[x]-=lst[2];
	}
	return f[x];
}
void getsz(int x,int fa)
{
	int i;
	sz[x]=1;
	for(i=head[x];i;i=nxt[i])
		if(v[i]!=fa)
		{
			getsz(v[i],x);
			sz[x]+=sz[v[i]];
		}
}
int main()
{
	int cass,x,y,i;
	freopen("a.in","r",stdin);
	freopen("a.txt","w",stdout);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		memset(head,0,sizeof(head));
		t=1;
		scanf("%d",&n);
		for(i=1;i<n;i++)
			scanf("%d%d",&x,&y),add(x,y);
		int ans=1<<20;
		for(i=1;i<=n;i++)
		{
			memset(f,0x3f,sizeof(f));
			memset(sz,0,sizeof(sz));
			getsz(i,-1);
			ans=min(ans,dfs(i,-1));
		}
		printf("Case #%d: %d\n",cass,ans);
	}
}
