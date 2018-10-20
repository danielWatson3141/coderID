#include <cstdio>
bool solve()
{
	int n,q,p;
	int N;
	scanf("%d",&n);
	N=n;
	scanf("%d",&q);
	n--;
	while(n--)
		scanf("%d",&p);
	q++;
	return q>=N/2;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		printf("Case #%d: %s\n",i,solve() ? "BAD" : "GOOD");
}