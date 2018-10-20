#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define N 155
const int inf=0x7fffffff;
long long a[N],b[N];
bool used[N];
int n,l;

void init()
{
	int i,j,temp;
	scanf("%d%d\n",&n,&l);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	FOR(i,1,n)
	{
		FOR(j,0,l-1)
		{
			temp=getchar()-'0';
			if(temp)a[i]+=1LL<<(long long)j;
		}
		getchar();
	}
	FOR(i,1,n)
	{
		FOR(j,0,l-1)
		{
			temp=getchar()-'0';
			if(temp)b[i]+=1LL<<(long long)j;
		}
		getchar();
	}
}

int count(long long x)
{
	int res=0;
	while(x)
	{
		res++;
		x-=x&(-x);
	}
	return res;
}

void work()
{
	int i,j,k,flag,bj,ans=inf;
	long long mark;
	FOR(i,1,n)
	{
		memset(used,0,sizeof(used));
		used[i]=1;
		mark=a[1]^b[i];
		flag=1;
		FOR(j,2,n)
		{
			bj=1;
			FOR(k,1,n)
			if(!used[k])
			{
				if((a[j]^b[k])==mark)
				{
					used[k]=1;
					bj=0;
					break;
				}
			}
			if(bj==1)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			ans=min(ans,count(mark));
		}
	}
	if(ans!=inf)cout<<ans<<endl; else puts("NOT POSSIBLE");
}

int main()
{
	int i,T;
	scanf("%d\n",&T);
	FOR(i,1,T)
	{
		init();
		printf("Case #%d: ",i);
		work();
	}
}