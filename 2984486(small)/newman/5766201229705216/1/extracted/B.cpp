#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 1010;

vector<int> g[maxn+1];
int f[maxn+1];
int n;
int result;
int root;

void init()
{
	int i,x,y;
	scanf("%d",&n);
	for (i=1; i<=n; ++i)
		g[i].clear();
	for (i=1; i<n; ++i)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

void dp(int p,int father)
{
	int w,i,t,f1=-1,f2=-1;
	f[p]=1;
	for (w=0; w<g[p].size(); ++w)
	{
		i=g[p][w];
		//printf("(%d-->%d)\n",p,i);
		if (i!=father)
		{
			dp(i,p);
			if (f[i]>f1)
			{
				f2=f1;
				f1=f[i];
			}
			else if (f[i]>f2)
				f2=f[i];
		}
	}

	if ((f1!=-1)&&(f2!=-1))
		f[p]=f1+f2+1;
	//if (root==2)
	//	printf("f[%d]=%d\n",p,f[p]);
}

void work()
{
	result=1;
	for (root=1; root<=n; ++root)
	{
		dp(root,-1);		
		if (f[root]>result)
			result=f[root];
	}
}

void output()
{
	printf("%d\n",n-result);
}

int main()
{
	int i,T;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
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