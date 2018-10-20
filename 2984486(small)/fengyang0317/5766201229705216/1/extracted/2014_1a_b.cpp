#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cctype>
#include <ctime>
#include <strstream>
#define min(a,b) ((a) < (b) ? (a) : (b)) 
#define max(a,b) ((a) > (b) ? (a) : (b)) 
using namespace std;
#define N 1005
int n;
int s[N],e[N];
int dp[N][N];
int big(int x,int f)
{
	if(dp[x][f]!=-1)return dp[x][f];
	int t[N],i,nt=0;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==x&&e[i]!=f)t[nt++]=e[i];
		if(e[i]==x&&s[i]!=f)t[nt++]=s[i];
	}
	if(nt<2)return dp[x][f]=1;
	int c[N];
	for(i=0;i<nt;i++)
		c[i]=big(t[i],x);
	sort(c,c+nt);
	return dp[x][f]=c[nt-1]+c[nt-2]+1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j,ma;
	scanf("%d",&cas);
	for(ki=1;ki<=cas;ki++)
	{
		printf("Case #%d: ",ki);
		cin>>n;
		for(i=0;i<n-1;i++)
		{
			cin>>s[i]>>e[i];
		}
		memset(dp,-1,sizeof(dp));
		ma=0;
		for(i=1;i<=n;i++)
		{
			j=big(i,0);
			if(j>ma)ma=j;
		}
		cout<<n-ma<<endl;
	}
	return 0;
}