#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define inf 10000000
using namespace std;
 
int a[1000000],dp[1000000],n,k,tree[1000000],b[1000000];
/*int f ( int l )
{
	if(l==n)
	return 0;
	if(n-l<3||a[l+2]-a[l]>2*k)
	return inf;
	int &ans=dp[l];
	if(ans!=-1)
	return ans;
	int i = 0;
	ans=inf;
	for(i=l+3;i<=n&&a[i-1]-a[l]<=2*k;i++)
	{	
		ans=min(ans,f(i)+1);
	}
	return ans;
}*/
void build ( int l, int h, int id )
{
	if ( l < h )
	{
		int m = ( l + h )/2;
		build(l,m,2*id);
		build(m+1,h,2*id+1);
		if ( dp[tree[2*id]] < dp[tree[2*id+1]] )
		tree[id]=tree[2*id];
		else
		tree[id]=tree[2*id+1];
	}
	else
	{
	tree[id]=l;
	b[l]=id;
	}
}
int query (int lo, int hi, int l, int h, int id )
{
	if ( lo > h || hi < l )
	return n;
	if ( lo >= l && hi <= h )
	return tree[id];
	else
	{
		int mid = ( lo + hi )/2;
		int p = query(lo,mid,l,h,2*id);
		int q = query(mid+1,hi,l,h,2*id+1);
		if ( dp[p]<dp[q])
		return p;
		else
		return q;
	}
}
void ch ( int l, int x )
{	
	int lo = b[l];
	while ( lo > 0 && dp[tree[lo]] > x)
	{
		tree[lo]= l;
		lo/=2;
	}
} 
int main()
{
	int t,o=0,i,j;
	scanf("%d", &t );
	while ( t-- )
	{
		scanf("%d%d", &n,&k);
		for ( i = 0; i < n; i++ )
		scanf("%d", &a[i]);
		for(i=0;i<=n;i++)
		dp[i]=inf;
		sort(a,a+n);
		build(0,n-1,1);	
		for ( i = 0; i < n; i++ )
		{
			int x = lower_bound(a,a+n,a[i]-2*k)-a;
			if (  x > i - 2 )
			{
				continue;
			}
			if ( x == 0 )
			{
				dp[i]=1;
				ch(i,1);
			}
			else
			{
				int q = query(0,n-1,x-1,i-3,1);	
				dp[i]=dp[q]+1;
				ch(i,dp[i]);
			}
		}
		printf("Case %d: ",++o);
		if ( dp[n-1] >= inf )
		puts("-1");
		else
		printf("%d\n",dp[n-1]);
	}
}
