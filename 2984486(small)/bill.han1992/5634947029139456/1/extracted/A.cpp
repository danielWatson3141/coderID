#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
string a[150],b[150];
int check()
{
	vector<string> c(a,a+n);
	sort(c.begin(),c.end());
	for (int i=0;i<n;i++) if (c[i]!=b[i]) return 0;
	return 1;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,k,l,i,j,x,y,ans;
	vector<int> v;
	cin>>t;
	for (k=1;k<=t;k++)
	{
		cin>>n>>l;
		for (i=0;i<n;i++) cin>>a[i];
		for (i=0;i<n;i++) cin>>b[i];
		sort(b,b+n);
		ans=l+1;
		for (i=0;i<n;i++)
		{
			for (j=0;j<l;j++) if (a[i][j]!=b[0][j]) v.push_back(j);
			for (x=0;x<n;x++)
			{
				for (y=0;y<v.size();y++)
					if (a[x][v[y]]=='0') a[x][v[y]]='1';
					else a[x][v[y]]='0';
			}
			if (check()) ans=v.size()<ans?v.size():ans;
			for (x=0;x<n;x++)
			{
				for (y=0;y<v.size();y++)
					if (a[x][v[y]]=='0') a[x][v[y]]='1';
					else a[x][v[y]]='0';
			}
			v.clear();
		}
		cout<<"Case #"<<k<<": ";
		if (ans>l) cout<<"NOT POSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}