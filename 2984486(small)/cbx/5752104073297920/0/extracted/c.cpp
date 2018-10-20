#include<math.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int n=1000;
double p[n][n];
int a[n];
int main()
{
	ios::sync_with_stdio(false);
	freopen("C-table.out","r",stdin);
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	int ti;
	for (ti=1;ti<=t;ti++)
	{
		double ans=0;
		int nn;
		cin>>nn;
		for (i=0;i<n;i++)
		{
			cin>>a[i];
			double x=p[i][a[i]];
			ans+=log(x);
		}
		cout<<"Case #"<<ti<<": "<<(ans<0?"GOOD":"BAD")<<endl;
	}


	return 0;
}
