#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int co[1001][1001];
//int f[1001];
int nodes(int x,int fa)
{
	int ans = 1;
	for (int i=1;i<=co[x][0];i++)
	if (co[x][i]!=fa)
	{
		ans += nodes(co[x][i],x);
	}
	return ans;
}

int cut(int r,int fa)
{
	int son = co[r][0];
	if (fa!=0) son--;
	if (son>=2)
	{
		int ans = n;
		for (int i=1;i<co[r][0];i++)
		{
			
			for (int j=i+1;j<=co[r][0];j++)
			if (co[r][i]!=fa && co[r][j]!=fa)
			{
				int now = 0;
				for (int k = 1;k<=co[r][0];k++)
				if (co[r][k]!=fa && co[r][k]!=co[r][i] && co[r][k]!=co[r][j])
				{
					now +=nodes(k,r);
				}
				now = now + cut(co[r][i],r)+cut(co[r][j],r);
				if (now<ans) ans = now;
			}
			
		}
		return ans;
	}
	else if (son==1)
	{
		for (int i=1;i<=co[r][0];i++)
			if (co[r][i]!=fa)
				return nodes(co[r][i],r);
	}
	else return 0;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		
		cin>>n;
		memset(co,0,sizeof(co));
		for (int i=0;i<n-1;i++)
		{
			int x,y;

			cin>>x>>y;
			co[x][0]++;
			co[x][co[x][0]] = y;
			co[y][0]++;
			co[y][co[y][0]] = x;
		}
		/*
		for(int i=1;i<=n;i++)
			cout<<co[i][0]<<" ";
			cout<<"\n";
			*/
		int ans = n;
		for (int i=1;i<=n;i++)
		{
		//	memset(f,0,sizeof(f));
			int now = cut(i,0);
			//cout<<"i,now="<<i<<" "<<now<<"\n";
			if (now<ans) 
			
				ans = now;
			

		}
		cout<<"Case #"<<tt<<": ";
		cout<<ans<<"\n";

	}
	return 0;
}