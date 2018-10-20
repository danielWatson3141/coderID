#include<iostream>
#include<stdio.h>
using namespace std;
int flag[100000],a[2000][2000],r[2000],w[2000],tot,q[20000];
void getnum(int x)
{
	int i,t1;
	for(i=1;i<=20;i++)
		w[i]=0;
	t1=0;
	tot=0;
	while(x)
	{
		w[++t1]=x&1;
		if (w[t1]==1) tot++;
		x=x/2;
	}
}
bool _dfs(int index)
{
	int k,len,i;
	flag[index]=1;
	len=a[index][0];
	k=0;
	for(i=1;i<=len;i++)
	{
		if (w[a[index][i]]==0&&flag[a[index][i]]==0)
		{
			if (!_dfs(a[index][i])) return false;
			k++;
		}
	}
	if (k==0||k==2)  return true;
	return false;
}
bool check(int n)
{
	int i;
	for(i=1;i<=n;i++)
		if (w[i]==0&&flag[i]!=1)  return false;
	return true;
}
int dog(int n)
{
	int _min,i,j,k;
	_min=100000;
	for(i=0;i<=(1<<n)-1;i++)
	{
		getnum(i);
		if (i==68)
		{
			int kgt=0;
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				flag[k]=0;
			if (_dfs(j)) 
				if (check(n)&&tot<_min) 
					_min=tot;
		}
	}
	return _min;
}
void dfs(int index)
{
	int len,k,tot,i,pt;
	flag[index]=1;
	len=a[index][0];
	k=0;
	tot=0;
	q[index]=1;
	for(i=1;i<=len;i++)
	{
		if (flag[a[index][i]]==0) 
		{
			dfs(a[index][i]);
			k++;
			pt=a[index][i];
		//	f[index][k]=r[pt];
			tot+=r[pt];	
			q[index]+=q[pt];
		}
	}
	if (k==0){r[index]=0;}
	if (k==1){r[index]=q[index]-1;}
	if (k>=2)
	{
	/*	_min1=100000000;
		_min2=100000000;
		for(i=1;i<=k;i++)
			if (f[index][i]<_min1) {_min1=f[index][i];g=i;}
		for(i=1;i<=k;i++)
			if (g!=i&&f[index][i]<_min2) {_min2=f[index][i];}*/
		r[index]=tot+k-2;
	}

}
int main()
{

	int ii,tt,n,x,y,_min,i,j;
	freopen("B-small-attempt2.in","r",stdin);
	freopen("000.txt","w",stdout);
	scanf("%d",&tt);

	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d",&n);
	//	printf("%d\n",n);
		for(i=1;i<=n;i++)
			a[i][0]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
		//	printf("%d %d\n",x,y);
			a[x][0]++;
			a[x][a[x][0]]=y;
			a[y][0]++;
			a[y][a[y][0]]=x;
		}
		printf("Case #%d: %d\n",ii,dog(n));
		_min=100000000;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				flag[j]=0;
			dfs(i);
			if (r[i]<_min) _min=r[i];
		}
	//	printf("Case #%d: %d\n",ii,_min);
	}
	return 0;

}