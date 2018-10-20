#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define MOD 1000000007
vector<int> v[1111];
int a[1111];
int dp[1111];
int dfs(int x,int start)
{
	int na=0,i;
	int n=v[x].size();
	for(i=0;i<n;i++)
	{
		if(v[x][i]==start)
			continue;
		dp[v[x][i]]=dfs(v[x][i],x);
	}
	for(i=0;i<n;i++)
	{
		if(v[x][i]==start)
			continue;
		a[na]=dp[v[x][i]];
		na++;
	}
	if(na<=1)
		dp[x]=1;
	else
	{
		sort(a,a+na);
		dp[x]=a[na-1]+a[na-2]+1;
	}
	return dp[x];
}
int main()
{
	int t,T;
	int themax;
	int n,i;
	int x,y;
	freopen("B-large.in","rt",stdin);
	freopen("B.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		themax=0;
		for(i=0;i<=n;i++)
			v[i].clear();
		for(i=1;i<n;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=1;i<=n;i++)
		{
			themax=max(themax,dfs(i,9999));
		}
		cout<<"Case #"<<t<<": "<<n-themax<<endl;
	}
    return 0;
}