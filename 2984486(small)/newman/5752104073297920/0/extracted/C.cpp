#include <stdio.h>

const int maxn = 1010;

int a[maxn+1];
int n;
int zai10;
double diff;
bool yes;

void init()
{
	int i;
	scanf("%d",&n);
	diff=0;
	zai10=0;
	for (i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		if (a[i]-i>0)
			diff+=a[i]-i;
		else diff+=i-a[i];
		if (a[i]>=i)
			++zai10;
	}
	//printf("%d\n",zai5);
}

void work()
{
	if (zai10>509)
		yes=false;
	else yes=true;
}

void output()
{
	if (yes)
		printf("GOOD\n");
	else printf("BAD\n");
}

int main()
{
	int i,T;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	scanf("%d",&T);
	int ans=0;
	for (i=1; i<=T; ++i)
	{
		printf("Case #%d: ",i);
		init();
		work();
		if (yes)
			++ans;
		output();
	}
	//printf("%d\n",ans);
	return 0;
}