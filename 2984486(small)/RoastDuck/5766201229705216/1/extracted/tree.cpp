#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1005;

int N, ans, m, a[maxn], b[maxn<<1], c[maxn<<1], size[maxn], f[maxn];

void Dfs(int x, int last)
{
	size[x]=0;
	for (int i=a[x];i;i=c[i]) if (b[i]!=last)
	{
		Dfs(b[i],x);
		size[x]+=size[b[i]];
	}
	f[x]=size[x];
	for (int i=a[x];i;i=c[i]) if (b[i]!=last)
	    for (int j=a[x];j;j=c[j]) if (b[j]!=last && i!=j)
		    f[x]=min(f[x],size[x]-size[b[i]]-size[b[j]]+f[b[i]]+f[b[j]]);
	size[x]++;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d",&N);
		memset(a,0,sizeof a);
		m=0;
		for (int i=1;i<N;i++)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			m++;
			b[m]=y;
			c[m]=a[x];
			a[x]=m;
			m++;
			b[m]=x;
			c[m]=a[y];
			a[y]=m;
		}
		ans=N;
		for (int i=1;i<=N;i++)
		{
			Dfs(i,0);
			ans=min(ans,f[i]);
		}
		printf("Case #%d: %d\n",TT,ans);
	}
	return 0;
}

