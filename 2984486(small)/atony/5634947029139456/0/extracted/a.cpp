#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 160;
const int MAXM = 2000001;
const int MAXK = 50;
const int INF = 10005;

long long n,l;
char s1[MAXN][MAXK];
char s2[MAXN][MAXK];
long long g[MAXN][MAXN];

long long find_bit(long long val)
{
	long long bit,k;
	bit=0;
	for(k=0;k<l;k++)
		if((val>>k)&1)
			bit++;
	return bit;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long T,cas,i,j,k,ans,find_val;
	scanf("%lld",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%lld%lld",&n,&l);
		for(i=0;i<n;i++)
			scanf("%s",s1[i]);
		for(j=0;j<n;j++)
			scanf("%s",s2[j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				g[i][j]=0;
				for(k=0;k<l;k++)
				{
					if(s1[i][k]!=s2[j][k])
					
						g[i][j]=(g[i][j]<<1)+1;
					else
						g[i][j]=(g[i][j]<<1);
				}
			}
		ans=INF;
		for(k=0;k<n;k++)
		{
			find_val=g[0][k];
			for(i=1;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(g[i][j]==find_val)
						break;
				}
				if(j==n)	break;
			}
			if(i==n)  ans=min(ans,find_bit(find_val));
		}
		if(ans==INF)
			printf("Case #%lld: NOT POSSIBLE\n",cas);
		else
			printf("Case #%lld: %lld\n",cas,ans);
	}
	return 0;
}