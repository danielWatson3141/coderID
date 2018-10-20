#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<time.h>
using namespace std;
int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	int T,f[2000],k[2000];
	srand((int)time(0));
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d",&f[i]);
		printf("Case #%d: ",TT);
		bool flag=rand()%2;

		if (flag) printf("GOOD\n");else printf("BAD\n");
	}
}
