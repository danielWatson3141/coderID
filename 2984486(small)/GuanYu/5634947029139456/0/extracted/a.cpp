#include <cstdio>
#include <algorithm>
#define MAXN 12
#define MAXL 12
using namespace std;

// Outlets
int ol[MAXN];

// Device
int dv[MAXN];

// Backtracking
int ans,n;
int lis[MAXN];
void backtrack(int now,int bit,int fp,int l)
{
	int i;

	// End
	if(now==l)
	{

		for(i=0;i<n;i++)
			lis[i]=ol[i]^bit;
		sort(lis,lis+n);

		for(i=0;i<n;i++)
			if(lis[i]!=dv[i]) break;
		if(i==n&&fp<ans) ans=fp;
		return;
	}

	// Flip
	backtrack(now+1,bit^(1<<now),fp+1,l);

	// Not flip
	backtrack(now+1,bit,fp,l);
}

// String
char str[MAXL];

// Main
int main(void)
{
	int tc,cs,l,i,j,ptr;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++)
		{
			ol[i]=0;
			ptr=1;
			scanf("%s",str);
			for(j=l-1;j>=0;j--,ptr<<=1)
				ol[i]+=(str[j]-'0')*ptr;
		}
		for(i=0;i<n;i++)
		{
			dv[i]=0;
			ptr=1;
			scanf("%s",str);
			for(j=l-1;j>=0;j--,ptr<<=1)
				dv[i]+=(str[j]-'0')*ptr;
		}
		sort(dv,dv+n);
		ans=(int)1e9;
		backtrack(0,0,0,l);
		printf("Case #%d: ",cs);
		if(ans==(int)1e9) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
	return 0;
}