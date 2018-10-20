#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,L,TT,ans;
char str[50];
long long change,a[210],b[210],c[210];

long long trans(char str[])
{
	long long ret=0;
	for (int i=0;i<L;i++) 
		ret=ret*2+str[i]-'0';
	return ret;
}

int count(long long x)
{
	int ret=0;
	while (x) 
		ret+=x%2,x/=2;
	return ret;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&L);
		for (int i=1;i<=n;i++) 
		{
			scanf("%s",str);
			a[i]=trans(str);
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%s",str);
			b[i]=trans(str);
		}
		sort(&b[1],&b[n+1]);
		ans=(int)1e9;
		for (int i=1;i<=n;i++)
		{
			change=a[1]^b[i];
			for (int j=1;j<=n;j++)
			{
				c[j]=a[j]^change;
			}
			sort(&c[1],&c[n+1]);
			bool flag=true;
			for (int j=1;j<=n;j++)
			{
				if (b[j]!=c[j]) { flag=false;break; } 
			}
			if (flag) ans=min(ans,count(change));
		}
		printf("Case #%d: ",++TT);
		if (ans>L) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}

	return 0;
}