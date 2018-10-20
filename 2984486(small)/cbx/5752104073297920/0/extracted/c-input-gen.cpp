#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[1000];
void swap(int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
int main()
{
	freopen("c-large.in","w",stdout);
	ios::sync_with_stdio(false);
	int t=30;
	cout<<t<<endl;
	int n=1000;
	while (t--)
	{
		cout<<n<<endl;
		if (0)//GOOD
		{
			int k;
			for (k=0;k<n;k++)
			{
				a[k]=k;
			}
			for (k=0;k<n;k++)
			{
				int p=rand()%(n-k)+k;
				swap(k,p);
			}
		}
		else //BAD
		{
			int k;
			for (k=0;k<n;k++)
			{
				a[k]=k;
			}
			for (k=0;k<n;k++)
			{
				int p=rand()%n;
				swap(k,p);
			}
		}
		int i;
		for (i=0;i<n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
