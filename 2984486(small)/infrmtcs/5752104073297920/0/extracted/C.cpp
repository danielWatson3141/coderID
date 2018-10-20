#include <bits/stdc++.h>
#define fi "C.INP"
#define fo "C.OUT"
#define nmax 1000+5
#define INF 1000000000
using namespace std;

//VARIABLES
int n,a[nmax],test;
bool ok;
//PROTOTYPES

void Process();

//MAIN
int main()
{
	int tc;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&tc);
       while (tc--)
	{
		Process();
		fprintf(stderr,"%d\n",test);
	}
       return 0;
}

//FUNCTIONS
void Process()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	if (n%2==0)
	{
		if (a[0]>=n/2) ok=true; else ok=false;
	} else
	{
		if (a[0]>n/2) ok=true; else
		if (a[0]<n/2) ok=false; else
		{
			if (a[1]>n/2) ok=true; else ok=false;
		}
	}
	if (ok) printf("Case #%d: GOOD\n",++test); else printf("Case #%d: BAD\n",++test);
}
