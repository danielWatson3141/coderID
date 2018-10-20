#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[1005][100],b[1005][100];
long long c[200][200],base[100],rr[105],cc[105];
int i,o,p,j,k,l,n,m,t,cl,ro,tem;
long long ans,mi;
long long cmp(long long x,long long y)
{
	long long xx,yy,tx,ty;
	if (x==-1) return y;
	xx=yy=0;
	tx=x;ty=y;
	while (tx)
	{
		if (tx%2) ++xx;
		tx/=2;
	}
	while (ty)
	{
		if (ty%2) ++yy;
		ty/=2;
	}
	if (xx>yy) return y;
	else return x;
}
main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	l=0;
	base[1]=1;
	for (i=2;i<=40;i++)
	base[i]=2*base[i-1];
	scanf("%d",&t);
	while(t--)
	{
	mi=-1;
	memset(c,0,sizeof(c));
	scanf("%d%d",&n,&m);
	
	scanf("%c",&o);
	for (i=1;i<=n;i++)
	{
	for	(j=1;j<=m;j++)
		scanf("%c",&a[i][j]);
	scanf("%c",&o);
	}
	
	for (i=1;i<=n;i++)
	{
	for	(j=1;j<=m;j++)
		scanf("%c",&b[i][j]);
	scanf("%c",&o);
	}
	
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		 {
			for (k=1;k<=m;k++)
			if (a[i][k]!=b[j][k]) c[i][j]+=base[m-k+1];
		}
	for (k=1;k<=n;k++)
		{cl=ro=0;
		memset(rr,0,sizeof(rr));
		memset(cc,0,sizeof(cc));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			if (c[i][j]==c[k][1]) {rr[i]=1;cc[j]=1;}
		for (i=1;i<=n;i++)
			cl+=rr[i];
		for (i=1;i<=n;i++)
			ro+=cc[i];
		if (ro==n&&cl==n) 
			mi=cmp(mi,c[k][1]);
		}

	printf("Case #%d: ",++p);
	if (mi==-1)
	printf("NOT POSSIBLE\n");
	else {
		tem=0;
		while (mi)
		{
			if (mi%2) ++tem;
			mi/=2;
		}
	printf("%d\n",tem);	
	}
	}
	return 0;
}
