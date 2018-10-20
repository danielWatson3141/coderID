#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 999999

int e[1010][1010],d[1010][1010],flag[1010],dp1[1010],dp2[1010],n,da;
bool Comp(const int &a,const int &b)
{
   return a > b ;
}
void doit(int now)
{
	flag[now]=1;
	vector<int> tem;
	tem.clear();
	int num=0;
	for(int i=1;i<=d[now][0];i++)
	{
		if(flag[d[now][i]]==1)
			continue;
		doit(d[now][i]);
		num++;
		tem.push_back(d[now][i]);
	//	tem.push_back(doit(d[now][i]]));
	}
	if(tem.size()==0)
	{
		dp1[now]=1;
		dp2[now]=1;		
	}
	else if(tem.size()==1)
	{
		dp1[now]=1+dp1[tem[0]];
		dp2[now]=1;
	}
	else if(tem.size()>=2)
	{
		int tot=0;
		vector<int>tem2;
		tem2.clear();
		for(int j=0;j<tem.size();j++)
		{
			tot+=dp1[tem[j]];
			tem2.push_back(dp2[tem[j]]);
		}
		dp1[now]=tot+1;
		sort(tem2.begin(),tem2.end(),Comp);
		dp2[now]=1+tem2[0]+tem2[1];
	}
}

int i1,x,y,n1,r;

int main()
{
	cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n;
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		for(int i=1;i<=n-1;i++)
		{
			cin>>x>>y;
			e[x][y]=1;
			e[y][x]=1;
			d[x][0]++;
			d[x][d[x][0]]=y;
			d[y][++d[y][0]]=x;
		}
		da=0;
		for(r=1;r<=n;r++)
		{
			memset(flag,0,sizeof(flag));
			memset(dp1,0,sizeof(dp1));
			memset(dp2,0,sizeof(dp2));
			doit(r);
			if(dp2[r]>da)
				da=dp2[r];			
		}
		cout<<"Case #"<<i1<<": "<<n-da<<endl;
	}
	return 0;
}
