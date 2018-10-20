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

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		int n;
		cin>>n;
		int ans=0;
		for (int i=0;i<n;i++)
		{	
			int j;
			cin>>j;
			ans+=abs(i-j);
		}
		cout<<"Case #"<<ii+1<<": ";
		if (ans<(n-1)*(n-1)/3) cout<<"BAD\n";else cout<<"GOOD\n";
	}
}