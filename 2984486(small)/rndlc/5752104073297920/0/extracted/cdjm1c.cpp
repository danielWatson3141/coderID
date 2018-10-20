#include<iostream>
using namespace std;
int main()
{
	int t,n,i,j,k,data;
	int ar[1001],br[1001];
	cin>>t;
	bool flag;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
			{cin>>ar[i];br[i]=i;}
		for(j=0;j<n;j++)
		{
			flag=false;
			data=ar[j];
			for(k=j;k<n;k++)
				if(data==br[k])
					{flag=true;br[k]=br[j];br[j]=data;break;}
			if(flag==false)
				break;
		}
		if(flag==false)
			cout<<"Case #"<<i<<": BAD\n";
		else
			cout<<"Case #"<<i<<": GOOD\n";
	}
}