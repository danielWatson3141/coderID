#include<iostream>
using namespace std;
int ar[1001][1001],top[1001]={0},chek[1001]={0};
void make_chek()
{
	for(int i=0;i<1001;i++)
		chek[i]=0;
}
void make()
{
	int i,j;
	for(i=0;i<1001;i++)
	{
		for(j=0;j<1001;j++)
			ar[i][j]=0;
		top[i]=chek[i]=0;
	}
}
int get_result(int node)
{
	chek[node]=1;
	bool flag1=false,flag2=false;
	int s1,s2,temp,i;
	if(top[node]<=1)
		return 1;
	for(i=0;i<top[node];i++)
	{
		if(chek[ar[node][i]]==0)
		{
			temp = get_result(ar[node][i]);
			if(flag1==false)
				{s1=temp;flag1=true;}
			else if(flag2==false)
				{s2=min(s1,temp);s1=max(s1,temp);flag2=true;}
			else
			{
				if(temp>=s2&&temp<=s1)
					s2=temp;
				else if(temp>s1)
					{s2=s1;s1=temp;}
			}
		}
	}
	if(flag1&&flag2)
		return s1+s2+1;
	else return 1;
}
int main()
{
	int t,i,n,a,b;
	int sum=0,j,temp;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		sum=0;
		cin>>n;
		make();
		for(j=0;j<n-1;j++)
			{cin>>a>>b;ar[a][top[a]]=b;top[a]++;ar[b][top[b]]=a;top[b]++;}
		j=1;
		while(j<=n)
			{
				temp=max(sum,get_result(j));
				sum=max(temp,sum);
				make_chek();
				j++;
			}
			sum=n-sum;
		cout<<"Case #"<<i<<": "<<sum<<endl;
	}
}