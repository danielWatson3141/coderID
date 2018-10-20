#include<iostream>
using namespace std;
int ar[1001][1001],top[1001]={0},mark[1001]={0};
void set_mark()
{
	for(int i=0;i<1001;i++)
		mark[i]=0;
}
void set()
{
	int i,j;
	for(i=0;i<1001;i++)
	{
		for(j=0;j<1001;j++)
			ar[i][j]=0;
		top[i]=mark[i]=0;
	}
}
int dfs(int node)
{
	// cout<<"called "<<node<<endl;
	mark[node]=1;
	bool f1=false,f2=false;
	int s1,s2,temp,i;
	if(top[node]<=1)
		return 1;
	for(i=0;i<top[node];i++)
	{
		if(mark[ar[node][i]]==0)
		{
			temp = dfs(ar[node][i]);
			// cout<<"node called return "<<node<<" "<<ar[node][i]<<" "<<temp<<endl;
			if(f1==false)
				{s1=temp;f1=true;}
			else if(f2==false)
				{s2=min(s1,temp);s1=max(s1,temp);f2=true;}
			else
			{
				if(temp>=s2&&temp<=s1)
					s2=temp;
				else if(temp>s1)
					{s2=s1;s1=temp;}
			}
		}
	}
	 // cout<<"node s1,s2 = "<<node<<" "<<s1<<" "<<s2<<endl;
	if(f1&&f2)
		return s1+s2+1;
	else return 1;
}
int main()
{
	int t,i,n,a,b,sum=0,j,temp;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		set();
		sum=0;
		cin>>n;
		for(j=0;j<n-1;j++)
			{cin>>a>>b;ar[a][top[a]]=b;top[a]++;ar[b][top[b]]=a;top[b]++;}
		for(j=1;j<=n;j++)
			{temp=max(sum,dfs(j));sum=max(temp,sum);set_mark();}
		cout<<"Case #"<<i<<": "<<n-sum<<endl;
	}
}