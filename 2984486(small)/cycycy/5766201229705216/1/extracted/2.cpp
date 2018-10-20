#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int a[3000],b[3000];
int st[2000],lk[3000];
int n,m;
int num[3000],dp[3000];
bool tf[3000];


void dfs(int x)
{
	num[x]=0;
	tf[x]=true;
	int a1=-1,a2=-1;
	int j=st[x];
	while (j!=-1)
	{
		int k=b[j];
		j=lk[j];
		if (tf[k]) continue;
		dfs(k);
		num[x]+=num[k];
		int i=num[k]-dp[k];
		if (i>a2)
			a2=i;
		if (a2>a1)
		{
			int temp=a1;
			a1=a2;
			a2=temp;
		}
	}
	if (a2==-1)
		dp[x]=num[x];
	else
		dp[x]=num[x]-a1-a2;
	num[x]++;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		cin>>n;
		m=n-1;
		for (int i=1;i<=m;i++)
		{
			cin>>a[i]>>b[i];
			b[i+m]=a[i];
			a[i+m]=b[i];
		}
		for (int i=1;i<=n;i++)
			st[i]=-1;
		for (int i=2*m;i>=1;i--)
		{
			lk[i]=st[a[i]];
			st[a[i]]=i;
		}
		cout<<"Case #"<<ii+1<<": ";
		int ans=3000;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				tf[j]=false;
			dfs(i);
			ans=min(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
}