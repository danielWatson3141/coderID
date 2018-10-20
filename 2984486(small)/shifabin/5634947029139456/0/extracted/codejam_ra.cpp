#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int tot,n,m;
string a[10000],b[10000],temp[10000];
int f[1000];
void getnum(int index)
{
	int i,t1;
	for(i=0;i<=50;i++)
		f[i]=0;
	t1=-1;
	tot=0;
	while(index)
	{
		f[++t1]=index&1;
		if (f[t1]==1) tot++;
		index=index/2;
	}
}
bool dog()
{
	int i,j;
	string s;
	for(i=1;i<=n;i++)
	{
		s=a[i];
		for(j=0;j<m;j++)
		   if (f[j]==1)
		   {
			   if (s[j]=='2') s[j]='1';
			   else
				   s[j]='2';
		   }
		temp[i]=s;
	}
	sort(temp+1,temp+1+n);
	for(i=1;i<=n;i++)
		if (temp[i]!=b[i])  return false;
	return true;

}
int main()
{
	int ii,tt,_min,i,j;
	string s;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("000.txt","w",stdout);
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
				if (s[j]=='0') s[j]='2';
			a[i]=s;
		}
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
				if (s[j]=='0') s[j]='2';
			b[i]=s;
		}
		sort(b+1,b+1+n);
		_min=100000;
		for(i=0;i<=(1<<m)-1;i++)
		{
			getnum(i);
			if (dog()) 
				if (tot<_min) _min=tot;

		}
		if (_min!=100000) printf("Case #%d: %d\n",ii,_min);
		else
			printf("Case #%d: NOT POSSIBLE\n",ii);
	}
	return 0;
}