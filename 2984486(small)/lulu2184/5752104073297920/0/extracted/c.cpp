#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int T,n,a[1010],TT;
long double p1,p2,f[1010][1010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i]++;
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++)
		{
			cnt1+=(a[i]>i);
			cnt2+=(a[i]<i);
		}
		printf("Case #%d: ",++TT);
		//printf("%d %d\n",cnt1,cnt2);
		if (cnt1-cnt2>=30) printf("BAD\n");
		else printf("GOOD\n");
	}

	return 0;
}