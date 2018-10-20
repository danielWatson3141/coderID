#include <cstdio>
#include <algorithm>
#define scanf(args...) scanf(args) ? : 0
const int INF=1e6;
const int MAX=1e3;
int a[MAX];
int b[MAX];
int c[MAX];
bool check(int n)
{
	for(int i=0;i<n;i++)
		if(b[i]!=c[i])
			return false;
	return true;
}
int get(int n)
{
	char s[MAX];
	scanf("%s",s);
	int w=0;
	int p=1;
	for(int i=n-1;i>=0;i--)
	{
		w+=(s[i]-'0')*p;
		p*=2;
	}
	return w;
}
int solve()
{
	int w=INF;
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++)
		a[i]=get(l);
	for(int i=0;i<n;i++)
		b[i]=get(l);
	std::sort(b,b+n);
	for(int mask=0;mask<=(1<<l);mask++)
	{
		for(int i=0;i<n;i++)
			c[i]=a[i]^mask;
		std::sort(c,c+n);
		if(check(n) && __builtin_popcount(mask) < w)
			w=__builtin_popcount(mask);
	}
	return w;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("Case #%d: ",i+1);
		int x=solve();
		if(x!=INF)
			printf("%d\n",x);
		else
			printf("NOT POSSIBLE\n");
	}
}