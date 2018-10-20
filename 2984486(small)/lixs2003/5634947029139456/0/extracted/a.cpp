#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
using namespace std;

char str1[160][50];
char str2[160][50];
int a1[160],a2[160],er[12],flag[1200],tem[160],res,num,k1,k,i,j,n1,i1,n,l,x,u;

int main()
{
	er[0]=1;
	for(i=1;i<=10;i++)
	{
	
		er[i]=er[i-1]*2;
	}
	cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n>>l;
		memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++)	
		{
			cin>>str1[i];
			x=0;
			for(j=0;j<l;j++)
			{
				x=x*2+str1[i][j]-'0';
			}
			//	cout<<x<<endl;
			flag[x]=i;
			a1[i]=x;
		}
		for(i=1;i<=n;i++)	
		{
			cin>>str2[i];			
			x=0;
			for(j=0;j<l;j++)
			{
				x=x*2+str2[i][j]-'0';
			}
			a2[i]=x;
		}
		res=999999;
		for(k=0;k<er[l]-1;k++)
		{
			u=0;
			for(i=1;i<=n;i++)
			{
				tem[i]=(a2[i]^k);
			//	cout<<tem[i];
				if(flag[tem[i]]==0)
				{
					u=1;
					break;
				}
			}
			if(u==0)
			{
			//	cout<<"*****"<<k<<endl;
		//		for(i=1;i<=n;i++)
		//				{cout<<tem[i]<<endl;}
				num=0;
				k1=k;
				while(k1>0)
				{
					if(k1%2==1)
						num++;
					k1=k1/2;
				}
				if(num<res)
					res=num;
			}
		}
	/*	for(i=0;i<l;i++)
		{
			x1=0;
			for(j=1;j<=n;j++)
				x1=x1+str1[j][i];
			x2=0;
			for(j=1;j<=n;j++)
				x2=x2+str2[j][i];
		}*/
		cout<<"Case #"<<i1<<": ";
		if(res==999999)
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<res<<endl;
	} 
	return 0;
} 
