#include<cstdio>
#include<algorithm>
#define N 200
using namespace std;

long long A[N],B[N];
char str[10000];
int n,l;

long long trans(char *s)
{
	long long res=0;
	for (int i=0;i<l;i++)
	{
		res*=2;
		if (s[i]=='1')
			res++;
	}
	return res;
}

int find(long long x)
{
	for (int i=0;i<n;i++)
		if (x==B[i])
			return 1;
	return 0;
}
int check(long long key)
{
	for (int i=0;i<n;i++)
	{
		if (find(A[i]^key)==0)
			return 0;
	}
	return 1;
}
int main()
{
	int t,ys=0;

	freopen("A-small-attempt0.in","r",stdin);
	freopen("resA.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&l);
		for (int i=0;i<n;i++)
		{
			scanf("%s",str);
			A[i]=trans(str);
		}
		for (int i=0;i<n;i++)
		{
			scanf("%s",str);
			B[i]=trans(str);
		}

		int ans=-1;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				long long key=A[i]^B[j];
				if (check(key))
				{
					if (ans==-1) ans=__builtin_popcountll(key);
					else ans=min(ans,__builtin_popcountll(key));
				}
			}
		printf("Case #%d: ",++ys);
		if (ans==-1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n",ans);
	}

	return 0;

}
