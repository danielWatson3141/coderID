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
string a[155];
string b[155];
string c[155];
int n,m;
int main()
{
	int t,T;
	int i,j,k;
	int themin;
	int count;
	string s;
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n>>m;
		themin=999;
		for(i=0;i<n;i++)
		{
			cin>>s;
			a[i]=s;
		}
		for(i=0;i<n;i++)
		{
			cin>>s;
			b[i]=s;
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
			c[i]=s;
		for(i=0;i<n;i++)
		{
			count=0;
			for(j=0;j<m;j++)
			{
				if(a[0][j]!=b[i][j])
				{
					count++;
					for(k=0;k<n;k++)
						c[k][j]='1'-b[k][j]+'0';
				}
				else
				{
					for(k=0;k<n;k++)
						c[k][j]=b[k][j];
				}
			}
			sort(c,c+n);
			for(j=0;j<n;j++)
			{
				if(a[j]!=c[j])
					break;
			}
			if(j==n)
				themin=min(themin,count);
		}
		if(themin==999)
			cout<<"Case #"<<t<<": NOT POSSIBLE"<<endl;
		else
			cout<<"Case #"<<t<<": "<<themin<<endl;
	}
    return 0;
}