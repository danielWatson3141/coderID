# include <iostream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <stack>
# include <algorithm>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdio>
# include <stdio.h>
using namespace std;
string a[10];
string b[10];
string d[10];
int n,l;
bool c[10];
int ans=10000;
int y=-1;
void solve(int i)
{
	if (i==l)
	{
		if (c[0]==0 && c[1]==0 && c[2]==0 && c[3]==1 && c[4]==0 && c[5]==0 && c[6]==0 && c[7]==1)
		{
			y=10;
		}
		int moves=0;
		for (int i=0;i<n;i++)
			d[i]=a[i];
		for (int i=0;i<l;i++)
		{
				if (c[i]==1)
				{
							moves++;
					for (int x=0;x<n;x++)
					{
						;
							if (d[x][i]=='1')
								d[x][i]='0';
							else
								d[x][i]='1';
					}
				}
		}
		sort(d,d+n);
		bool p=1;
		for (int i=0;i<n;i++)
		{
			if (d[i]!=b[i])
			{
				p=0;
				break;
			}
		}
		if (p==1)
		{
			;
			if (moves<ans)
				ans=moves;
		}
	}
	else
	{
		c[i]=1;
		solve(i+1);
		c[i]=0;
		solve(i+1);
	}
}
int main()
{
	freopen("1A.txt","w",stdout);
	int t;
	cin>>t;
	int h=1;
	while(t--)
	{
		cin>>n>>l;
		for (int i=0;i<n;i++)
			cin>>a[i];
		for (int x=0;x<n;x++)
			cin>>b[x];
		
		sort(b,b+n);
		solve(0);
		cout<<"Case #"<<h<<": ";
		if (ans==10000)
		{
			cout<<"NOT POSSIBLE\n";
		}
		else
		cout<<ans<<endl;
		ans=10000;
		h++;
	}
}
