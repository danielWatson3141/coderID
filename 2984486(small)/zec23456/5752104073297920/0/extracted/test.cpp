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
int a[1111];
double re[111];
int main()
{
	int t,T;
	int themin;
	int n,j,i,count;
	int flag=0;
	freopen("C-small-attempt2.in","rt",stdin);
	freopen("C.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		count=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
					count++;
			}
		}
		double x=n*(n-1)/2/2;
		double xx=1-(double)count/x;
		//cout<<xx<<endl;
		if(xx>0)
			flag++;
		re[t]=xx;
		if(xx<-0.0190551)
			cout<<"Case #"<<t<<": BAD"<<endl;
		else
			cout<<"Case #"<<t<<": GOOD"<<endl;
	}
	/*sort(re+1,re+T+1);
	cout<<flag<<"asdasds"<<endl;
	cout<<re[60]<<"www"<<endl;*/
    return 0;
}