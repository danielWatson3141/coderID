#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int min(int a,int b)
{if(a>b)return b;return a;}
int n,l,sum;
int main()
{
	freopen("test.txt","w",stdout);
	int t;cin>>t;
	int ii,i,j,k;
	for(ii=1;ii<=t;ii++)
	{
		char a[45][155];char b[45][155];
		char temp[45];
		int m=-1;
		cin>>n>>l;
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<n;i++)cin>>b[i];
		cout<<"Case #"<<ii<<": ";
		for(i=0;i<n;i++)
		{
			bool f=true;
			bool visited[45];sum=0;
			for(j=0;j<l;j++)visited[j]=0;
			for(j=0;j<l;j++)
			if(a[0][j]!=b[i][j])
			{visited[j]=1;sum++;}
			for(k=1;k<n;k++)
			{
				strcpy(temp,a[k]);
				//cout<<temp<<endl;
				for(j=0;j<l;j++)
				{//if(!visited[j])temp[k][j]=a[k][j];
				if(visited[j])
				{
					if(a[k][j]=='1')temp[j]='0';
					else temp[j]='1';
				}}
				bool ne;ne=false;
				//temp[i][l]='\0';
				//cout<<temp<<" "<<i<<endl;
				for(j=0;j<n;j++)if(strcmp(temp,b[j])==0)ne=true;
				if(!ne)
				{f=false;break;}
			}
			if(f)
			{
				if(m==-1)m=sum;
				else m=min(m,sum);
			}
		}
		//cout<<m<<endl;
		if(m==-1)cout<<"NOT POSSIBLE"<<endl;
		else cout<<m<<endl;
	}
}
