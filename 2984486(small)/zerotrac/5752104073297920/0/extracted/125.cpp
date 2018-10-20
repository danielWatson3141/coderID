#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

int a[1010],ans[1010];
int T,n;

int main()
{
	freopen("125.in","r",stdin);
	freopen("125.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			a[j]++;
		}
		LL cost=0;
		for(int j=1;j<=n;j++)cost+=(LL)(j-a[j])*(j-a[j]);
		if(cost<=161000000LL)ans[i]=0;else ans[i]=1;
	}
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		if(ans[i]==0)printf("BAD\n");else printf("GOOD\n");
	}
	return 0;
}
