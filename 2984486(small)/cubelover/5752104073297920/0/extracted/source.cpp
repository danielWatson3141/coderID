#include<cstdio>
#include<algorithm>

int a[1000];
bool v[1000];

struct pair
{
	int x;
	int y;
} d[1000];

inline bool operator <(const pair &x,const pair &y)
{
	if(x.y!=y.y)return x.y<y.y;
	return x.x<y.x;
}

int main()
{
	freopen("C-small-attempt3.in","r",stdin);
	freopen("C-small-attempt3.out","w",stdout);
	int tc,tcn,sum=0;
	scanf("%d",&tcn);
	for(tc=0;tc<tcn;tc++)
	{
		int i,j,t,n;
		d[tc].x=tc;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			v[i]=false;
		}
		for(i=0;i<n;i++)if(!v[i])for(j=a[i];j!=i;j=a[j])
		{
			v[j]=true;
			d[tc].y++;
		}
	}
	std::sort(d,d+tcn);
	for(tc=0;tc<tcn;tc++)
	{
		if(tc<tcn/2)a[d[tc].x]=1;
		else a[d[tc].x]=-1;
	}
	for(tc=0;tc<tcn;tc++)
	{
		printf("Case #%d: ",tc+1);
		if(a[tc]==1)puts("GOOD");
		else puts("BAD");
	}
	return 0;
}
