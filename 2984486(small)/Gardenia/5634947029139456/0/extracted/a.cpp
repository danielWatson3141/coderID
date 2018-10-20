#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool com(int a[],int b[],int n)
{
	sort(a,a+n);
	sort(b,b+n);
	for (int i=0;i<n;i++)
		if (a[i]!=b[i])
			return false;
	return true;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	//cout<<t<<"\n";
	for (int tt=1;tt<=t;tt++)
	{
		int n,l;

		cin>>n>>l;
		int a[n],b[n];
		char x; 
		int m = 1;
		for (int i=0;i<l-1;i++) m *= 2;
		//cout<<m<<"\n";
		for (int i=0;i<n;i++)
		{
			int mm = m;
			a[i] = 0;
			for (int j=0;j<l;j++)
			{
				cin>>x;
				if (x=='1')
				{
					a[i] += mm;
				}
				mm /= 2;
			}

		}

		for (int i=0;i<n;i++)
		{
			int mm = m;
			b[i] = 0;
			for (int j=0;j<l;j++)
			{
				cin>>x;
				if (x=='1')
				{
					b[i] += mm;
				}
				mm /= 2;
			}

		}
/*
		for (int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		for (int i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		*/
		int ll = 0,mm = m;
		for (int i=0;i<l;i++)
		{
			ll += mm;
			mm /=2;
		}
		int ans = l;
		bool flag = true;

		for (int i=0;i<=ll;i++)
		{
			int c[n];

			for (int j=0;j<n;j++)
			{
				c[j] = a[j]^i;
				//cout<<c[j]<<" ";
			}
				

			if (com(c,b,n))
			{	
				flag = false;
				int mm=m,now = 0;
				int x = i;
			//	cout<<"x="<<x<<"\n";
				for (int ii=0;ii<l-1;ii++)
				{
					if (x / mm == 1)
					{
						now+=1;
						x = x-mm;
					}
						
					mm /=2;
				}
				if (x==1) now+=1;
				if (now<ans) ans  = now;
			}
		}
		cout<<"Case #"<<tt<<": ";
		if (flag==false)
			cout<<ans<<"\n";
		else
			cout<<"NOT POSSIBLE"<<"\n";
			

	}
}