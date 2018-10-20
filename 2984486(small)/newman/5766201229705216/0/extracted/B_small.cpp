#include <stdio.h>

const int maxn = 16;

bool g[maxn+1][maxn+1];
bool done[maxn+1];
int now,result,n;
bool success;

void init()
{
	int i,j,k,x,y;
	scanf("%d",&n);
	for (i=0; i<n; ++i)
		for (j=0; j<n; ++j)
			g[i][j]=false;
	for (i=1; i<n; ++i)
	{
		scanf("%d%d",&x,&y);
		--x;
		--y;
		g[x][y]=g[y][x]=true;
	}
}

void dfs(int p,int father)
{
	int p1=-1,p2=-1;
	int i;
	if (!success)
		return;
	for (i=0; i<n; ++i)
		if (((1<<i)&now)&&(g[p][i])&&(i!=father))
		{
			if (done[i])
			{
				success=false;
				return;
			}
			else {
				if (p1==-1)
					p1=i;
				else {
					if (p2==-1)
						p2=i;
					else {
						success=false;
						return;
					}
				}
			}
		}
	if ((p1!=-1)&&(p2==-1))
	{
		success=false;
		return;
	}
	if (p1!=-1)
	{
		done[p1]=done[p2]=true;
		dfs(p1,p);
		dfs(p2,p);
	}
}

void gao(int root)
{
	int i,j;
	for (j=0; j<n; ++j)
		done[j]=false;
	success=true;
	done[root]=true;
	dfs(root,-1);
	for (j=0; j<n; ++j)
		if ((now&(1<<j))&&(!done[j]))
			success=false;
	if (success)
	{		
		j=0;
		for (i=0; i<n; ++i)
			if (now&(1<<i))
				++j;
		if (j>result)
		{
			//printf("now=%d root=%d j=%d\n",now,root,j);
			result=j;
		}
	}
}

void work()
{
	int i,j,k,root;
	result=1;
	for (i=1; i<(1<<n); ++i)
	{
		now=i;		
		for (root=0; root<n; ++root)
			if (now&(1<<root))
				gao(root);
	}
}

void output()
{
	printf("%d\n",n-result);
}

int main()
{
	int i,T;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (i=1; i<=T; ++i)
	{
		printf("Case #%d: ",i);
		init();
		work();
		output();
	}
	return 0;
}