#include <cstdio>
int i,o[2200],j,T,x,y;

int main()
{
	for (i=2; i<=2100; ++i)
	if (!o[i])
	for (j=i+i; j<=2100; j+=i) o[j]=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&x,&y);
		for (i=1; o[x+y+i]; ++i);
		printf("%d\n",i);
	}
	return 0;
}
