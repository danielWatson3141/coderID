#include<stdio.h>
#include<string.h>
 #include<algorithm>
 #define ll long long

 #define inf 1000000000

 using namespace std;


pair<int,int> a[40][40];
int s[200],dp[40][1010];
bool pred ( pair<int,int> x, pair<int,int> y )
{
	return x.first < y.first;
}
int main()
{
    int t,i,j,o=0,n,m,k,p,q;
    scanf("%d",&t);
   	while(t--)
   	{
   	scanf("%d%d%d",&n,&m,&k);
   	for ( i = 0; i < n; i++ )
   	scanf("%d",&s[i]);
   	for ( i = 0; i < n; i++ )
   	{
   		for ( j = 0; j < m; j++ )
   		scanf("%d",&a[i][j].first);
   	}
   	for ( i = 0; i < n; i++ )
   	{
   		for ( j = 0; j < m; j++ )
   		scanf("%d",&a[i][j].second);
   	}
   	for(i=0;i<40;i++)
   	for(j=0;j<1010;j++)
   	dp[i][j]=-1000000000;
   	for ( i = 0; i < n; i++ )
   	{
   		sort(a[i],a[i]+m,pred);
   		/*for ( j = 0; j < m; j++ )
   		{
   			printf("a[%d][%d]=(%d,%d)\n",i,j,a[i][j].first,a[i][j].second);
   		}*/
   		dp[i][s[i]]=0;
   		for ( p = 1; p <= k; p++ )
   		{
   			for ( q = 0; q < m && a[i][q].first <= p; q++ )
   			dp[i][p]=max(dp[i][p],dp[i][p-a[i][q].first]+a[i][q].second);
   		}
   	}
   	for(i=1;i<n;i++)
   	{
   		for(p=1;p<=k;p++)
   		{
   			for(q=0;q<=p;q++)
   			dp[i][p]=max(dp[i][p],dp[i][p-q]+dp[i-1][q]);
   		}
   	}
   	int mo=-1;
   	for(i=0;i<=k;i++)
   	mo=max(mo,dp[n-1][i]);
   	printf("%d\n",mo);
   }
    return 0;
}

