#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

#define MAXN 1005

int ar[MAXN];
int lis,lds;
int t,n;
int li[MAXN],ld[MAXN];

void getLIS()
{
	lis = 1;
	memset(li,0,sizeof(li));
	li[0] = 1;
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<i;j++)
		{
			if (ar[j]<ar[i]) li[i] = max(li[i],li[j]+1);
			lis = max(lis,li[i]);
		}
	}
}

void getLDS()
{
	lds = 1;
	memset(ld,0,sizeof(ld));
	ld[0] = 1;
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<i;j++)
		{
			if (ar[j]>ar[i]) ld[i] = max(ld[i],ld[j]+1);
			lds = max(lds,ld[i]);
		}
	}
}

int main()
{
	OPENR("C-small-attempt1.in");
	OPENW("C-small-attempt1.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
		}
		
		getLIS();
		getLDS();
		
		if (lis>lds) printf("Case #%d: BAD\n",tc);
		else printf("Case #%d: GOOD\n",tc);
	}
	
 	return 0;
}



