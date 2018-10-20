#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int i,j,k,l,n,t,c,count,m,a[1005],b[1005],d[1005]={0};
	cin>>t;
	for(m=1;m<=t;m++)
	{
		int flag=0;
		cout<<"Case #"<<m<<": ";
		cin>>n;c=0;
		for(i=0;i<n;i++)
			a[i]=i;
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++)
		{
			if(b[i]==i)
				c++;
		}
		if(c>n/2)
		{
			cout<<"BAD\n";
			continue;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(b[i]==a[j])
				{
					l=a[i];
					a[i]=a[j];
					a[j]=l;
					if(j<i)
					{
						flag==1;
					}
					if(flag==0)
					{
						k=(j-i+1)*n;
						k=k/(n-i);
						d[k]++;
					}
				}
			}
		}
		if(flag==1)
		{
			cout<<"BAD\n";
			continue;
		}
		for(i=0;i<n;i++)
			if(d[i]>=n/3)
			{
				cout<<"BAD\n";
				continue;
			}
		cout<<"GOOD\n";
	}
	
	return 0;
}