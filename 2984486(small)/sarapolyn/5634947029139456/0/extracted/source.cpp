#include <bits/stdc++.h>
using namespace std;
int flip(int c[], int l, int a)
{
	int ret,i,n=1;
	ret=0;
	for(i=0;i<l;i++)
	{
		if((a%10==0 && c[i]==1)||(a%10==1 && c[i]==0))
		{
			ret+=n;
		}
		a/=10;
		n*=10;
	}
	return ret;
}
int main() {
	int t;
	cin>>t;
	int n,a[100],b[100],c[100],d[100],i,j,k,l,m,mini;
	for(i=1;i<=t;i++)
	{
		cin>>n>>l;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(j=0;j<n;j++)
		{
			cin>>b[j];
		}
		sort(b,b+n);
		mini=20;
		for(k=0;k<pow(2,l);k++)
		{
			int p=k;
			int count=0;
			for(m=0;m<l;m++)
			{
				c[m]=p%2;
				if(p%2==1)count++;
				p/=2;
			}
			for(m=0;m<n;m++)
			{
				int xyz;xyz=a[m];
				d[m]=flip(c, l, xyz);
			}
			sort(d,d+n);
			int flag=0;
			for(m=0;m<n;m++)
			{
				if(d[m]!=b[m])flag=1;
			}
			if(!flag)
			{
				mini=min(mini,count);
			}
		}

		if(mini==20)
		cout<<"Case #"<<i<<": NOT POSSIBLE"<<endl;

		else

		cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}
