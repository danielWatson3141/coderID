#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[2000];
int i,o,p,j,k,l,n,m,t;
double tep1,tep2,lnn=2.6;
main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	l=0;
	scanf("%d",&t);
	while(t--)
	{
		p=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{scanf("%d",&o);
		if (o==i-1) ++p;
		}
		tep1=p;
		tep2/=(double)n/lnn;
		printf("Case #%d: ",++l);
		if (tep1>tep2) printf("BAD\n");
		else printf("GOOD\n");
	}
	return 0;
}
