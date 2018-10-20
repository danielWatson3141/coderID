#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

int a[20][20];
int b[20][20];
int visited[20];
int ans,n,flag;

using namespace std;
void dfs(int node)
{
	int i;
	visited[node]=1;
	for(i=1;i<=n;i++)
	{
		if(b[node][i] && !visited[i])	dfs(i);
	}
	return;
}
/*
void checkbin(int node)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(b[node][i] && b[i][19]==2)
		{
			flag=0;
			return;
		}
	}
//	dfs(node);
	return;
}
*/
int main()
{
	int i,j,k,t,x,y,cnt,sco,f;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		ans=20;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
			a[y][x]=1;
		}
		if(n==2)
		{
			printf("Case #%d: 1\n",k);
			continue;
		}
		for(i=0;i<(1<<n);i++)
		{
			for(x=1;x<=n;x++)
			{
				for(j=1;j<=n;j++)
				{
					b[x][j]=a[x][j];
				}
			}
			for(x=1;x<=n;x++)	visited[x]=0;
			x=i;
			cnt=1;
			sco=0;
			while(x)
			{
				if(x&1)
				{
					for(j=1;j<=n;j++)
					{
						b[cnt][j]=0;
						b[j][cnt]=0;
					}
					visited[cnt]=1;
					sco++;
				}
				cnt++;
				x=x>>1;
			}
			for(x=1;x<=n;x++)
			{
				cnt=0;
				for(j=1;j<=n;j++)
				{
					if(b[x][j]==1)	cnt++;
				}
				b[x][19]=cnt;
			}
			flag=1;
//			f=1;
			for(x=1;x<=n;x++)
			{
				if(b[x][19]==2)	
				{
					dfs(x);
					break;
				}
			}
			for(x=1;x<=n;x++)
			{
				if(!visited[x])	flag=0;
			}
			if(!flag)	continue;
			cnt=0;
			for(x=1;x<=n;x++)
			{
				if(b[x][19]==2)	cnt++;
			}
			if(cnt!=1)	flag=0;
			if(flag)	ans=min(ans,sco);
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}
