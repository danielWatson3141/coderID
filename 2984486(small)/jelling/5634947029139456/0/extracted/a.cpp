//cj round1 A
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;
int chuli(int sum,int L)
{
	int res=0;
	while(sum)
	{
		if(sum%2)
			res++;
		sum=sum/2;
	}
	return res;
}
int main()
{
	ifstream cin("b.in");
	ofstream cout("A-small-attempt0.out");
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int N,L;
		cin>>N>>L;
		int a1[150]={0},a2[150]={0};
		string tem;
		for(int j=0;j<N;j++)
		{
			cin>>tem;
			for(int k=0;k<L;k++)
			{
				if(tem[k]=='1')
					a1[j]+=int(pow(2.0,L-k-1));
			}
		}
		for(int j=0;j<N;j++)
		{
			cin>>tem;
			for(int k=0;k<L;k++)
			{
				if(tem[k]=='1')
					a2[j]+=int(pow(2.0,L-k-1));
			}
		}
		sort(a1,a1+N);
		sort(a2,a2+N);
		bool flag=0;
		int sum=0;
		while(!flag&&sum<int(pow(2.0,L)))
		{
			int j=0;
			int temp[150];
			for(int k=0;k<N;k++)
			{
				temp[k]=a1[k]^sum;
			}
			sort(temp,temp+N);
			while(temp[j]==a2[j]&&j<N)
			{
				j++;
			}
			if(j==N)
			{
				flag = 1;
				break;
			}
			sum++;
		}
		if(flag)
		{
			int res=chuli(sum,L);
			cout<<"Case #"<<i+1<<": "<<res<<endl;
		}
		else 
			cout<<"Case #"<<i+1<<": "<<"NOT POSSIBLE"<<endl;
	}
	return 0;
}