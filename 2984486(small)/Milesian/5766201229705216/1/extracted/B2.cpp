#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define maxn 1020
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int fir[maxn],en[maxn*2],nex[maxn*2];
int tot,n,ans,T;
int f[maxn][5];
int fa[maxn];
int d[maxn];
int r[maxn];
void tjb(int x,int y)
{
//	++d[x];
	en[++tot]=y;
	nex[tot]=fir[x];
	fir[x]=tot;
}
void dfs_1(int x)
{
	int c1=-1,c2=-1;
	for(int i=fir[x];i;i=nex[i])
	{
		int j=en[i];
		if(j==fa[x])continue;
		fa[j]=x;
		++d[x];
		++d[j];
		dfs_1(j);
		int y=r[j];
		if(y>c1)
		{
			c2=c1;
			c1=y;
		}else c2=max(c2,y); 
	}
	f[x][0]=1;
	if(c1>=0)f[x][1]=c1+1;else f[x][1]=-1;
	if(c2>=0)f[x][2]=c1+c2+1; else f[x][2]=-1;
	r[x]=max(1,f[x][2]);
//	printf("%d %d\n",x,r[x]);
}
void dfs_2(int x,int pre)
{
	if(f[x][1]>0&&pre>0)ans=max(ans,f[x][1]+pre);
	ans=max(ans,r[x]);
//	printf("%d %d %d\n",ans,x,pre);
	int c1=n+1,c2=n+1,c3=n+1; 
	if(pre>0)
	{
		c1=0;
		r[0]=pre;
	}
	for(int k=fir[x];k;k=nex[k])
	{
		if(d[x]<3)break; 
		int j=en[k];
		if(j==fa[x])continue;
		//int y=max(f[j][0],f[j][2]);
		if(r[c1]<r[j])
		{
			c3=c2;
			c2=c1;
			c1=j;
		}else if(r[c2]<r[j])
		{
			c3=c2;
			c2=j;
		}else if(r[c3]<r[j])c3=j;
	}
	for(int k=fir[x];k;k=nex[k])
	{
		int j=en[k];
		if(j==fa[x])continue;
		r[0]=pre;
	//	printf("%d %d %d %d %d\n",r[c1],r[c2],r[c3],x,j);
		if(d[x]<3)dfs_2(j,1);
		else
		{
			if(j==c1)dfs_2(j,r[c2]+r[c3]+1);
			else if(j==c2)dfs_2(j,r[c1]+r[c3]+1);
				else dfs_2(j,r[c1]+r[c2]+1);
		}
	}
}	
int main()
{
	//freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	
	scanf("%d",&T); 
	rep(ii,T)
	{
		memset(fir,0,sizeof(fir));
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		tot=0;
		ans=1;
		scanf("%d",&n);
		memset(fa,0,sizeof(fa));
		rep(i,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			tjb(x,y);
			tjb(y,x);
		}
		dfs_1(1);
		r[n+1]=-1;
		dfs_2(1,0);
	//	rep(i,n)printf("%d %d\n",i,d[i]);
		printf("Case #%d: %d\n",ii,n-ans);
	}
	return 0;
}