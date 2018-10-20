#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

const int maxn = 1005;
int N,T,tot,ans;
int a[maxn],b[maxn],c[maxn],size[maxn],f[maxn];

void Insert(int x,int y)
{
	tot ++;
	b[tot] = y;
	c[tot] = a[x];
	a[x] = tot;
}

void DP(int x,int last)
{
	int cnt = 0;
	size[x] = 1;
	for (int i = a[x];i;i = c[i])
		if (b[i] != last)
		{
			DP(b[i],x);
			cnt ++;
			size[x] += size[b[i]];
		}
	int M = 0x7fffffff;
	for (int i = a[x];i;i = c[i])
		if (b[i] != last)
		{
			for (int j = a[x];j;j = c[j])
				if (b[j] != last && i != j)
				{
					int v = f[b[i]] + f[b[j]] + size[x] - size[b[i]] - size[b[j]] - 1;
					if (v < M) M = v;
				}
		}
	if (!cnt) f[x] = 0;
	else if (cnt == 1) f[x] = size[x] - 1;
	else f[x] = M;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	fo(cs,1,T)
	{
		scanf("%d",&N);
		tot = 0;
		fo(i,1,N) a[i] = 0;
		fo(i,1,N-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Insert(x,y);
			Insert(y,x);
		}
		ans = 0x7fffffff;
		fo(i,1,N)
		{
			DP(i,0);
			ans = min(ans,f[i]);
		}
		printf("Case #%d: ",cs);
		printf("%d\n",ans);
	}
	return 0;
}

